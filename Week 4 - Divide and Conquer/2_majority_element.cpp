#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(int a[], int n) {
	int count=1,element=a[0],count_max=n/2+1;
	for(int i=1;i<n;++i){
		if(a[i]!=element){
			element=a[i];
			count=1;
		}
		else{
			++count;
			if(count==count_max)
				return a[i];
		}
	}
	return -1;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; ++i) {
    cin >> a[i];
  }
	sort(a,a+n);
  cout << (get_majority_element(a, n) != -1) << '\n';
}
