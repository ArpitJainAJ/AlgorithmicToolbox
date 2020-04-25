#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int binary_search(int a[], int x, int n, int& found) {
  int left = 0, right = n ,mid=(left+right)/2, more_than=-1; 
  //write your code here
	while(left<=right){
		if(a[mid]==x){
			found=1;
			int mid2=mid;
			while(mid<n){
				if(a[mid]==a[mid+1]){
					++mid;
					++found;
				}
				else
					break;
			}
			while(mid2>0){
				if(a[mid2]==a[mid2-1])
					--mid2;
					++found;
			}
			return mid;
		}
		else if(a[mid]<x){
			more_than=mid;
			left=mid+1;
			mid=(left+right)/2;
		}
		else{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	return more_than;
}

void fast_count_segments(int starts[], int ends[], vector<int> points, int n) {
	for(size_t i=0;i<points.size();++i){
		int found_a=0,found_b=0;
		int a=binary_search(starts,points[i],n, found_a);
		if(a==-1){
			//cout<<"a: "<<a<<", ";
			//cout<<0<<endl;
			cout<<0<<" ";
			continue;
		}
		int b=binary_search(ends,points[i],n, found_b);
		//cout<<"a: "<<a<<" found-"<<found_a<<",b: "<<b<<" found-"<<found_b<<", ";
		int count=a+1;
		if(found_b<=0)
			count-=b+1;
		else if(found_b==1)
			count-=b;
		else
			count-=b-found_b+1;
		//cout<<count<<endl;
		cout<<count<<" ";
	}	
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  int starts[n], ends[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < m; ++) {
    std::cin >> points[i];
  }
	sort(starts,starts+n);
	sort(ends, ends+n);
  //use fast_count_segments
  fast_count_segments(starts, ends, points,n-1);

}
