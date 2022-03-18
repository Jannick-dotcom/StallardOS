import math
import os
import pandas as pd
import glob

read_file = pd.read_excel (glob.glob('CAN_System_Design_2021/*.xlsx')[0])
read_file.to_csv (r'CAN_System_Design_2021/Masterlist.csv', index = None, header=True)

infile = open("CAN_System_Design_2021/Masterlist.csv", "r") #the excel exported as csv with the Information
outfileDefs = open("lib/CAN/StallardOScanIDs.h", "w") #the output for IDs
outfileStructs = open("lib/CAN/StallardOScanStructs.hpp", "w") #the output for structs

outfileStructs.write("#ifndef StallardOScanStructs_hpp\n#define StallardOScanStructs_hpp\n")
outfileStructs.write('#include "stdint.h"\n#include "StallardOScanTypes.hpp"\n#include <math.h>\n\n') #include the integer types to the struct file
# outfileStructs.write("inline uint64_t jk_pow(uint8_t exp)\n{\n\treturn (1 << exp);\n}\n\n")

infileText = infile.read(-1) #read all stuff from the csv
infileArray = infileText.split("\n") #split the text into an array containing the lines
prevMSGName = "" #variable for saving the previous Message name
prevSigName = ""
bitcountInMsg = ""
bitcountWholeMessage = 0
strFunc = ""
signamesInMessage = "" #variable for printing in the build function

# messagesClass = ""

