

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <list>
#include <sys/resource.h>
#include <algorithm>
using namespace std;

class Node{
	public:
		list<unsigned int> forwardNodes;
		list<unsigned int> reverseNodes;
		unsigned int finishing_time;
		unsigned int explored;
		unsigned int temp_explored;
		unsigned int assigned;
		void reset(){
			explored=0;
			temp_explored=0;
			
		}
		Node(){
			explored=0;
			temp_explored=0;
			assigned=0;
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
			//cout<<"\nPushed item="<<item;
		}
		unsigned int pop(){
			s_pointer--;		
			int temp=s.back();
			s.pop_back();
			//cout<<"\nPoped item="<<temp;
			return temp;
		}
		
		unsigned int peek(){
			//cout<<"\nPeeked item="<<s[s_pointer-1];
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
				//cout<<"\nHere";
				unsigned int temp_node=stack.peek();
				//cout<<"\nTemp_node="<<temp_node;
				//nodes[temp_node].temp_explored=1;
				list<unsigned int>::iterator j;
				int pushed=0;
				for(j=nodes[temp_node].forwardNodes.begin();j!=nodes[temp_node].forwardNodes.end();++j){
					//cout<<"\n*j="<<*j<<" temp_explored="<<nodes[*j].temp_explored;
					if(nodes[*j].temp_explored==0){
						SCC_size++;
						nodes[*j].temp_explored=1;
						//cout<<"\nSCC_Size="<<SCC_size;
						stack.push(*j);
						pushed=1;
						}			
				}
				//cout<<"\nPushed="<<pushed;
				if(pushed==0){
					nodes[temp_node].explored=1;
				}
				if (nodes[temp_node].explored==1){
					finish_time++;
					//cout<<"\nfinish_time"<<finish_time;
					nodes[temp_node].finishing_time=finish_time;
					second_array.push_back(temp_node);
					stack.pop();
				}
			}
			SCC_sizes.push_back(SCC_size);	
			//cout<<"\n########################Leader="<<second_array[k-1]<<" "<<SCC_size;
		}		
	}	
	return SCC_sizes;
}

vector<int> DFS(Node nodes[], unsigned int current_node){
	Stack stack;	
	vector <int> second_array;
	int finish_time=0;	
	cout<<"#######rev DFS";
	int n_nodes=0;
	for(int k=current_node;k>0;k--){
		if (nodes[k].assigned==1){
			n_nodes++;
			if (nodes[k].temp_explored!=1){
				nodes[k].temp_explored=1;	
				stack.push(k);	
				while(stack.s_pointer>0){
					//cout<<"\nHere";
					unsigned int temp_node=stack.peek();
					nodes[temp_node].temp_explored=1;
					//cout<<"\nTemp_node="<<temp_node;
					list<unsigned int>::iterator j;
					int pushed=0;
					for(j=nodes[temp_node].reverseNodes.begin();j!=nodes[temp_node].reverseNodes.end();++j){
						//cout<<"\n*j="<<*j<<" temp_explored="<<nodes[*j].temp_explored;
						if(nodes[*j].temp_explored==0){
							//nodes[*j].temp_explored=1;
							stack.push(*j);
							pushed=1;
							}			
					}
					//cout<<"\nPushed="<<pushed;
					if(pushed==0){
						
						if(nodes[temp_node].explored==0){						
							nodes[temp_node].explored=1;
						}else if(nodes[temp_node].explored==2){
							stack.pop();
						}	
							
					}
					if (nodes[temp_node].explored==1){
						finish_time++;
						//cout<<"\nfinish_time"<<finish_time;
						nodes[temp_node].finishing_time=finish_time;
						second_array.push_back(temp_node);
						stack.pop();
						nodes[temp_node].explored=2;
					}
				}
			}
		}
	}
	cout<<"\nn_nodes rev DFS="<<n_nodes;
	cout<<"\nSecond array Size="<<second_array.size();
	/*for(int i=1;i<10;i++){
		cout<<"\ni="<<i;
		cout<<" finishing time="<<nodes[i].finishing_time;
	}*/
	return second_array;
}

