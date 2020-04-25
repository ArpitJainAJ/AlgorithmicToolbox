#include <iostream>

int get_coins (int& n,int r){
	int count=0;
	while(n>=r){
		n-=r;
		count++;
	}
	return count;
}
int get_change(int m) {
  return get_coins(m,10)+get_coins(m,5)+get_coins(m,1);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
