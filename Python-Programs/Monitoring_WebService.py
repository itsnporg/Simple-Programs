import socket
import time

HOST= "10.30.3.254" #add IP
PORT= "80" #define PORT

def isOpen(ip,port):
   s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   
   try:
      s.settimeout(1)
      s.connect((ip, int(port)))
      s.shutdown(2)
      return True
   except:
        return False
print("Monitoring is ON!")

while (True):
    
    if isOpen(ip=HOST,port=PORT):
        print("Site is UP" + " "  + time.asctime() + "\n---------------")
        with open("Output.txt", "a") as text_file:
           print(f"Site is UP" + " "  + time.asctime() +"\n---------------", file=text_file)
        time.sleep(5)
    else:
        print("Site is DOWN" + " "  + time.asctime() + "\n---------------")
        with open("Output.txt", "a") as text_file:
           print(f"Site is DOWN" + " "  + time.asctime() + "\n---------------", file=text_file)
        time.sleep(5)
