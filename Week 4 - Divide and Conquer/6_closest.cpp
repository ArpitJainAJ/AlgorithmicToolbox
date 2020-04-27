#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include<limits>
#include<cfloat>

using namespace std;

class points{
public:
	int x,y;
};

inline void showpoints(points& a){
	cout<<"("<<a.x<<","<<a.y<<")";
}

inline bool compare(points& a, points& b){
	if(a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}

inline double distance(points&a, points&b){
	/*cout<<"Finding distance between points ";
	showpoints(a);
	cout<<" and ";
	showpoints(b);
	double d = sqrt( pow((double)(a.x-b.x),2) + pow((double)(a.y-b.y),2) );
	cout<<" d= "<<d<<endl;
	return d;
	*/
	return sqrt( pow((double)(a.x-b.x),2) + pow((double)(a.y-b.y),2) );
}

inline double naive_minimal_distance(points xy[], int l, int r){
	//double d=numeric_limits<double>max();
	double d= DBL_MAX;
	for(int i=l; i<r;++i){
		for(int j=i+1;j<=r;++j){
			d=min(d,distance(xy[i],xy[j]));
		}
	}
	return d;
}

inline double strip_minimal_distance(points xy[], int l, int r, double d){
	while(l<r){
		for(int i=l+1;i<=r;++i){
			if(xy[i].y-xy[l].y<d)
				d=min(d, distance(xy[i],xy[l]));
			break;
		}
		++l;
	}
	return d;
}

inline double minimal_distance(points xy[], int l, int r) {
  //write your code here
	if(r-l<=2)
		return naive_minimal_distance(xy,l,r);
	int mid=(l+r)/2;
	double d1=minimal_distance(xy, l, mid);
	double d2=minimal_distance(xy, mid+1, r);
	double d=min(d1, d2);

	int i=mid,j=mid;
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
	return min(d, strip_minimal_distance(xy, i, j, d));
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
  cout << fixed;
  cout << setprecision(9) << minimal_distance(arr,0,n-1) << "\n";
}
