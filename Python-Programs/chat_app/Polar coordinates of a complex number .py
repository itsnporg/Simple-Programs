#!/usr/bin/env python
# coding: utf-8

# In[1]:


import cmath as c                     #Importing Cmath module as C
n=input("Enter the complex number : ")#Taking Input of complex number 
num=complex(n)                        #Applying complex function for converting string in to complex number
r=abs(num)                            #Using ABS function for calculating Magnitude of a complex number
e=c.phase(num)                        #Using Phase function for calculating Phase angle of the complex number
print("Mangnitude is : "r)            #Printing Magnitude of complex number
print("Phase Angle is : "e)           #Printing Phase Angle of complex number

