from random import randint as r
File=open('test1.in','w+')
n=r(1,100000)
File.write(str(n)+'\n')
#print(n)
for x in range(n):
    a=r(1,2)
    if a==1:
        b=r(1,n)
	pom=str(a)+' '+str(b)+'\n';
	File.write(str(pom))
	# print(a,b,c)
    else:
        b=r(1,n)
        c=r(b,n)
        val=r(0,10000)
	pom=str(a)+' '+str(b)+' '+str(c)+' '+str(val)+'\n';
	File.write(str(pom))

File.close()
