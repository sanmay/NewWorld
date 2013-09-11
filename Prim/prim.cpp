
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <list>
#include <sys/resource.h>
#include <algorithm>
#include <limits>
using namespace std;

class Node{
	bool spanned;
	public:
		Node(){
			spanned=false;
		}
	
		bool isSpanned(){
			return spanned;
		}
		void setSpanned(){
			spanned=true;
		}
};

class Edge{
	public:
		int v1;
		int v2;
		int w;
};

int main(int argc, char* argv[]){

	cout <<"\nWelcome to Prims\n";
	ifstream infile(argv[1]);
	string line;
	int intialize=0;
	int n_edge=0;
	int n_nodes;
	Node* nodes;
	Edge* edges;
	
	while (getline (infile,line) )    {  
		std::vector<std::string> strings;
		std::istringstream f(line);
		std::string s;
		cout<<"\n";
		int vals[3];
		int cnt=0;	
		
		while (std::getline(f, s, ' ')) {
			strings.push_back(s);
			unsigned int int_node=atoi(s.c_str());	
			cout <<int_node<<" ";
			vals[cnt++]=int_node;
		}
		if (intialize==0){
			cout<<"\nInitialized";
			n_nodes=vals[0];
			nodes=new Node[vals[0]+1];
			edges=new Edge[vals[1]];
			intialize=1;
		}
		else{
			cout<<"\nAdding Edge";
			edges[n_edge].v1=vals[0];
			edges[n_edge].v2=vals[1];
			edges[n_edge++].w=vals[2];
		}
	}
	
	for(int i=0;i<n_edge;i++){
		cout<<"\ni="<<i<<" v1="<<edges[i].v1<<" v2="<<edges[i].v2<<" w="<<edges[i].w;
	}
	
	vector <int> spanned_nodes;
	int start_node=1;
	
	spanned_nodes.push_back(start_node);
	nodes[start_node].setSpanned();
	long int mst_cost=0;
	while(spanned_nodes.size()<n_nodes){
		int low_edge = std::numeric_limits<int>::max();
		int low_edge_loc;
		cout<<"\nNew Spanned##########";
		for(int i=0;i<spanned_nodes.size();i++){
			int search_node=spanned_nodes[i];
			cout<<"\nSpanned="<<spanned_nodes[i];
			for (int j=0;j<n_edge;j++){
				if(edges[j].v1==search_node){
					if(!nodes[edges[j].v2].isSpanned()){
						if(edges[j].w<low_edge){
							low_edge=edges[j].w;
							low_edge_loc=j;
						}
					}
				}
				else if(edges[j].v2==search_node){
					if(!nodes[edges[j].v1].isSpanned()){
						if(edges[j].w<low_edge){
							low_edge=edges[j].w;
							low_edge_loc=j;
						}
					}
				}
			}

		}
		if(!nodes[edges[low_edge_loc].v2].isSpanned()){
			nodes[edges[low_edge_loc].v2].setSpanned();
			spanned_nodes.push_back(edges[low_edge_loc].v2);
		}else{
			nodes[edges[low_edge_loc].v1].setSpanned();
			spanned_nodes.push_back(edges[low_edge_loc].v1);
		}
		cout<<"\nEdge added="<<low_edge;
		mst_cost+=low_edge;
	}
	
	cout<<"\nMST="<<mst_cost;
	return 0;
}