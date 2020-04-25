#include <iostream>
#include<cmath>
using namespace std;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){
	n=n+2;
	n=n%60;
	if(n<=1)
		return (n+9)%10;	
	int fab[n+1];
	fab[0]=0;
	fab[1]=1;
	for(int i=2;i<=n;++i){
		fab[i]=(fab[i-1]+fab[i-2])%10;
	}
	return (fab[n]+9)%10;
}


int main() {
    long long n = 0;
    cin >> n;
//	if(fibonacci_sum_naive(n)==fibonacci_sum_fast(n))
    cout << fibonacci_sum_fast(n);
}
