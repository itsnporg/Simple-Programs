# a simple program which takes link from user and generate QR Code
import pyqrcode 
from pyqrcode import QRCode 
  
# String which represent the QR code 
s = input("Enter link: ")
  
# Generate QR code 
url = pyqrcode.create(s) 
  
# Create and save the png file naming "myqr.png" 
url.svg("myqr.svg", scale = 8) 
print("Your QR code have been saved as myqr.svg")
