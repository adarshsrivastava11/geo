def toUpper(str):
    a=[]
    for i in range(0,len(str)):
        a.append(chr(ord(str[i])-32))
    return "".join(a)

f=open("temp.txt","r")

a=f.readlines()
for i in a:
    print i[:len(i)-1], "\t\t\t\treturn", toUpper(i[:len(i)-1])+"_T;"
