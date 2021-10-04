#! usr/bin/python3


# Aurthor :- Leyuskc
# Date :- 2021-4-October
# Realese Version :- 1.0.1
# Is open source :- True
# Can I distribute :- Yes
# Fork me

# And yes you can use urllib or urllib3 but I like requests as it is a bit shorter and other can easy interpreate
# from urllib3 import request

import requests

# this is just a normal headers used to make the requests as the server checks the user agent
# You may be asking just the UA would have worked
# Yes! it works but having other headers looks abit formal and code length get longer
headers = {
    "Accept": "application/json, text/plain, */*",
    "Accept-Encoding": "gzip, deflate, br",
    "Accept-Language": "en-US,en;q=0.9",
    "Cache-Control": "no-cache",
    "Connection": "keep-alive",
    "DNT": "1",
    "Host": "tms17.nepsetms.com.np",
    "Pragma": "no-cache",
    "Referer": "https",
    "Sec-Fetch-Dest": "empty",
    "Sec-Fetch-Mode": "cors",
    "Sec-Fetch-Site": "same-origin",
    "Sec-GPC": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0;\
         Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko)\
         Chrome/90.0.4430.85 Safari/537.36",
}
# You can use any urls but for me it works best and it doesn't have much security for crawler
# and doesn't requires cookies which 1 forehand requests is avoided
# main dictionary
total = {}
# pseudo dictonary for storing values for short term
value = []
for i in range(0, 7):
    # grabbing provience wise District names
    url1 = f"https://tms17.nepsetms.com.np/tmsapi/clientApi/nepal-location/district-by-province/{i+1}"
    res = requests.get(url1, headers=headers)  # making requests for a above url;
    for k, j in enumerate(res.json()):
        # grabbing districts wise munipalicity name
        url2 = f'https://tms17.nepsetms.com.np/tmsapi/clientApi/nepal-location/municipality-by-district/{j["id"]}'
        res2 = requests.get(url2, headers=headers)  # making requests for above url
        # storing munipalicity name with district in pseudo variable
        value.append({res.json()[k - 1]["districtName"]: res2.json()})
    # storing provience wise district and district wise munipalcity for final
    total[f"Provienc{i+1}"] = value
    # emptying the pseudo variable for later use
    value = []

# please do fork my repo and leave me a star and a folllow
# https://github.com/leyuskckiran1510/pythoncodes
