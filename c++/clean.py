import os

path = os.listdir()
#print(path)
for i in path:

	if ".exe" in i:
		print("[-] Removing :  ",i)
		os.remove(i);


print(10*"-","DONE",10*"------", "\nRemaining Files:\t",path,end="\n")