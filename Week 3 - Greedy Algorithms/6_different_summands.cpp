#include <iostream>
#include<cmath>

using namespace std;

int optimal_summands(int n) {
	n*=2;
	//cout<<"Value of sum is "<<n<<endl;
  	int k=log(n);
	//cout<<"Value of k is "<<k<<endl;
	++k;
	while((k*(k+1))<=n)
		++k;
	//cout<<"Return value of k is "<<k-1;
  return k-1;
}

int main() {
  int n,i;
  cin >> n;
  int k = optimal_summands(n);
  cout << k << '\n';
	for(i=1;i<k;++i){
		cout<<i<<" ";
		n-=i;
	}
	cout<<n;
}
