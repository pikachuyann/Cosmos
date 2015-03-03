import monsoon

import sys
import threading
import time
import socket
import sys
import tty, termios


exitFlag = 0

def getchar():
	#Returns a single character from standard input
	fd = sys.stdin.fileno()
	old_settings = termios.tcgetattr(fd)
	try:
		tty.setraw(sys.stdin.fileno())
		ch = sys.stdin.read(1)
	finally:
		termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
	return ch

class PowerMonitorThread (threading.Thread):
    def __init__(self, monitor):
        threading.Thread.__init__(self)
        self.monitor = monitor
    def run(self):
        print "Starting PowerMonitor Thread\n"
        self.monitor.StartDataCollection()

        collected = []
        while len(collected)<10:
			samples = self.monitor.CollectData()
			collected.extend(samples)

        self.monitor.StopDataCollection()

        print "\n".join(map(str, collected))
        print "Ending PowerMonitor Thread\n"

#mon = monsoon.Monsoon("/dev/tty.usbmodemfd141")
#mon.SetVoltage(3.7)
#mon.SetUsbPassthrough(0)
#items = sorted(mon.GetStatus().items())
#print "\n".join(["%s: %s" % item for item in items])
#mon.StopDataCollection()
## Create new threads
#threadMonitor = PowerMonitorThread(mon)
## Start new Threads
#threadMonitor.start()

HOST = 'localhost'    		# The remote host
PORT = 27778              # The same port as used by the server
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

time.sleep(10)
s.sendall('\xF1')

while True:
	print 'Simulating...'
	time.sleep(60)
#    char = getchar()
#    if char=='a':
#    	s.sendall('\xF1')

#s.sendall('q')
#data = s.recv(1024)
s.close()
