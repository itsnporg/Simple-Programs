import geocoder

ip = input("Enter ip")
g = geocoder.ip(ip)  # you might also try - 147.229.2.90 - this ip address

addr = (
    g.latlng
)  # this gives latitude and longitude which you can copy and paste on google earth

print(addr)
