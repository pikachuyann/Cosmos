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
import numpy as np

exitFlag = 1
stDataColl = 0
collectedSamples = []
useVM = 0
logTime = 2 # in Seconds

def SaveToFile(handle, dta):
	if dta==0:
		handle.write(str(0)+" "+str(0)+"\n")
	elif dta==1:
		handle.write(str(1)+" "+str(0)+"\n")
	elif dta==2:
		handle.write(str(0)+" "+str(1)+"\n")
	elif dta==3:
		handle.write(str(1)+" "+str(1)+"\n")

def GetEnergyReadings(pmData, monitorSamplingFreq, tranListTimes):
	sumCurrent = 0
	sampleCnt = 1
	prev = pmData[0][1]
	
def GetRisingEdge(pmData):
	cnt = 0
	prev = pmData[0][1]
	for it in range(1,len(pmData)):

		if prev==0 and 	pmData[it][1]==1:
			cnt = cnt + 1
		prev = pmData[it][1]	
	return cnt

def ProcessPowerMonitorData(pmData, monitorSampligFreq):
	currentTran = []

	#firstPosM2 = 0
	#firstPosM1 = 0
	filedta = open('markers.txt', 'w+')
	sumCurrent = 0
	sampleCnt = 1
	prev = pmData[0][1]
	state = 0
	prev_time = 0.0

	SaveToFile(filedta, prev)

	for it in range(1,len(pmData)):
		sampleCnt = sampleCnt + 1

		SaveToFile(filedta, pmData[it][1])

		#print str(state)+":"+str(sampleCnt/monitorSampligFreq)

		if state==0:
			if pmData[it][1]==2 and prev==2:
				state = 0
			elif pmData[it][1]==0 and prev==2:
				state = 1
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==1 and prev==2:	
				state = 2
				sumCurrent = sumCurrent + pmData[it][0]

		if state==1:
			if pmData[it][1]==0 and prev==0:
				state = 1
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==1 and prev==0:
				state = 2
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==2 and prev==0:
				state = 1
			elif pmData[it][1]==3 and prev==0:
				state = 6
				sumCurrent = sumCurrent + pmData[it][0]

		if state==2:
			if pmData[it][1]==0 and prev==1:
				state = 3
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==1 and prev==1:
				state = 2
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==2 and prev==1:
				state = 5
			elif pmData[it][1]==3 and prev==1:
				state = 6
				sumCurrent = sumCurrent + pmData[it][0]

		if state==3:
			if pmData[it][1]==0 and prev==0:
				state = 3
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==1 and prev==0:
				state = 3
				stime = sampleCnt/monitorSampligFreq

				if stime-prev_time>5.0:
					currentTran.append((sumCurrent,stime))

				prev_time = stime	
				#print str(stime)+"  "+str(sumCurrent)
				sumCurrent = pmData[it][0]
			elif pmData[it][1]==2 and prev==0:
				state = 5
			elif pmData[it][1]==3 and prev==0:
				state = 4
				sumCurrent = sumCurrent + pmData[it][0]

		if state==4:
			if (pmData[it][1]==0 and prev==3) or (pmData[it][1]==0 and prev==2):
				state = 1
				stime = sampleCnt/monitorSampligFreq

				if stime-prev_time>5.0:
					currentTran.append((sumCurrent,stime))

				prev_time = stime	
				#print str(stime)+"  "+str(sumCurrent)
				sumCurrent = pmData[it][0]

			#elif pmData[it][1]==2 and prev==3:
			#	state = 5
			elif (pmData[it][1]==2 and prev==3) or (pmData[it][1]==2 and prev==2):
				state = 4
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==3 and prev==3:
				state = 4
				sumCurrent = sumCurrent + pmData[it][0]

		if state==5:
			state = 5

		if state==6:
			if (pmData[it][1]==0 and prev==3) or (pmData[it][1]==0 and prev==2):
				state = 1
				sumCurrent = sumCurrent + pmData[it][0]
			elif (pmData[it][1]==1 and prev==3):
				state = 2
				sumCurrent = sumCurrent + pmData[it][0]
			elif pmData[it][1]==2 and prev==3:
				state = 6
			elif (pmData[it][1]==3 and prev==3) or (pmData[it][1]==2 and prev==2):
				state = 6
				sumCurrent = sumCurrent + pmData[it][0]

		prev = pmData[it][1]

	filedta.close()

	return currentTran

