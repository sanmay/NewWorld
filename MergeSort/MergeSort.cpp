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
		MergeSort(input,left_start,left_end);
		cout<<"\nRight start="<<right_start;
		cout<<"\nRight end="<<right_end;				
		MergeSort(input,right_start,right_end);
		cout <<"\nMerging";
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
  
	int input []={1,3,5,2,4,6};
	int start=0;
	int end=5;
	
	MergeSort(input, start, end);

	return 0;
}
