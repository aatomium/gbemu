hex = input("Hexadecimal ? ")
hex2 = ''
a = 0
j=0
for i in hex:
	if(a==0):
		a=a+1
		hex2 = hex2 + "0x" + i
	else:
		hex2 = hex2 + i + ','
		j=j+1
		a=0
print("\n\n\n")
print("uint8_t hexChar[" + str(j) + "] = {" + hex2[:-1] + "};")
print("printf(\"Injecting "+ str(j) + " bytes at adress 0x8000...\\n\");")
print("insertData(memory,0x8000,hexChar," + str(j) + ");")
#uint8_t hexChar[16] = {0x3C,0x00,0x42,0x00,0xB9,0x00,0xA5,0x00,0xB9,0x00,0xA5,0x00,0x42,0x00,0x3C,0x00};
#printf("Injecting 16 bytes at adress 0x8000...\n");
#insertData(memory,0x8000,hexChar,16);
