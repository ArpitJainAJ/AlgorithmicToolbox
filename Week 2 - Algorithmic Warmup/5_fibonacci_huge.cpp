//pisano perios
#include <iostream>

long long get_pisano_period(long long m){
	long long fab[m*m],max=m*m;
	fab[0]=0;
	fab[1]=1;
	fab[2]=1;
	for(long long i=3;i<=max;++i){
		fab[i]=(fab[i-1]+fab[i-2])%m;
		if((fab[i]==1)&&(fab[i-1]==0))
			return i-1;
	}
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
	n=n%get_pisano_period(m);
//	std::cout<<"Later pp: "<<get_pisano_period(m);
	if(n<=1)
		return n;
	long long int fab[n+1];
	fab[0]=0;
	fab[1]=1;
	for(long long i=2;i<=n;++i){
		fab[i]=(fab[i-1]+fab[i-2])%m;
	}
	return fab[n];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
//	if(get_fibonacci_huge_naive(n,m)==get_fibonacci_huge_fast(n,m))
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
