#!/usr/bin/env python

import socket
import sys


TCP_IP = '10.42.43.2'
TCP_PORT = 2000
BUFFER_SIZE = 32

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

while 1:
    packet = sys.stdin.readline()

    s.send(packet)
    print "Sent: ", packet
    sys.stdout.flush()

    print "Recvd: ", s.recv(BUFFER_SIZE)
s.close()

print "received data:", data
