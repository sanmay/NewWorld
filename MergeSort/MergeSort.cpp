#include <iostream>

using namespace std;
void print_debug_msg(int);
void print_debug_msg(string);

void MergeSort(int input[], int start, int end){
	if (start==end)
		print_debug_msg("One element in array");
	else{
		int left_start=start;
		int left_end= (start+end)/2;
		int right_start=((start+end)/2)+1;
		int right_end=end;
		cout<<"\nLeft start="<<left_start;
		cout<<"\nLeft end="<<left_end;
		cout<<"\nLeft Array";
		for(int i=0;i<=left_end-left_start;i++){
			cout<<" "<<input[left_start+i];
		}
		MergeSort(input,left_start,left_end);
		cout<<"\nRight start="<<right_start;
		cout<<"\nRight end="<<right_end;		
		cout<<"\nRight Array";
		for(int i=0;i<=right_end-right_start;i++){
			cout<<" "<<input[right_start+i];
		}		
		MergeSort(input,right_start,right_end);
		cout <<"\nMerging";
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
		cout<<"\nOriginal Array\n";
		for (int i=0;i<11;i++){
			cout<<" "<<input[i];
		}
			
			int cnt=0;
			while(left_ptr<left_n && right_ptr<right_n){
			cnt++;
			cout<<"\nsize"<<size;
			cout<<"\nleft_start+left_ptr"<<left_start+left_ptr;
			cout<<"\nleft_end"<<left_end;
			cout<<"\ninput[left_start+left_ptr]"<<input[left_start+left_ptr];
			cout<<"\ninput[right_start+right_ptr])"<<input[right_start+right_ptr];
				if(input[left_start+left_ptr]<input[right_start+right_ptr]){
						array[pos++]=input[left_start+left_ptr];
						cout<<"\nLeft ptr"<<left_ptr;
						left_ptr++;
						cout<<"\nLeft ptr"<<left_ptr;
						
				}
				else{
						array[pos++]=input[right_start+right_ptr];
						cout<<"\nRight ptr"<<right_ptr;
						right_ptr++;
						cout<<"\nRight ptr"<<right_ptr;
				}
			cout<<"\n";
			}
			while(left_start+left_ptr<=left_end){
				array[pos++]=input[left_start+left_ptr];
				left_ptr++;
			}
			while(right_start+right_ptr<=right_end){
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
			cout<<"\nOriginal";
			cout<<left_start<<" "<<i<<" "<<array[i];
			input[left_start+i]=array[i];
			cout<<"\nMerged";
			cout<<left_start<<" "<<i<<" "<<input[left_start+i];
		}
		cout<<"\nMerged Array\n";
		for (int i=0;i<11;i++){
			cout<<" "<<input[i];
		}
		
		
		
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

int main()
{
	cout <<"Welcome to Merge Sort";
	#ifdef DEBUG
		cout<< "\nIn Debug Mode";
	#endif
  
	int input []={9,55,2,-5,2,1,10,6,2,24,0};
	int start=0;
	int end=10;
	
	MergeSort(input, start, end);
	cout << "Sorted Array:";
	for (int i=0;i<11;i++){
		
		cout<<" "<<input[i];
	}

	return 0;
}
