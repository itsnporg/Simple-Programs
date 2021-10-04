#!/bin/python3

import argparse
import re
import socket
import time

import header

# Arguement Parsing for CLI
parser = argparse.ArgumentParser(description="A Simple Network port scanner.")
parser.add_argument("host", help="Ip address of host to scan.")
parser.add_argument(
    "-p",
    dest="port_range",
    default="1-1024",
    help="Port range to scan(Default is 1-1024)",
)
args = parser.parse_args()

target = args.host  # Target IP to scan

# Define Port Range
port_range = args.port_range.split(
    "-"
)  # Split the input port range into starting and ending port
port_start = int(port_range[0])
port_end = int(port_range[1])

target_name = socket.getfqdn(target)  # Set Target IP Variable


# Host Validator
try:
    target_ip = socket.gethostbyname(target)  # Set Target Name Variable
    print("Scanning", target_ip, "from port ", port_start, " to ", port_end, ".")
    print("\n")

except socket.gaierror:
    print("Invalid host to scan. Please verify that the host you are scanning exists.")
    quit()


# Host Identifier - used to validate both ip and domain name input
ip_regex = "^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$"
hostmatch = re.match(ip_regex, target)
try:
    if hostmatch == True:
        target_ip = socket.getfqdn(target)
        print(target_ip)
        print("ip address")
    else:
        target_ip = socket.gethostbyname(target)
except socket.gaierror:
    print("Hostname couldnot be resolved.")

# Port Scanner with socket
try:
    for port in range(port_start, port_end + 1):
        print("Scanning", target_ip, "at port", port)
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        socket.setdefaulttimeout(1)
        result = s.connect_ex((target, port))
        if result == 0:
            print("Port {} is open".format(port))
        else:
            print("Port {} is close".format(port))
        s.close()

except KeyboardInterrupt:
    print("exiting the scanner")
    exit()

except s.error:
    print("Connection error. Please check your connection and try again")
    exit()
