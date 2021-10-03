import math
import sys


def cont():
  print("Do you want to continue ")
  print("Press Y/N to continue and exit respectively")
  inputchar=input()
  if(inputchar=="Y" or inputchar=="y"):
       switch()
  elif(inputchar=="N" or inputchar=="n"):
       sys.exit()
       

def switch():

    print("-"*40)
    print("1) Check Class of IPV4 Address")
    print("2) Exit")
    print("-"*40)
    option = int(input("your option : "))
    if  option == 1:
        data = input("Enter the ip address to check its class:")
        data = input("Enter the ip address find subnets")

        octet=data.split(".")
        (first_byte,second_byte,third_byte,fourth_byte)=(int(octet[0]),int(octet[1]),int(octet[2]),int(octet[3]))
        if len(str(first_byte))>3 :
            print("Incorrect lenght of  IP in first octet")
            cont()
        elif  len(str(second_byte))>3 :
            print("Incorrect lenght of  IP in second octet")
            cont()
        elif  len(str(third_byte))>3 :
            print("Incorrect lenght of  IP in third octet")
        elif len(str(fourth_byte))>3 :
            print("Incorrect lenght of  IP in fourth octet")
            cont()
        elif octet[4:]:
            print("Extra bits encountered so  Give IP in Format as A.B.C.D ")
            cont()

        if (first_byte==0 or first_byte<=127):
            if (second_byte==0 or second_byte<=255):
                if( third_byte==0 or third_byte<=255 ):
                    if (fourth_byte==0 or fourth_byte<=255):
                        print("Class A IP")
                        subnet(octet,'A')
                        cont()
                    else:
                        print("Invalid 4th octet of Class A IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class A IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class A IP")
                cont()                         
               
        elif (first_byte==128 or first_byte<=191):
            if (second_byte==0 or second_byte<=255):
                if( third_byte==0 or third_byte<=255 ):
                    if (fourth_byte==0 or fourth_byte<=255):
                        print("Class B IP")
                        subnet(octet,'B')
                        cont()
                    else:
                        print("Invalid 4th octet of Class B IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class B IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class B IP")
                cont()   
        elif (first_byte==192 or first_byte<=223):
            if (second_byte==0 or second_byte<=255):
                if( third_byte==0 or third_byte<=255 ):
                    if (fourth_byte==0 or fourth_byte<=255):
                        print("Class C IP")
                        subnet(octet,'C')
                        cont()
                    else:
                        print("Invalid 4th octet of Class C IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class C IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class C IP")
                cont()                         
        elif (first_byte==224 or first_byte<=239):
            if (second_byte==0 or second_byte<=255):
                if( third_byte==0 or third_byte<=255 ):
                    if (fourth_byte==0 or fourth_byte<=255):
                        print("Class D IP")
                        subnet(octet,'D')
                        cont()
                    else:
                        print("Invalid 4th octet of Class D IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class D IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class D IP")
                cont()                         
        elif (first_byte==240 or first_byte<=255):
            if (second_byte==0 or second_byte<=255):
                if( third_byte==0 or third_byte<=255 ):
                    if (fourth_byte==0 or fourth_byte<=255):
                        print("Class E IP")
                        subnet(octet,'E')
                        cont()
                    else:
                        print("Invalid 4th octet of Class E IP")
                        cont()
                else:
                    print("Invalid 3rd octet of Class E IP")
                    cont()
            else:
                print("Invalid 2nd octet of Class E IP")
                cont()                         

        else:
                print("Invalid IP")
                cont()
        

    elif option == 2:
                print("Exit")
     

