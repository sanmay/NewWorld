

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

class Node{
	public:
		list<unsigned int> forwardNodes;
		list<unsigned int> reverseNodes;
		unsigned int finishing_time;
		unsigned int explored;
		unsigned int temp_explored;
		void reset(){
			explored=0;
			temp_explored=0;
		}
		Node(){
			explored=0;
			temp_explored=0;
		}
};

class Stack{
	public:
		vector<unsigned int> s;
		int s_pointer;	
		Stack(){
			s_pointer=0;
		}
		void push(unsigned int item){
			s.push_back(item);
			s_pointer++;
			cout<<"\nPushed item="<<item;
		}
		unsigned int pop(){
			s_pointer--;		
			int temp=s.back();
			s.pop_back();
			cout<<"\nPoped item="<<temp;
			return temp;
		}
		
		unsigned int peek(){
			cout<<"\nPeeked item="<<s[s_pointer-1];
			return s[s_pointer-1];
		}
};

vector <int> fwdDFS(Node nodes[], vector <int> second_array){
	Stack stack;		
	int finish_time=0;
	vector <int> SCC_sizes;
	cout<<"\n\n***************fwdDFS***********";
	
	for(int k=second_array.size(); k>0; k--){
		int SCC_size=0;
		if (nodes[second_array[k-1]].temp_explored!=1){
			nodes[second_array[k-1]].temp_explored=1;	
			SCC_size++;
			stack.push(second_array[k-1]);				
			while(stack.s_pointer>0){
				cout<<"\nHere";
				unsigned int temp_node=stack.peek();
				cout<<"\nTemp_node="<<temp_node;
				list<unsigned int>::iterator j;
				int pushed=0;
				for(j=nodes[temp_node].forwardNodes.begin();j!=nodes[temp_node].forwardNodes.end();++j){
					cout<<"\n*j="<<*j<<" temp_explored="<<nodes[*j].temp_explored;
					if(nodes[*j].temp_explored==0){
						SCC_size++;
						nodes[*j].temp_explored=1;
						stack.push(*j);
						pushed=1;
						}			
				}
				cout<<"\nPushed="<<pushed;
				if(pushed==0){
					nodes[temp_node].explored=1;
				}
				if (nodes[temp_node].explored==1){
					finish_time++;
					cout<<"\nfinish_time"<<finish_time;
					nodes[temp_node].finishing_time=finish_time;
					second_array.push_back(temp_node);
					stack.pop();
				}
			}
			SCC_sizes.push_back(SCC_size);	
			cout<<"\n########################Leader="<<second_array[k-1]<<" "<<SCC_size;
		}		
	}	
	return SCC_sizes;
}

vector<int> DFS(Node nodes[], unsigned int current_node){
	Stack stack;	
	vector <int> second_array;
	int finish_time=0;	
	
	for(int k=current_node;k>0;k--){
		if (nodes[k].temp_explored!=1){
			nodes[k].temp_explored=1;	
			stack.push(k);	
			while(stack.s_pointer>0){
				cout<<"\nHere";
				unsigned int temp_node=stack.peek();
				cout<<"\nTemp_node="<<temp_node;
				list<unsigned int>::iterator j;
				int pushed=0;
				for(j=nodes[temp_node].reverseNodes.begin();j!=nodes[temp_node].reverseNodes.end();++j){
					cout<<"\n*j="<<*j<<" temp_explored="<<nodes[*j].temp_explored;
					if(nodes[*j].temp_explored==0){
						nodes[*j].temp_explored=1;
						stack.push(*j);
						pushed=1;
						}			
				}
				cout<<"\nPushed="<<pushed;
				if(pushed==0){
					nodes[temp_node].explored=1;
				}
				if (nodes[temp_node].explored==1){
					finish_time++;
					cout<<"\nfinish_time"<<finish_time;
					nodes[temp_node].finishing_time=finish_time;
					second_array.push_back(temp_node);
					stack.pop();
				}
			}
		}
	}
	for(int i=1;i<10;i++){
		cout<<"\ni="<<i;
		cout<<" finishing time="<<nodes[i].finishing_time;
	}
	return second_array;
}

int main(int argc, char* argv[]){

	cout<<"Welcome to SCC";

	ifstream infile(argv[1]);
	string line;
	int cnt=0;
	while (getline (infile,line) )    {      
		cnt++;
	}
	infile.close();
	infile.open(argv[1]);
	Node nodes [1000];
	unsigned int prev_node=0;
	unsigned int parent_node;
	int n_nodes=0;
	while (getline (infile,line) )    {  
		std::vector<std::string> strings;
		std::istringstream f(line);
		std::string s;
		cout<<"\n";
		int parent_flag=0;
		
		while (std::getline(f, s, ' ')) {
			strings.push_back(s);
			unsigned int int_node=atoi(s.c_str());			
			if(parent_flag==0){
				parent_flag=1;
				parent_node=int_node;
				if(parent_node!=prev_node){
					n_nodes++;
					prev_node=parent_node;
				}
				cout<<"\nparent_node="<<parent_node;
			}else{
				cout<<"\nint_node="<<int_node;
				nodes[parent_node].forwardNodes.push_back(int_node);
				nodes[int_node].reverseNodes.push_back(parent_node);
			}
		}
		
	}
	
	for(int i=1;i<=n_nodes;i++){
		cout<<"\nNode="<<i;
		list<unsigned int>::iterator j;
		cout<<"\nForward Node=";		
		for(j=nodes[i].forwardNodes.begin();j!=nodes[i].forwardNodes.end();++j){
			cout<<" "<<*j;
		}
		cout<<"\nReverse Node=";		
		for(j=nodes[i].reverseNodes.begin();j!=nodes[i].reverseNodes.end();++j){
			cout<<" "<<*j;
		}
	}
	
	
	unsigned int n=n_nodes;
	vector <int> second_array;
	second_array=DFS(nodes,n);	
	cout<<"\nSecond_array size="<<second_array.size();
	for (int i=second_array.size(); i>0; i--){
		cout<<"\ni="<<i<<" "<<second_array[i-1];
		nodes[second_array[i-1]].reset();
	}
	
	for(int i=1;i<=n_nodes;i++){
		cout<<"\nNode="<<i;
		list<unsigned int>::iterator j;
		cout<<"\nForward Node=";		
		for(j=nodes[i].forwardNodes.begin();j!=nodes[i].forwardNodes.end();++j){
			cout<<" "<<*j;
		}
		cout<<"\nReverse Node=";		
		for(j=nodes[i].reverseNodes.begin();j!=nodes[i].reverseNodes.end();++j){
			cout<<" "<<*j;
		}
	}
	
	vector <int> SCC_sizes;	
	SCC_sizes=fwdDFS(nodes, second_array);
	for (int i=SCC_sizes.size(); i>0; i--){
		cout<<"\ni="<<i<<" "<<SCC_sizes[i-1];		
	}
	
	
}


