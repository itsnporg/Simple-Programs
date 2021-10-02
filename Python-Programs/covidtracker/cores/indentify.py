'''To identify the geo and stats'''
import requests
import urllib,urllib.error,urllib.request,urllib.parse
import os,time,sys
import json

base_url="https://freegeoip.app/json/"

class Identify:
        # for checking geo and ip
        def raw_data(self):
            res_1=urllib.request.urlopen(base_url).read().decode()
            res_1=json.loads(res_1)
            return res_1
         
         # Calling Api for fetching stat data 
        def covid_stats(self):
           data=self.raw_data()
           country=data["country_name"]
           covid_api_url="https://corona.lmao.ninja/v2/countries/{}?yesterday&strict&query".format(country)
           res_stats=requests.get(covid_api_url).content
           source_dict=json.loads(res_stats)
           cases=(source_dict["cases"])
           today_cases=source_dict["todayCases"]
           deaths,today_deaths,recovered,today_recovered,active,tests=source_dict["deaths"],source_dict['todayDeaths'],source_dict["recovered"],source_dict["todayRecovered"],source_dict["active"],source_dict["tests"]
           yield cases,today_cases,deaths,today_deaths,recovered,today_recovered,active,tests

           


