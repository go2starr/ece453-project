#!/usr/bin/env python
import socket
import sys
from struct import *

import time

# scale - scale a value from one range to another
def scale(val, srange, erange):
    return val * erange / srange

# Joystick
# __u32(I), __s16(h), __u8(B), __u8(B)
jsfmt = 'IhBB'
jssize = 8

# PS3
YAW = 2
PITCH = 3
THROTTLE = 13

yaw = 0
pitch = 0
throttle = 0
cal = 63

# WIFI Module
TCP_IP = '10.42.43.2'
TCP_PORT = 2000
BUFFER_SIZE = 32*8

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))

# Read a ps3 packet
fd = open('/dev/input/js0', 'r')

while 1:
    fd.seek(0, 2)
    ps3pack = fd.read(jssize)
    ps3upack = unpack(jsfmt, ps3pack)

    button = int(ps3upack[3])
    val  =   int(ps3upack[1])

    if button == YAW:
        yaw = scale(val, 1<<16, 127) + 127/2
    elif button == PITCH:
        pitch = scale(val, 1<<16, 127) + 127/2
    elif button == THROTTLE:
        throttle = scale(val, 1<<16, 127) + 127/2

    print (yaw, pitch, throttle)
    
    packet = [0,0,0,0]
    packet[0] = yaw + cal/4
    packet[1] = pitch
    packet[2] = throttle
    packet[3] = cal

    print packet

    msg = "^"
    for i in range(4):
        for j in range(8):
            msg += str((packet[i] >> (8-j)) & 1)
    print msg

    # Send the packet
    s.send(msg)
    sys.stdout.flush()
    print "Recvd: ", s.recv(BUFFER_SIZE)

s.close()
