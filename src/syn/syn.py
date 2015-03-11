import monsoon

import sys
import threading
import time
import socket
import sys
import tty, termios
import struct
import binascii
import random
import ctypes

exitFlag = 1
stDataColl = 0
collectedSamples = []
useVM = 0

def ProcessPowerMonitorData(pmData):
	currentTran = []

	firstPosM2 = 0
	firstPosM1 = 0
	sumCurrent = 0

	for it in range(len(pmData)):
		if pmData[it][1]!=2 and firstPosM2 == 0:
			firstPosM2 = 1
		elif pmData[it][1]==2 and firstPosM2 == 1:
			break
		elif pmData[it][1]!=2 and firstPosM2 == 1:
			if pmData[it][1] == 1:
				firstPosM1 = 1
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1] == 0 and firstPosM1 == 0:
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1] == 0 and firstPosM1 == 1:
				firstPosM1 = 0
				currentTran.append(sumCurrent)
				print sumCurrent
				sumCurrent = pmData[it][0]


	return currentTran

class PowerMonitorThread (threading.Thread):
	def __init__(self, monitor):
		threading.Thread.__init__(self)
		self.monitor = monitor
	def run(self):
		print "Starting PowerMonitor Thread\n"
		self.monitor.StartDataCollection()

		while exitFlag:
			samples = self.monitor.CollectData()
			if stDataColl:
				collectedSamples.extend(samples)

				#print "\n".join(map(str, samples))

		self.monitor.StopDataCollection()

		print "Ending PowerMonitor Thread\n"

mon = monsoon.Monsoon("/dev/tty.usbmodemfd141")

mon.SetVoltage(3.7)
mon.SetUsbPassthrough(0)

items = sorted(mon.GetStatus().items())
print "\n".join(["%s: %s" % item for item in items])
mon.StopDataCollection()

# Create new threads
threadMonitor = PowerMonitorThread(mon)

# Start new Threads
threadMonitor.start()

HOST = 'localhost'			# The remote host
PORT = 27778				# The same port as used by the server
s = None
for res in socket.getaddrinfo(HOST, PORT, socket.AF_UNSPEC, socket.SOCK_STREAM):
	af, socktype, proto, canonname, sa = res
	try:
		s = socket.socket(af, socktype, proto)
	except socket.error as msg:
		s = None
		continue
	try:
		s.connect(sa)
	except socket.error as msg:
		s.close()
		s = None
		continue
	break
if s is None:
	print 'could not open socket'
	sys.exit(1)

#s.setblocking(0)

if useVM==0:
	print "Preparing the PowerMonitor device..."
	time.sleep(4);

	for iters in range(0, 5):

		# Generate random parameter
		headerID = 0xF4
		parID = 1
		parValue = random.randint(1, 2000)

		print "Sending parameter ID: "+str(parID)+" value: "+str(parValue)

		parStr = struct.pack('BBI',headerID, parID, parValue)

		# Send parameter to Client
		s.sendall(parStr)

		buftmp = bytearray(1)
		buflen = s.recv_into(buftmp,1)

		if buftmp[0]!=0xF6:
			print "Wrong return value"
			break

		print "Start iteration: "+str(iters)

		# Start iteration
		s.sendall('\xF0')
		stDataColl = 1

		time.sleep(60);

		# Stop iteration
		s.sendall('\xF1')
		time.sleep(1);
		stDataColl = 0

		print "Stopped collecting data"
		currentTran = ProcessPowerMonitorData(collectedSamples)

		# Send get list of IDs
		s.sendall('\xF3')

		bufSize = bytearray(4)
		buflen = s.recv_into(bufSize, 4)

		if buflen!=4:
			print "Wrong packet length"
			break

		bufSize = struct.unpack("I",bufSize)

		print "Packet size: "+str(bufSize[0])

		bufIDs = bytearray()
		buftmp = bytearray(2048)
		bytes_recd = 0

		while bytes_recd < bufSize[0]:
			chunkLen = s.recv_into(buftmp,2048)
			bufIDs[bytes_recd:] = buftmp[:chunkLen]
			bytes_recd = bytes_recd + chunkLen

		if 	bytes_recd != bufSize[0]:
			print "Wrong data"
			break

		#print binascii.hexlify(bufIDs)

		collectedSamples = []

	s.sendall('\xF2')
	exitFlag = 0

else:
	key = ''
	while key!='a':
		print "Press a key: "
		key = sys.stdin.read(1)

		if key=='w':
			s.sendall('\xF0')
		elif key=='s':
			s.sendall('\xF1')
		elif key=='a':
			s.sendall('\xF2')

s.close()
