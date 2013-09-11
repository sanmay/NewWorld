import sys

class Job:
	
	def _init_(self):
		weight=0.0
		length=0.0
		difference=0.0
	def set_val(self, weight, length, difference):
		self.weight=weight
		self.length=length
		self.difference=difference
	def print_job(self):
		print "\nWeight="+str(self.weight)+" length="+str(self.length)+" difference="+str(self.difference),

def main():
	print "hello world"
	fin=open(sys.argv[1],"r")
	jobs=[]
	for line in fin:
		numbers=line.split(" ")
		if len(numbers)>1:
			j=Job()			
			#j.set_val(int(numbers[0]), int(numbers[1]),int(numbers[0])-int(numbers[1]))
			j.set_val(int(numbers[0]), int(numbers[1]),float(float(numbers[0])/float(numbers[1])))
			jobs.append(j)			
			
	for n_job in jobs:
		n_job.print_job()
	jobs.sort(key=lambda x:x.difference, reverse=True)
	
	print "After Sorting"
	for n_job in jobs:
		n_job.print_job()
	
	prev_diff=0
	start=0
	end=0
	cnt=0
	for n_job in jobs:
		#print "Start="+str(start)+" end="+str(end)
		if prev_diff!=n_job.difference:
			print "Inside Start="+str(start)+" end="+str(end)
			#print jobs[start:end+1]
			jobs[start:end+1]=sorted(jobs[start:end+1],key=lambda x:x.weight, reverse=True)
			prev_diff=n_job.difference			
			start=cnt	
		end=cnt
		cnt=cnt+1
	jobs[start:end+1]=sorted(jobs[start:end+1],key=lambda x:x.weight, reverse=True)
		
	print "After Final Sorting"
	for n_job in jobs:
		n_job.print_job()
	completion_time=0
	weighted_sum=0
	for n_job in jobs:
		completion_time=completion_time+n_job.length
		weighted_sum=weighted_sum+completion_time*n_job.weight
	print weighted_sum
	
if __name__=="__main__":
	main()