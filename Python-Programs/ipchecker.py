import re
import urllib.request

url = "http://checkip.dyndns.org"
print("\nWe will try to open this url, to get the IP Address: ", url)
request = urllib.request.urlopen(url).read()

# To check the raw request with the ip address
print("\nThe raw request with the external IP Address is: \n\n", request)

theIP = str(request)
theIP = re.findall(r"\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b", theIP)
print("\nYour external IP Address is: ", theIP)
