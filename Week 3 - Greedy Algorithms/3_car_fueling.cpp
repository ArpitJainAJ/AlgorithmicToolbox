#include <iostream>
#include <vector>
using namespace std;


int compute_min_refills(int tank, vector<int> & stops,int n) {
    int refills=0, last_refill=0, current_refill=0;
	while(current_refill<=n){
		last_refill=current_refill;
		while((stops[current_refill+1]-stops[last_refill]<=tank)&&(current_refill<=n)){
			++current_refill;
		}
		if(current_refill==last_refill){
			return -1;
		}
		if(current_refill<=n){
			refills++;
		}
		//cout<<"Refill Station: "<<last_refill<<endl;
	}
    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
	stops[0]=0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops[i];
	stops[n+1]=d;

    cout << compute_min_refills(m, stops,n) << "\n";

    return 0;
}