for x in infileArray: #Go through every line
    if(x > ""): #if there is something in the line
        lineArray = x.split(",") #split the line into columns
        id = str(lineArray[6])  #get the id of the message
        msgname = str(lineArray[7]) #get the name of the message
        rowcounter = str(lineArray[8]) #rowcounter from ms4
        signame = str(lineArray[9]) #get the name of the signal in the message
        if(signame.__contains__(" ")):
            signame = signame.replace(" ", "_")
        initVal = str(lineArray[14]) #get initial Value of the Signal
        signed = str(lineArray[13])  #is the signal signed or unsigned?
        startingAtBit = str(lineArray[10]) #get the Bit at which the signal starts
        canType = str(lineArray[5])
        byteOrder = str(lineArray[12])
        factor = str(lineArray[15])
        offset = str(lineArray[16])
        byteOrderBool = 0

        if(not rowcounter.__contains__("= 0x")):
            rowcounter = "0"
        else:
            rowcounter = rowcounter.split("= ")[1]

        if(msgname > "" and id > "" and id.startswith("0x")): #if valid message with valid id?
            bitcountIn = int(str(lineArray[11]))
            if(bitcountIn <= 8):
                bitcount = 8
            elif(bitcountIn <= 16):
                bitcount = 16
            elif(bitcountIn <= 32):
                bitcount = 32
            elif(bitcountIn <= 64):
                bitcount = 64
            else:
                print("Wrong bit count in " + msgname +" !\n")

            if(prevMSGName != msgname): #New Message?
                outfileDefs.write("#define STOS_CAN_ID_" + msgname + " " + id + "\n") #write a new define for the id
                if(bitcountWholeMessage > 64):
                    print("Something is wrong with size of PDU:" + prevMSGName)
                bitcountWholeMessage = 0

                if(prevMSGName != ""): #if this is not the first message name?
                    
                    outfileStructs.write(strFunc + "\t}\n")

                    outfileStructs.write("\tSTOS_CAN_PDU_" + prevMSGName + "() \n\t{\n\t\tID = _id;\n")
                    outfileStructs.write("\t\tuint8_t temp = " + bitcountInMsg + ";\n")
                    outfileStructs.write("\t\tif(temp % 8 != 0) temp = temp / 8 + 1;\n\t\telse temp = temp / 8;\n")
                    outfileStructs.write("\t\tif(temp > 8) temp = 8;\n")
                    outfileStructs.write("\t\t_size = dlc = temp;\n\t}\n")

                    outfileStructs.write("\tvoid build() {\n\t\tVal = " + signamesInMessage + ";\n\t\tID = _id;\n\t}\n")
                    
                    outfileStructs.write("};\n\n")
                    
                    bitcountInMsg = ""

                strFunc = "\tvoid unbuild()\n\t{\n"

                outfileStructs.write("struct STOS_CAN_PDU_" + msgname + " : public StallardOSCanMessage \n{\npublic:\n") #write the first struct

                outfileStructs.write("\tstatic const uint16_t _id = " + id + ";\n")
                outfileStructs.write("\tuint16_t _size;\n")
                
                # messagesClass += "\tSTOS_CAN_PDU_" + msgname + " elem" + id + ";\n"

                prevMSGName = msgname #set new previous name
                signamesInMessage = ""

            if(prevSigName != signame): #if new signal

                bitcountWholeMessage += bitcountIn
                if(byteOrder == "Motorola" and bitcountIn % 8 == 0 and bitcountIn > 8):########################################################################
                    startingAtBit = int(startingAtBit) - int(bitcountIn - 8)
                    byteOrderBool = 1

                if(int(startingAtBit) + bitcountIn > 64):
                    print("Something is wrong with bit positions of PDU:" + msgname)

                if(rowcounter != "0"):
                    strFunc += "\t\tif((Val & 0xFF) == " + rowcounter + ") //If the rowcounter points to this row \n\t"
                # strFunc += "\t\t" + signame + ".value = ((Val & (~(jk_pow(" + signame + ".startbit)-1))) & ((uint64_t)(jk_pow(" + signame + ".countOfBits)-1) << (uint64_t)" + signame + ".startbit)) >> (uint64_t)" + signame +".startbit;\n"
                strFunc += "\t\t" + signame + ".unbuild(Val);\n"

                if(signamesInMessage != ""):
                    signamesInMessage = signamesInMessage + " | "
                signamesInMessage = signamesInMessage + signame + ".build()"

                if(bitcountInMsg != ""):
                    bitcountInMsg = bitcountInMsg + " + "
                bitcountInMsg = bitcountInMsg + str(signame) + ".countOfBits"

                outfileStructs.write("\tCAN_Signal<")
                if(signed == "Unsigned"):      #is unsigned?
                    outfileStructs.write("u")
                outfileStructs.write("int"+ str(bitcount) + "_t> ")
                outfileStructs.write(signame + " = {" + initVal + ", " + str(bitcountIn) + ", " + str(startingAtBit) + ", " + str(rowcounter) + ", " + str(byteOrderBool) + ", " + str(factor) + ", " + str(offset) + "};//init,bitcount,startbit,rowcount,isMotorola,factor,offset \n") #write a signal
                prevSigName = signame
            else:
                print("Something is wrong with Signals of PDU:" + msgname + "!!!")

# messagesClass += "};\n"

# outfileStructs.write("\tuint64_t jk_pow(uint8_t exp)\n\t{\n\t\treturn (1 << exp);\n\t}\n")
outfileStructs.write(strFunc + "\t}\n")

outfileStructs.write("\tSTOS_CAN_PDU_" + prevMSGName + "() \n\t{\n\t\tID = _id;\n")
outfileStructs.write("\t\tuint8_t temp = " + bitcountInMsg + ";\n")
outfileStructs.write("\t\ttemp = (temp + 8 - (temp % 8)) / 8;\n")
outfileStructs.write("\t\tif(temp > 8) temp = 8;\n")
outfileStructs.write("\t\t_size = dlc = temp;\n\t}\n")

outfileStructs.write("\tvoid build() {\n\t\tVal = " + signamesInMessage + ";\n\t\tID = _id;\n\t}\n")
outfileStructs.write(";\n}; \n\n#endif")
# outfileStructs.write(messagesClass)

infile.close() #close the files
outfileDefs.close()
outfileStructs.close()

os.remove('CAN_System_Design_2021/Masterlist.csv')