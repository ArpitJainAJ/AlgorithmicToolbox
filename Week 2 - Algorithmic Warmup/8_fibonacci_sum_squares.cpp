#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n){
	n=n%60;
	if(n<=1)
		return n;	
	int fab[n+1];
	fab[0]=0;
	fab[1]=1;
	int sum=1;		//Initial sum for 60 pairs is 0
	for(int i=2;i<=n;++i){
		fab[i]=(fab[i-1]+fab[i-2])%10;
		sum=(sum+fab[i]*fab[i])%10;
	}
	return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
//	if(fibonacci_sum_squares_naive(n)==fibonacci_sum_squares_fast(n))
    std::cout << fibonacci_sum_squares_fast(n);
}
