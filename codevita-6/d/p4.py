import math
h,d=input().split(',')
la,ls,ra,rs=input().split(',')
rx=d/2
ry=0
lx=-d/2
ly=0
i=0.0
lc=False
rc=False
while (lx<=rx):
	i=i+0.5
	if(lc):
		
	else:
		lx=ls*i*math.sin(math.radians(90-la))-(d/2)
		ly=ls*i**math.cos(math.radians(la))
		if(lx>=h/2):
			lc=True
	if(rc):

	else:
		rx=(d/2)-(rs*i*math.sin(math.radians(90-ra)))
		ry=rs*i*math.cos(math.radians(ra))
		if(rx>=h/2):
			rc=True
	if(i>=1.0):

	else:
		if(lx==rx&&ly==ry):
			print("Yes,",lx,",",rx)
if(lx>rx):
	print("No")