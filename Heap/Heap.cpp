#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class heap_min{
	public:
		vector <int> heap_array;
		int size;
		
		heap_min(){
			size=0;
		}
		
		void bubble_up(){
			int child=heap_array.size()-1;
			int parent;
			//cout<<"\nchild="<<child;
			while(child>0){
				parent=(child-1)/2;
				if(heap_array[child]<heap_array[parent]){
					int temp=heap_array[child];
					heap_array[child]=heap_array[parent];
					heap_array[parent]=temp;
					child=parent;
				}
				else{
					break;
				}
			}
		}
		void insert(int n){
			heap_array.push_back(n);
			size++;			
			bubble_up();
			//print_heap();
		}
		
		int peek_min(){
			return (heap_array[0]);
		}
		void bubble_down(){
			int end=heap_array.size()-1;
			int temp=heap_array[0];
			heap_array[0]=heap_array[end];
			heap_array[end]=temp;
			heap_array.pop_back();
			end=heap_array.size();
			int parent=0;
			
			cout<<"\nheap[0]="<<heap_array[parent];
			//cout<<"\nHere";
			while(2*parent+1<end){
				if(2*parent+2<end){
					if((heap_array[parent]>heap_array[2*parent+1]) || (heap_array[parent]>heap_array[2*parent+2])){
						//cout<<"\nheap[parent]="<<heap_array[parent];
						//cout<<"\nheap_array[2*parent+1]="<<heap_array[2*parent+1];
						//cout<<"\nheap_array[2*parent+2]="<<heap_array[2*parent+2];
						if(heap_array[2*parent+1]<heap_array[2*parent+2]){
							temp=heap_array[parent];
							heap_array[parent]=heap_array[2*parent+1];
							heap_array[2*parent+1]=temp;
							parent=2*parent+1;
							//cout<<"\nIF1heap[parent]="<<heap_array[parent];
						}else{
							temp=heap_array[parent];
							heap_array[parent]=heap_array[2*parent+2];
							heap_array[2*parent+2]=temp;
							parent=2*parent+2;
							//cout<<"\nIF2heap[parent]="<<heap_array[parent];
						}
						//cout<<"\nHere123";
					}
					else{
						break;
					}
				}else{
					if(heap_array[parent]>heap_array[2*parent+1]){
						temp=heap_array[parent];
						heap_array[parent]=heap_array[2*parent+1];
						heap_array[2*parent+1]=temp;
						parent=2*parent+1;
					}
					else{
						break;
					}
				}
				
			}
		}
		int extract_min(){
			int min=heap_array[0];
			bubble_down();
			return min;
		}
		void print_heap(){
			cout<<"\nPrinting Heap";
			for (int i=0;i<heap_array.size();i++)
				cout<<"\n"<<heap_array[i];
			cout<<"\nEnd of heap";
		}
	
};

class heap_max{
	public:
		vector <int> heap_array;
		int size;
		
		heap_max(){
			size=0;
		}
		
		void bubble_up(){
			int child=heap_array.size()-1;
			int parent;
			//cout<<"\nchild="<<child;
			while(child>0){
				parent=(child-1)/2;
				if(heap_array[child]>heap_array[parent]){
					int temp=heap_array[child];
					heap_array[child]=heap_array[parent];
					heap_array[parent]=temp;
					child=parent;
				}
				else{
					break;
				}
			}
		}
		void insert(int n){
			heap_array.push_back(n);
			size++;			
			bubble_up();
			//print_heap();
		}
		
		int peek_max(){
			return (heap_array[0]);
		}
		void bubble_down(){
			int end=heap_array.size()-1;
			int temp=heap_array[0];
			heap_array[0]=heap_array[end];
			heap_array[end]=temp;
			heap_array.pop_back();
			end=heap_array.size();
			int parent=0;
			
			//cout<<"\nheap[0]="<<heap_array[parent];
			//cout<<"\nHere";
			while(2*parent+1<end){
				if(2*parent+2<end){
					if((heap_array[parent]<heap_array[2*parent+1]) || (heap_array[parent]<heap_array[2*parent+2])){
						//cout<<"\nheap[parent]="<<heap_array[parent];
						//cout<<"\nheap_array[2*parent+1]="<<heap_array[2*parent+1];
						//cout<<"\nheap_array[2*parent+2]="<<heap_array[2*parent+2];
						if(heap_array[2*parent+1]>heap_array[2*parent+2]){
							temp=heap_array[parent];
							heap_array[parent]=heap_array[2*parent+1];
							heap_array[2*parent+1]=temp;
							parent=2*parent+1;
							//cout<<"\nIF1heap[parent]="<<heap_array[parent];
						}else{
							temp=heap_array[parent];
							heap_array[parent]=heap_array[2*parent+2];
							heap_array[2*parent+2]=temp;
							parent=2*parent+2;
							//cout<<"\nIF2heap[parent]="<<heap_array[parent];
						}
						
					}
					else{
						break;
					}
				}else{
					if(heap_array[parent]<heap_array[2*parent+1]){
						temp=heap_array[parent];
						heap_array[parent]=heap_array[2*parent+1];
						heap_array[2*parent+1]=temp;
						parent=2*parent+1;
					}
					else{
						break;
					}
				}
				
			}
		}
		int extract_max(){
			int min=heap_array[0];
			bubble_down();
			return min;
		}
		void print_heap(){
			cout<<"\nPrinting Heap";
			for (int i=0;i<heap_array.size();i++)
				cout<<"\n"<<heap_array[i];
			cout<<"\nEnd of heap";
		}
	
};

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	string line;
	int cnt=0;
	cout<<"\nWelcome to Heap";
	heap_min h_high;
	heap_max h_low;
	int n_h_high=0;
	int n_h_low=0;
	int sum=0;
	while (getline (infile,line) )    {  
		int n=atoi(line.c_str());	
		cout<<"\n"<<n;
		if((n_h_low==0)&&(n_h_high==0)){
			h_low.insert(n);
			n_h_low++;
		}
		else{
			if(n<h_low.peek_max()){
				h_low.insert(n);
				n_h_low++;
			}else{
				h_high.insert(n);
				n_h_high++;
			}		
		}
		cout<<"\nh low:";
		h_low.print_heap();
		//cout<<"\nh high";
		//h_high.print_heap();		
		//cout<<"n_h_low="<<n_h_low;
		//cout<<"n_h_high="<<n_h_high;
		//cout<<"\nResizing";
		if(n_h_low!=n_h_high){
			if(n_h_low>n_h_high){
				h_high.insert(h_low.extract_max());
				n_h_low--;
				n_h_high++;
			}else{
				h_low.insert(h_high.extract_min());
				n_h_low++;
				n_h_high--;
			}
		}
		cout<<"\nh low:";
		h_low.print_heap();
		cout<<"\nh high";
		h_high.print_heap();
		int median;
		if(n_h_low==n_h_high){
			median=h_low.peek_max();
		}
		else if(n_h_low<n_h_high){
			median=h_high.peek_min();
		}else{
			median=h_low.peek_max();
		}
		cout<<"\n#######################Median="<<median;
		sum+=median;
		//h.insert(n);
		//cout<<"\npeek min="<<h.peek_max();
		//input[cnt]=atoi(line.c_str());
	}
	
	cout<<"\nSum="<<sum;
	
	
	
	return 0;
}