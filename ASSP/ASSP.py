import sys


class Node:
	def __init__(self):
		self.node=0
	def assign(self, v):
		self.node=v

class Edge:

	def __init__(self):
		self.n1=0
		self.n2=0
		self.w=0
	
	def assign(n1,n2,w):
		self.n1=n1
		self.n2=n2
		self.w=w
	
	def print_Edge():
		print "N1="+str(self.n1)+" N2="+str(self.n2)+" W="+str(self.w)


def main():
	fin= open(sys.argv[1])
	Ai=[]
	Aj=[]
	A=[]
	n_nodes=0
	n_edges=0
	for line in fin:
		print line
		if len(line.split(" "))<3:
			n_nodes=int(line.split(" ")[0])
			n_edges=int(line.split(" ")[1])
			A=[[[0 for k in xrange(n_nodes)] for j in xrange(n_nodes)] for i in xrange(n_nodes)]
			for k in range(2):
				print k
				for i in range(n_nodes):
					for j in range(n_nodes):						
						A[i][j][k]=float("inf")	
						if i==j and k==0:
							A[i][j][k]=0
			
			
		else:
			i=int(line.split(" ")[0])-1
			j=int(line.split(" ")[1])-1
			cij=int(line.split(" ")[2])
			A[i][j][0]=cij
			print A[i][j]
	#print A
	
	for k in range(n_nodes):
			for i in range(n_nodes):
					for j in range(n_nodes): 
						if k-1>=0:
							Psoln=A[i][j][0]
							Csoln=A[i][k][0]+A[k][j][0]
							if Psoln<Csoln:
								A[i][j][1]=Psoln
							else:
								A[i][j][1]=Csoln
			for i in range(n_nodes):
					for j in range(n_nodes): 
						A[i][j][0]=A[i][j][1]
	min_distance=float("inf")
	for i in range(n_nodes):
		for j in range(n_nodes):
			if A[i][j][k]<min_distance:
				min_distance=A[i][j][k]
			if i==j:
				if A[i][i][k]<0:
					print "Negative Edge"
					exit()
	print "Min_distance="+str(min_distance)							
						
if __name__=="__main__":
	main()