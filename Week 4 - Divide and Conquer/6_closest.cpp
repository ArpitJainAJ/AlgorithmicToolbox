#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include<limits>
#include<cfloat>

using namespace std;

class points{
public:
	long long int x,y;
};

inline void showpoints(points& a){
	cout<<"("<<a.x<<","<<a.y<<")";
}

inline bool compare(points& a, points& b){
	if(a.x==b.x)
		return a.y<=b.y;
	else
		return a.x<=b.x;
}

inline long long int distance(points& a, points& b){
	/*cout<<"Finding distance between points ";
	showpoints(a);
	cout<<" and ";
	showpoints(b);
	long long d =(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	cout<<" d = sqrt("<<d<<")"<<endl;
	return d;
	*/
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

inline void naive_minimal_distance(points xy[], int l, int r, long long int& d){
	for(int i=l; i<r;++i){
		for(int j=i+1;j<=r;++j){
			d=min(d,distance(xy[i],xy[j]));
		}
	}
}

inline void strip_minimal_distance(points xy[], int l, int r, long long int& d){
	while(l<r){
		for(int i=l+1;i<=r;++i){
			if(abs(xy[i].y-xy[l].y)<d)
				d=min(d, distance(xy[i],xy[l]));
			break;
		}
		++l;
	}
}

inline void minimal_distance(points xy[], int l, int r, long long int& d) {
	if(r-l<=2){
		naive_minimal_distance(xy,l,r,d);
		return;
	}
	int mid=(l+r)/2;
	minimal_distance(xy, l, mid,d);
	minimal_distance(xy, mid, r,d);

	int i=mid-1,j=mid+1;
	while(i>=l){
		if(xy[i].x==xy[mid].x)
			--i;
		break;
	}
	while(j<=r){
		if(xy[j].x==xy[mid].x)
			++j;
		break;
	}
	strip_minimal_distance(xy, i+1, j-1, d);
}

int main() {
  size_t n;
  cin >> n;
  points arr[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> arr[i].x >> arr[i].y;
  }
	sort(arr,arr+n, compare);
	/*cout<<endl<<"After sorting:"<<endl;
	for(size_t i=0;i<n;++i){
		showpoints(arr[i]);
		cout<<endl;
	}
	*/
	long long int d = numeric_limits<long long int>().max();
	minimal_distance(arr,0,n-1,d);
  cout << fixed;
  cout << setprecision(9) << sqrt(d) << "\n";
}
