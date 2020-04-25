#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){
	if(n<0)
		return 0;
	n=n+2;
	n=n%60;
	if(n<=1)
		return (n+9)%10;	
	int fab[n+1];
	fab[0]=0;
	fab[1]=1;
	int sum=1;
	for(int i=2;i<=n;++i){
		fab[i]=(fab[i-1]+fab[i-2])%10;
	}
	return (fab[n]+9)%10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to){
	if(to<from)
		return 0;
	else
		return (fibonacci_sum_fast(to)-fibonacci_sum_fast(from-1)+10)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
//	if(get_fibonacci_partial_sum_naive(from,to)==get_fibonacci_partial_sum_fast(from,to))
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