def SaveDistribution(handle, dData):
		dIdCurr = {}
		for key, val in dData:
			dIdCurr.setdefault(key, []).append(val)

		for key in 	dIdCurr:
			handle.write("T"+str(key)+"_min"+" = "+str(min(dIdCurr[key]))+"\n")
			handle.write("T"+str(key)+"_max"+" = "+str(max(dIdCurr[key]))+"\n")
			handle.write("T"+str(key)+"_mean"+" = "+str(np.mean(dIdCurr[key]))+"\n")
			handle.write("T"+str(key)+"_var"+" = "+str(np.var(dIdCurr[key]))+"\n")
			handle.write("T"+str(key)+"_list"+" = "+str(dIdCurr[key])+"\n")

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

if useVM==0:
	mon = monsoon.Monsoon("/dev/tty.usbmodemfd141")

	mon.SetVoltage(3.7)
	mon.SetUsbPassthrough(0)

	monItems = mon.GetStatus()
	items = sorted(monItems.items())
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

idCurr = []

if useVM==0:
	print "Preparing the PowerMonitor device..."
	time.sleep(4);

	for iters in range(0, 1):

		# Generate random parameter
		headerID = 0xF4
		parID = 1
		parValue = random.randint(1, 2000)
		#parValue = 809 		# Very slow Sa-node rate
		parValue = 30000
		#parValue = 177

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

		time.sleep(logTime);

		# Stop iteration
		s.sendall('\xF1')
		time.sleep(1);
		stDataColl = 0

		print "Stopped collecting data"

		currentTran = ProcessPowerMonitorData(collectedSamples, monItems['sampleRate'])
		#idx = -1

		#for idx in range(len(currentTran)-1,-1,-1):
		#	if currentTran[idx][1]<logTime*1000:
		#		break

		#if idx==-1:
		#	print "No energy samples"
		#	break

		#currentTran = currentTran[:idx+1]
		#print "Number of valid energy samples: "+str(len(currentTran))

		#print "\n".join(["%s: %s" % item for item in currentTran])
		#nrising = GetRisingEdge(collectedSamples)
		#print "Numbert of rising edges: "+str(nrising)

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

		nTranCnt = 	bufSize[0]/8
		print "Number of transitions received: "+str(nTranCnt)

		#if bufSize[0]!=len(currentTran):
		#	print "Diffent number of samples(client, power monitor)"
		#	break

		#print binascii.hexlify(bufIDs)
		
		tTimeList = []
		for idx in range(0,nTranCnt):
			tID = bufIDs[idx*8]
			tTime = struct.unpack("I",bufIDs[idx*8+1:idx*8+1+4])
			tTimeList.append(tTime[0])
			print str(tTime[0])+" "+str(bufIDs[idx*8])

		# Save energy readings to list	
		#for idx in range(bufSize[0]):
		#	idCurr.append([bufIDs[idx],currentTran[idx][0]])

		collectedSamples = []

	s.sendall('\xF2')
	exitFlag = 0

	# Save energy readings
	fileconst = open('const.m', 'w+')
	SaveDistribution(fileconst, idCurr)
	fileconst.close()

else:
	key = ''

	# Generate random parameter
	headerID = 0xF4
	parID = 1
	#parValue = random.randint(1, 2000)
	parValue = 30000

	print "Sending parameter ID: "+str(parID)+" value: "+str(parValue)

	parStr = struct.pack('BBI',headerID, parID, parValue)

	# Send parameter to Client
	s.sendall(parStr)

	buftmp = bytearray(1)
	buflen = s.recv_into(buftmp,1)

	if buftmp[0]!=0xF6:
		print "Wrong return value"
		s.close()
		exit()

	while key!='a':
		print "Press a key: "
		key = sys.stdin.read(1)

		if key=='w':
			s.sendall('\xF0')
			stDataColl = 1

		elif key=='s':
			s.sendall('\xF1')
			time.sleep(1);
			stDataColl = 0


			print "Stopped collecting data"

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

			print binascii.hexlify(bufIDs)

			collectedSamples = []

		elif key=='a':
			s.sendall('\xF2')

s.close()