int main(int argc, char* argv[]){

	cout<<"Welcome to SCC";
	
	const rlim_t sz=16*1024*1024; // we need 16MB
    struct rl;    // we use to ask and receive data
    int result;
    // first get current limit to get rl filled out
   // result = getrlimit(RLIMIT_STACK, &rl);
    /*if(!result){    // getrlimit returns 0 for success
        rl.rlim=sz; // tell them we want 16MB
        result = setrlimit(RLIMIT_STACK, &rl);
        if(result){ 
            // error error will robinson
            std::cerr << "Baboo, can't do it!\n";
        }
    }
	*/
	
	ifstream infile(argv[1]);
	string line;
	int cnt=0;
	while (getline (infile,line) )    {      
		cnt++;
	}
	infile.close();
	infile.open(argv[1]);
	Node* nodes= new Node[900000];
	//vector <Node> nodes;
	unsigned int prev_node=0;
	unsigned int parent_node;
	int n_nodes=0;
	while (getline (infile,line) )    {  
		std::vector<std::string> strings;
		std::istringstream f(line);
		std::string s;
		//cout<<"\n";
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
					//cout<<"\nparent_node="<<parent_node<<" n_nodes="<<n_nodes;;
				}
				if (parent_node%100000==0)
					cout<<"\nparent_node="<<parent_node;
			}else{
				//cout<<"\nint_node="<<int_node;
				Node p_node,i_node;
				//nodes.insert(nodes.begin()+parent_node,p_node);
				//nodes.insert(nodes.begin()+int_node,i_node);
				nodes[parent_node].forwardNodes.push_back(int_node);
				nodes[int_node].reverseNodes.push_back(parent_node);
				nodes[parent_node].assigned=1;
				nodes[int_node].assigned=1;
			}
		}
		
	}
	
	for (int i=1;i<875714;i++){
		if (nodes[i].assigned!=1){
			cout<<"\nNode i="<<i;
		}
	}
	cout<<"\nNo node found";
	/*
	for(int i=1;i<=n_nodes;i++){
		cout<<"\nNode="<<i;
		list<unsigned int>::iterator j;
		cout<<"\nForward Node=";	
		if (nodes[i].assigned==1){
			for(j=nodes[i].forwardNodes.begin();j!=nodes[i].forwardNodes.end();++j){
				cout<<" "<<*j;
			}
			cout<<"\nReverse Node=";		
			for(j=nodes[i].reverseNodes.begin();j!=nodes[i].reverseNodes.end();++j){
				cout<<" "<<*j;
			}
		}
	}
	
	*/
	unsigned int n=parent_node;
	vector <int> second_array;
	second_array=DFS(nodes,n);	
	cout<<"\nSecond_array size="<<second_array.size();
	for (int i=second_array.size(); i>0; i--){
		//cout<<"\ni="<<i<<" "<<second_array[i-1];
		nodes[second_array[i-1]].reset();
	}
	/*
	for(int i=1;i<=n_nodes;i++){
		if (nodes[i].assigned==1){
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
	}
	*/
	vector <int> SCC_sizes;	
	SCC_sizes=fwdDFS(nodes, second_array);
	int max_size=0, second_max=0, third_max=0,fourth_max=0,fifth_max=0;
	int n_nodes2=0;
	
	for (int i=0; i<SCC_sizes.size(); i++){
			n_nodes2+=SCC_sizes[i];
			//cout<<"\n SCC="<<SCC_sizes[i];
			cout<<"\ni"<<i;
			for (int j=i;j<SCC_sizes.size();j++){
				if(SCC_sizes[j]<SCC_sizes[i]){
					int temp=SCC_sizes[j];
					SCC_sizes[j]=SCC_sizes[i];
					SCC_sizes[i]=temp;
				}
			}			
	}
	cout<<"\nn_nodes="<<n_nodes;	
	cout<<"\nn_nodes2="<<n_nodes2;
	cout<<"\n1st="<<SCC_sizes[SCC_sizes.size()-1];
	cout<<"\n2nd="<<SCC_sizes[SCC_sizes.size()-2];
	cout<<"\n3rd="<<SCC_sizes[SCC_sizes.size()-3];
	cout<<"\n4th="<<SCC_sizes[SCC_sizes.size()-4];
	cout<<"\n5th="<<SCC_sizes[SCC_sizes.size()-5];
	
	
}


