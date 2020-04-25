#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= a[l]) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int>& a, int l, int r, int& m1, int& m2){
	m1=m2=l;
	for(int i=l+1;i<=r;++i){
		if(a[i]<a[l]){
			++m2;
			swap(a[i],a[m2]);
			++m1;
			swap(a[m1],a[m2]);
		}
		else if(a[i]==a[l]){
			++m2;
			swap(a[i],a[m2]);
		}
	}
	swap(a[l],a[m1]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) return;

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
//	int m = partition2(a, l, r);
	int m1,m2;
	partition3(a,l,r,m1,m2);

//	randomized_quick_sort(a, l, m - 1);
//	randomized_quick_sort(a, m + 1, r);
	randomized_quick_sort(a, l, m1 - 1);
	randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
