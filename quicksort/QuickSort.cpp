#include <iostream>
#include <stdlib.h>

using namespace std;

int getPivot(int input[], int start, int end){
	return start;
}
void QuickSort(int input[],int start, int end){
	if (start>=end)
		cout<<"\nStart bigger or equal than end"<<start<<" "<<end<<endl;
	else{
		int pivot=getPivot(input,start, end);
		int i=1,j=1;
		int temp;
		cout<<"\nPivot="<<input[pivot]<<" start="<<start<<" end="<<end;
		for (j=1;j<=end-start;j++){
			if(input[pivot]>input[start+j]){
				temp=input[start+i];
				input[start+i]=input[start+j];
				input[start+j]=temp;
				i++;			
			}
		}
		cout<<"\ninput[start+i-1]="<<input[start+i-1]<<"start+i-1="<<start+i-1<<" "<<i;
		temp=input[pivot];
		input[pivot]=input[start+i-1];
		input[start+i-1]=temp;
		#ifdef DEBUG
			cout<<"\nArray"<<endl;
			for (int i=0;i<5;i++){
				cout<<" "<<input[i];
			}
		#endif
		QuickSort(input,start,start+i-2);
		QuickSort(input,start+i,end);
	}
}

int main(int argc, char* argv[]){

int input[]={5,4,3,2,1,10,0,30,3099,-1,42,45};
int start=0;
int end=11;
	cout<<"Welcome to QuickSort"<<endl;	
	QuickSort(input, start, end);
	cout<<"\n\nSorted Array"<<endl;
	for (int i=0;i<=end;i++){
		cout<<" "<<input[i];
	}

}