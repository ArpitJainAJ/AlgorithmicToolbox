#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

inline void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1,mid=(left+right)/2; 
  //write your code here
	while(left<=right){
		if(a[mid]==x) return mid;
		else if(a[mid]<x){
			left=mid+1;
			mid=(left+right)/2;
		}
		else{
			right=mid-1;
			mid=(left+right)/2;
		}
	}
	return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
	fastio();
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
	cout<<binary_search(a,b[i])<<' ';
  }
}
