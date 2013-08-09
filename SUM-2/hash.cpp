#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;
class Bucket{
	public:
	vector <int> lists;

};

class hashtable{
	//vector <int> lists;
	public:
	vector <Bucket> buckets;
	//map <int, vector> buckets;
	int hash_func;
	hashtable(int n){
		hash_func=n;
		cout<<"\nInitializing";
		for(int i=0;i<n;i++){
			Bucket bucket;
			buckets.push_back(bucket);			
		}
	}
	
	int hash(int n){
		int hash_val;
		hash_val=n%hash_func;
		if (hash_val<0){
			hash_val*=-1;
		}
		return hash_val;
	}
	void insert(int n){
		int bucket_id=hash(n);
		//cout<<"\nbucket_id="<<bucket_id;
		buckets[bucket_id].lists.push_back(n);
		/*vector <int> lists;
		lists=buckets[bucket_id].pop_back();
		lists.push_back(n);
		buckets[bucket_id].push_back(lists);*/
	}
	bool look_up(int n, int m){
		int bucket_id=hash(n);
		for(int i=0;i<buckets[bucket_id].lists.size();i++){
			if(buckets[bucket_id].lists[i]==n){
				if(n!=m){
					return true;
				}
			}
		}
		return false;
	}
	void print_bucket(int n){
		cout<<"\nFor bucket="<<n;
		for(int i=0;i<buckets[n].lists.size();i++){
			cout<<" "<<buckets[n].lists[i];
		}
	}

};

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	string line;
	int cnt=0;
	vector <int> nums;
	vector <int> sums;
	cout<<"\nWelcome to hash";
	hashtable h(1048576);
	for (int i=0;i<20001;i++){
		sums.push_back(0);
	}
	cout<<"\nWelcome to Hash";	
	while (getline (infile,line) )    {  
		int n=atoi(line.c_str());	
		//cout<<"\n"<<n;
		cnt++;
		nums.push_back(n);
		h.insert(n);
	}
	cout<<"\n";
	h.print_bucket(1);
	cout<<"\ncnt="<<cnt;
	
	for(int i=-10000;i<=10000;i++){
		if(i%100==0)
			cout<<"\ni="<<i;
		for(int j=0;j<nums.size();j++){
			if(h.look_up(i-nums[j],nums[j])){
				sums[i+10000]=1;				
			}
		}
	}
	/*for (int i=0;i<nums.size();i++){
		if(i%1000==0)
			//cout<<"\ni="<<i;
		for(int j=i+1;j<nums.size();j++){
			long int temp_sum=nums[i]+nums[j];
			if(temp_sum>=-10000 && temp_sum<=10000){
				temp_sum=temp_sum+10000;
				sums[temp_sum]=1;
			}
		}
	}*/
	int t=0;
	for(int i=0;i<sums.size();i++){
		if(sums[i]==1){
			t++;
		}
	}
	cout<<"\nt="<<t;
	return 0;
}