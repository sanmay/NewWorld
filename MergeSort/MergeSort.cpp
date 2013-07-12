#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void print_debug_msg(int);
void print_debug_msg(string);

int MergeSort(int input[], int start, int end){
	if (start==end){
		print_debug_msg("One element in array");
		return 0;
		}
	else{
		int left_start=start;
		int left_end= (start+end)/2;
		int right_start=((start+end)/2)+1;
		int right_end=end;
		#ifdef DEBUG
		cout<<"\nLeft start="<<left_start;
		cout<<"\nLeft end="<<left_end;
		cout<<"\nLeft Array";
		
		for(int i=0;i<=left_end-left_start;i++){
			cout<<" "<<input[left_start+i];
		}
		#endif
		long int x=MergeSort(input,left_start,left_end);
		#ifdef DEBUG
		cout<<"\nRight start="<<right_start;
		cout<<"\nRight end="<<right_end;		
		cout<<"\nRight Array";
		
		for(int i=0;i<=right_end-right_start;i++){
			cout<<" "<<input[right_start+i];
		}	
		#endif		
		long int y=MergeSort(input,right_start,right_end);
		#ifdef DEBUG
		cout <<"\nMerging";
		#endif
		int left_n=left_end-left_start+1;
		int right_n=right_end-right_start+1;
		int* array=new int[left_n+right_n];
		int size;
		if (left_n<=right_n)
			size=left_n;
		else
			size=right_n;
		int left_ptr=0;
		int right_ptr=0;
		int pos=0;	
		long int z=0;
			
			int cnt=0;
			while(left_ptr<left_n && right_ptr<right_n){
			cnt++;
			#ifdef DEBUG
			cout<<"\nsize"<<size;
			cout<<"\nleft_start+left_ptr"<<left_start+left_ptr;
			cout<<"\nleft_end"<<left_end;
			cout<<"\ninput[left_start+left_ptr]"<<input[left_start+left_ptr];
			cout<<"\ninput[right_start+right_ptr])"<<input[right_start+right_ptr];
			#endif
				if(input[left_start+left_ptr]<=input[right_start+right_ptr]){
						array[pos++]=input[left_start+left_ptr];
						#ifdef DEBUG
						cout<<"\nLeft ptr"<<left_ptr;						
						cout<<"\nLeft ptr"<<left_ptr;
						#endif
						left_ptr++;
						
				}
				else{
						array[pos++]=input[right_start+right_ptr];
						#ifdef DEBUG
						cout<<"\nRight ptr"<<right_ptr;						
						cout<<"\nRight ptr"<<right_ptr;
						#endif
						//z++;	
						z=z+(left_n-left_ptr);
						cout<<"\nZ="<<z;
						right_ptr++;
						
				}
			
			}
			//z=z*(left_n-left_ptr);
			cout<<"\nZ in comparision="<<z;
			cout<<"\nX="<<x;
			cout<<"\nY="<<y;
			while(left_ptr<left_n){
				array[pos++]=input[left_start+left_ptr];
				left_ptr++;					
								
			}
			while(right_ptr<right_n){
				array[pos++]=input[right_start+right_ptr];
				right_ptr++;
			}
			
		
		/*else{
			while(right_start+right_ptr<=right_end){
				if(input[left_start+left_ptr]<input[right_start+right_ptr]){
						array[pos++]=input[left_start+left_ptr];
						left_ptr++;
				}
				else{
						array[pos++]=input[right_start+right_ptr];
						right_ptr++;
				}
			}
			
		}*/
		
		for(int i=0;i<=right_end-left_start;i++){
			
			input[left_start+i]=array[i];			
		}		
		
		
		return x+y+z;
		
	}
		

}

void print_debug_msg(int msg){
	#ifdef DEBUG
		cout<<"\n"<< msg;
	#endif
}

void print_debug_msg(string msg){
	#ifdef DEBUG
		cout<<"\n"<< msg;
	#endif
}

int main(int argc, char* argv[])
{
	cout <<"Welcome to Merge Sort";
	#ifdef DEBUG
		cout<< "\nIn Debug Mode";
	#endif
	ifstream infile(argv[1]);
	string line;
	int cnt=0;
	while (getline (infile,line) )    {
      
      cnt++;
    }
	infile.close();
	infile.open(argv[1]);
	int* input=new int[cnt];
	cnt=0;
	while (getline (infile,line) )    {      
	  input[cnt]=atoi(line.c_str());
	  cout<<"\n"<<input[cnt++];
	}	
	int start=0;
	int end=cnt-1;
	int inversions=0;
	inversions=MergeSort(input, start, end);
	cout << "\nSorted Array:";
	for (int i=0;i<=end;i++){
		
		cout<<" "<<input[i];
	}
	cout<<"\nInversions="<<inversions;
	return 0;
}