def subnet(octet,clas):
  print("Do you want to Subnet",".".join(octet), " IP  \n" ,"\bPress Y/N to continue subnetting and exit respectively")
  inputchar=input()
  clas=clas.upper()
  if(inputchar=="Y" or inputchar=="y"):
      print("Enter cidr value")
      cidr=input()
      if((clas=="A" and int(cidr)<8) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
      elif((clas=="B" and int(cidr)<16) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
      elif((clas=="C" and int(cidr)<24) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
      elif(clas=="D"):
        print("Since it is a multicast address so you can't use this ip")
          #classD(octet,cidr)
      elif(clas=="E"):
        print("Since it is a loopback address so you can't use")
          #classE(octet,cidr)
      else:
          classA(octet,cidr,clas)
  elif(inputchar=="N" or inputchar=="n"):
       sys.exit()

     

def subnet(octet,clas):

    clas=clas.upper()
    print("Enter cidr value")
    cidr=input()
    if((clas=="A" and int(cidr)<8) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
    elif((clas=="B" and int(cidr)<16) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
    elif((clas=="C" and int(cidr)<24) or int(cidr)>33):
        print("Invalid CIDR for class",clas," IP")
        cont()
    elif(clas=="D"):
        print("Since it is a multicast address so you can't use this ip")
          #classD(octet,cidr)
    elif(clas=="E"):
        print("Since it is a loopback address so you can't use")
          #classE(octet,cidr)
    else:
          classA(octet,cidr,clas)
  


def classA(octet,cidr,type):

    if(type=="A")  :     
            (first_byte,second_byte,third_byte,fourth_byte)=(int(octet[0]),0,0,0)
            extracidr=int(cidr)-8
            Networknumber=int(math.pow(2,extracidr))
            Validipnumber=int(math.pow(2,32-int(cidr))-2)
            print("No. of Networks",int(Networknumber))
            print("No of valid host per Network",int(Validipnumber))
            Testing(cidr,extracidr,first_byte,second_byte,third_byte,fourth_byte,type)

    if(type=="B"):
            (first_byte,second_byte,third_byte,fourth_byte)=(int(octet[0]),int(octet[1]),0,0)
            extracidr=int(cidr)-16
            Networknumber=int(math.pow(2,extracidr))
            Validipnumber=int(math.pow(2,32-int(cidr))-2)
            print("No. of Networks",int(Networknumber))
            print("No of valid host per Network",int(Validipnumber))
            Testing(cidr,extracidr,first_byte,second_byte,third_byte,fourth_byte,type)
    if(type=="C"):
            (first_byte,second_byte,third_byte,fourth_byte)=(int(octet[0]),int(octet[1]),int(octet[2]),0)
            extracidr=int(cidr)-24
            Networknumber=int(math.pow(2,extracidr))
            Validipnumber=int(math.pow(2,32-int(cidr))-2)
            print("No. of Networks",int(Networknumber))
            print("No of valid host per Network",int(Validipnumber))
            Testing(cidr,extracidr,first_byte,second_byte,third_byte,fourth_byte,type)

def Testing(cidr,extracidr,first_byte,second_byte,third_byte,fourth_byte,type):
    fsm=255 #fistsubnetmask aka fsm
    ssm=0
    tsm=0
    lsm=0
    blocksize=0
    n=7 #defining no. bits to obtain the subnet mask e.g if 1 bit is on that means 255.10000000.0.0 we can 2power7 and if 2 bit is on  we can do 2power7+2power6 and soon
    print("-"*50)
    print("Network Id \t Valid IPs \t Broadcast Id")
    print("-"*50)
    if(type=="A" and int(cidr)>8):
            if not (ssm==255):
              for bits in range(0,extracidr):
                  if True:
                    ssm=ssm+int(math.pow(2,n-bits))

            if(ssm==255 and int(cidr)>16):
                for bits in range(0,extracidr-8):
                    if True:
                        tsm=tsm+int(math.pow(2,n-bits))
            if(tsm==255 and int(cidr)>24):
                for bits in range(0,extracidr-16):
                    if True:
                        lsm=lsm+int(math.pow(2,n-bits))

            
            if(ssm>=0 and ssm<=255 and tsm==0 and (int(cidr) in range(9,17))):
                blocksize=256-ssm
                print("Blocksize of the Network is ",blocksize)
                while not (second_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    second_byte+=int(blocksize)
                    print("\t",first_byte,".",second_byte-1,".",third_byte+255,".",fourth_byte+255-1, end="")
                    print("\t",first_byte,".",second_byte-1,".",third_byte+255,".",fourth_byte+255)

          
            if(tsm>0 and tsm<=255 and lsm==0 and (int(cidr) in range(17,25))):
                blocksize=256-tsm
                print("Blocksize of the Network is ",blocksize)
                while not (third_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    third_byte+=int(blocksize)
                    print("\t",first_byte,".",second_byte,".",third_byte-1,".",fourth_byte+255-1, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte-1,".",fourth_byte+255)
                    
                    
            if(lsm>0 and lsm<=255 and (int(cidr) in range(25,31)) ):
                blocksize=256-lsm
                print("Blocksize of the Network is ",blocksize)
                while  not (second_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    fourth_byte+=int(blocksize)
                    if(fourth_byte<=256):
                        print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-2, end="")
                        print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)
                    if(fourth_byte==256):
                        fourth_byte=0
                        third_byte+=1
                        if(third_byte==256):
                            third_byte=0
                            second_byte+=1
                            if(second_byte==256):
                                break
                        #print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-2, end="")
                        #print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

    
            if int(cidr)==31:
                blocksize=256-lsm
                print("Blocksize of the Network is ",blocksize)
                while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    fourth_byte+=int(blocksize)                 
                    print("\t\t\t\t\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

            if int(cidr)==32:
                blocksize=256-lsm
                print("Blocksize of the Network is ",blocksize)
                while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="\t\t\t\n")
                    fourth_byte+=int(blocksize)                 

                    
    if(type=="B" and int(cidr)>16):

    if(type=="B" and int(cidr)>=16):
        ssm=255
        if(ssm==255 and int(cidr)>16):
                for bits in range(0,extracidr):
                    if True:
                        tsm=tsm+int(math.pow(2,n-bits))
        if(tsm==255 and int(cidr)>24):
                for bits in range(0,extracidr-8):
                    if True:
                        lsm=lsm+int(math.pow(2,n-bits))

        if int(cidr)==16:
            blocksize=256-lsm
            print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
            fourth_byte+=int(blocksize)
            third_byte+=int(blocksize)                   
            print("\t\t\t\t\t",first_byte,".",second_byte,".",third_byte-1,".",fourth_byte-1)



        if int(cidr) in range(17,25):
          if(tsm>0 and tsm<=255 and lsm==0):
            blocksize=256-tsm
            print("Blocksize of the Network is ",blocksize)
            while not (third_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    third_byte+=int(blocksize)
                    print("\t",first_byte,".",second_byte,".",third_byte-1,".",fourth_byte+255-1, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte-1,".",fourth_byte+255)
                    
                    
        if int(cidr) in range(25,31):
          if(lsm>0 and lsm<=255 ):
            blocksize=256-lsm
            print("Blocksize of the Network is ",blocksize)
            while  not (third_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    fourth_byte+=int(blocksize)
                    if(fourth_byte<=256):
                        print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-2, end="")
                        print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)
                    if(fourth_byte==256):
                        fourth_byte=0
                        third_byte+=1
                        if(third_byte==256):
                            break
                            
                    #print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-int(2), end="")
                  
                    #print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

        if int(cidr)==31:
            blocksize=256-lsm
            print("Blocksize of the Network is ",blocksize)
            while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    fourth_byte+=int(blocksize)                 
                    print("\t\t\t\t\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

        if int(cidr)==32:
            blocksize=256-lsm
            print("Blocksize of the Network is ",blocksize)
            while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="\t\t\t\n")
                    fourth_byte+=int(blocksize)  
        

    if(type=="C" and int(cidr)>24):
        print("just check it")

    if(type=="C" and int(cidr)>=24):

        ssm=255
        tsm=255        
        if(tsm==255 and int(cidr)>24):
          for bits in range(0,extracidr):
            if True:
              lsm=lsm+int(math.pow(2,n-bits))
        
        if(lsm>0 and tsm==255 and (int(cidr) in range(25,31))):
                blocksize=256-lsm
                print("Blocksize of the Network is ",blocksize)
                while not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")
                    fourth_byte+=int(blocksize)
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-2, end="")
                    print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

        if int(cidr)==24:
            print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="\t\t\t")
            print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte+1, end="  ------")      
            fourth_byte+=int(256)
            print("\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-2, end="")       
            print(first_byte,".",second_byte,".",third_byte,".",fourth_byte-1, end="\t\t\t\n")    

        if int(cidr)==31:
            blocksize=256-lsm
            print("Blocksize of the Network is ",blocksize)
            while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="")
                    fourth_byte+=int(blocksize)                 
                    print("\t\t\t\t\t",first_byte,".",second_byte,".",third_byte,".",fourth_byte-1)

        if int(cidr)==32:
            blocksize=256-lsm
            print("Blocksize of the Network is ",blocksize)
            while  not (fourth_byte==256):
                    print(first_byte,".",second_byte,".",third_byte,".",fourth_byte, end="\t\t\t\n")
                    fourth_byte+=int(blocksize)
                    
                    

    print("New Subnet mask is ",fsm,"\b.",ssm,"\b.",tsm,"\b.",lsm)
         
               
switch()