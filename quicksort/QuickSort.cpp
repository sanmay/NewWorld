#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int getPivot(int input[], int start, int end){	
	int choice=2;
	cout<<"\nChoosing pivot using choice"<<choice;
	if (choice==2){
		cout<<"\nchoice="<<choice;
		int temp=input[start];
		input[start]=input[end];
		input[end]=temp;		
	}
	/*
	if (choice==3){
		cout<<"\nchoice="<<choice;
		int median=end/2;
		if(end-start<0){
			cout<<"\n*********LESS THAN TWO ELEMENTS************";
			
		}
		else{
		int swap;
		if((input[start]<input[median] && input[start]>input[end])||(input[start]>input[median] && input[start]<input[end])){
			swap=start;
		}
		else if ((input[median]<input[start] && input[median]>input[end])||(input[median]>input[start] && input[median]<input[end])){
			swap=median;
		}		
		else
			swap=end;
			
		int smallest, biggest;
		if(input[start]<input[median] && input[start]<input[end]){
				smallest=start;
		} 
		else if (input[median]<input[end]) {
				smallest=median;
		}
		else{
				smallest=end;
		}
		if(input[start]>input[median] && input[start]>input[end]){
				biggest=start;
		} 
		else if (input[median]>input[end]) {
				biggest=median;
		}
		else{
				biggest=end;
		}
		
		if (start!=smallest && start!=biggest){
			swap=start;
		}
		else if (end!=smallest && end!=biggest){
			swap=end;
		}
		else{
			swap=median;
		}
			
		
		int temp=input[start];
		input[start]=input[swap];
		input[swap]=temp;		
}	
	}*/
	if (choice==3){
	
		int* array=new int[3];
		cout<<"\n start, end, end/2="<<start<<" "<<end<<" "<<(end+start)/2;
		if(end-start>1){
		cout<<"\n end-start>1";
		array[0]=input[start];
		array[1]=input[(end+start)/2];
		array[2]=input[end];
		int swap;
		cout<<"\nOriginal Array:";
		for (int i=0; i<3;i++){
			cout<<" "<<array[i];
		}
		
		for (int i=0;i<3;i++){
			for (int j=i;j<3;j++){
				if (array[j]<array[i]){
					int temp=array[j];
					array[j]=array[i];
					array[i]=temp;
				}
			}
		}
		cout<<"\nSorted Array:";
		for (int i=0; i<3;i++){
			cout<<" "<<array[i];
		}
		if (input[start]==array[1]){
			swap=start;
		}
		else if (input[(end+start)/2]==array[1]){
			swap=(end+start)/2;
		}
		else if (input[end]==array[1]){
			swap=end;
		}
		cout<<"\nSwap"<<swap;
		int temp1=input[start];
		input[start]=input[swap];
		input[swap]=temp1;
	}
	}
	return start;
	
}
int QuickSort(int input[],int start, int end){
	if (start>=end){
		cout<<"\nStart bigger or equal than end"<<start<<" "<<end<<endl;
		return 0;
		}
		
	else{
		int pivot=getPivot(input,start, end);
		int i=1,j=1;
		int temp;
		cout<<"\nArray before adustment";
			for (int m=0;m<100;m++){
				cout<<" "<<input[m];
			}
		cout<<"\nPivot="<<pivot<<" value="<<input[pivot]<<" start="<<start<<" end="<<end;
		for (j=1;j<=end-start;j++){
			if(input[pivot]>input[start+j]){
				temp=input[start+i];
				input[start+i]=input[start+j];
				input[start+j]=temp;
				i++;			
			}
		}
		//cout<<"\ninput[start+i-1]="<<input[start+i-1]<<"start+i-1="<<start+i-1<<" "<<i;
		temp=input[pivot];
		input[pivot]=input[start+i-1];
		input[start+i-1]=temp;
		#ifdef DEBUG
			cout<<"\nArray after adustment";
			for (int m=0;m<100;m++){
				cout<<" "<<input[m];
			}
		#endif
		int left_comp=0;
		int right_comp=0;
		if(start+i-2-start>0){
			left_comp=start+i-2-start;
			cout<<"\n left comp"<<left_comp;
		}
		if(end-start-i>0){
			right_comp=end-start-i;
			cout<<"\n right comp"<<right_comp;
		}
		cout<<"\nMaking Recusrion calls with start, start+i-2,i="<<start<<" "<<start+i-2<<" "<<i;
		cout<<"\nMaking Recusrion calls with start+i, end="<<start+i<<" "<<end;
		int left_n=QuickSort(input,start,start+i-2);
		int right_n=QuickSort(input,start+i,end);
		//left_n+right_n+left_comp+right_comp
		cout<<"\n left_n:"<<left_n<<" right_n:"<<right_n<<"left_comp:"<<left_comp<<" right_comp:"<<right_comp;
		int comparisions=end-start+left_n+right_n;
		cout<<"\nend-start:"<<end-start<<" comparision:"<<comparisions;
		return comparisions;
	}
}

int main(int argc, char* argv[]){
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
	//int input[]={5,4,3,2,1,10,0,30,3099,-1,42,45};
	int start=0;
	int end=cnt-1;
	cout<<"Welcome to QuickSort"<<endl;	
	int comparisions=QuickSort(input, start, end);
	cout<<"\n\nSorted Array"<<endl;
	for (int i=0;i<=end;i++){
		cout<<" "<<input[i];
	}
	cout<<"\n comparisions="<<comparisions;

}