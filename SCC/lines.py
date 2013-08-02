import sys

fin=open(sys.argv[1])
prev_num=0
cnt=0
for line in fin:
	numbers=line.split(" ")
	print numbers
	if int (numbers[0])!=prev_num:
		cnt=cnt+1
		print cnt
		prev_num=int (numbers[0])
print cnt