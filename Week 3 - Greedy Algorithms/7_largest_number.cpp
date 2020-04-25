#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include<cstdlib>
#include<queue>

using namespace std;


inline int getdigits(int a){
	int count=0;
	while(a>0){
		a=a/10;
		++count;
	}
	return count;
}

/*
inline vector<int> breakingdigits(int a){
	vector<int>va;
	while(a!=0){
		va.insert(va.begin(),(a%10));
		a/=10;
	}
	return va;
}


inline bool IsGreaterOrEqual(int a, int b){
	vector<int> va=breakingdigits(a);
	vector<int> vb=breakingdigits(b);
	//cout<<"Breaking digits "<<a<<" and "<<b<<endl;
	int l=min(va.size(),vb.size()),i;
	for(i=0;i<l;++i){
		if((va[i]-vb[i])!=0)
			return va[i]>vb[i];
	}
	//cout<<"Initial digits are similar by length "<<l<<endl;
	if(i==l){
		if(vb.size()>l){
			l=vb.size();
			while(i<l){
				if(vb[i]<vb[0])
					return true;
				else if(vb[i]>vb[0])
					return false;
			}
			if(i==l)
				return true;
		}
		else{
			l=va.size();
			while(i<l){
				if(va[i]<va[0])
					return false;
				else if(va[i]>va[0])
					return true;
			}
			if(i==l)
				return true;
		}
	}
}

inline int largest_number(vector<int>& a) {
	vector<int> output;
	//cout<<"Inside largest no function"<<endl;
	vector<int>:: iterator it;
	int max_digit=0, remove=0;
	while(!a.empty()){
		//cout<<"Finding max digit"<<endl;
		max_digit=a[0];
		remove=0;
		for(int digit=1;digit<a.size();++digit){
			//cout<<"Comparing"<<endl;
			if(IsGreaterOrEqual(a[digit],max_digit)){
				max_digit=a[digit];
				remove=digit;
			}
		}
		//cout<<"Got max digit: "<<max_digit<<endl;
		it=a.begin()+remove;
		output.push_back(max_digit);
		a.erase(it);
		//cout<<"Removing "<<*it<<endl;
	}
	for(int i=0;i<output.size();++i)
		cout<<output[i];
}

inline int largest_number_better(vector<int>& a) {
	vector<int> output;
	//cout<<"Inside largest no function"<<endl;
	vector<int>:: iterator it;
	int max_digit=0, remove=0;
	while(!a.empty()){
		//cout<<"Finding max digit"<<endl;
		remove=rand()%a.size();
		max_digit=a[remove];
		for(int digit=0;digit<a.size();++digit){
			//cout<<"Comparing"<<endl;
			if(digit==remove)
				continue;
			if(IsGreaterOrEqual(a[digit],max_digit)){
				max_digit=a[digit];
				remove=digit;
			}
		}
		//cout<<"Got max digit: "<<max_digit<<endl;
		it=a.begin()+remove;
		output.push_back(max_digit);
		a.erase(it);
		//cout<<"Removing "<<*it<<endl;
	}
	for(int i=0;i<output.size();++i)
		cout<<output[i];
}

inline int largest_number_best(priority_queue<pair<int,int>> pq){
	//cout<<"Inside function";
	//if(!pq.empty())
	//	//cout<<"Not empty"<<endl;
	//else
	//	//cout<<"Empty"<<endl;
	while(!pq.empty()){
		//cout<<"Inside while loop"<<endl;
		pair<int,int> top=pq.top();
		int x=top.first;
		//cout<<"Got value "<<x<<endl;
		switch(top.second)
		{
		case 1:
			x=x/1000;
			break;
		case 2:
			x=x/100;
			break;
		case 3:
			x=x/10;
			break;
		}
		cout<<x;
		pq.pop();
	}
}
*/
/*
deque<int> getdeque(int a){
	deque<int> da;
	while(a>0){
		da.push_front(a%10);
		a=a/10;
	}
	return da;
}

bool compare(int a, int b){
	deque<int> da=getdeque(a);
	deque<int> db=getdeque(b);
	int base=da.front();
	while(min(da.size(),db.size())!=0){
		if(da.front()>db.front())
			return true;
		else if(da.front()<db.front())
			return false;
		else{
			da.pop_front();
			db.pop_front();
		}
	}
	if((da.empty())&&(db.empty()))
		return true;
	else if(da.empty()){
		while(base==db.front()){
			db.pop_front();
			if(db.empty())
				return true;
		}
		return base>db.front();
	}
	else{
		while(base==da.front()){
			da.pop_front();
			if(da.empty())
				return true;
		}
		return base<da.front();
	}
}
*/

inline bool compare(int a ,int b){
	int la=getdigits(a);
	int lb=getdigits(b);
	//cout<<a<<" has length "<<la<<" and compare value "<<a*pow(10,lb)+b<<endl;
	//cout<<b<<" has length "<<lb<<" and compare value "<<b*pow(10,la)+a<<endl;
	return (a*pow(10,lb)+b)>(b*pow(10,la)+a);
}
int main() {
  int n,x;
  cin >> n;
  int input[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> input[i];
  }
	sort(input,input+n,compare);
	//cout<<"Calling function"<<endl;
  for(size_t i=0;i<n;++i)
	cout<<input[i];
}






