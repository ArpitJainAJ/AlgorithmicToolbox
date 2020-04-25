#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long max_dot_product(priority_queue <int>& a, priority_queue <int>& b) {
  // write your code here
  long long result = 0;
	while(!a.empty()){
		result += ((long long) a.top()) * b.top();
		a.pop();
		b.pop();
  }
  return result;
}

int main() {
  size_t n;
	int x;
  std::cin >> n;
  priority_queue <int> a, b;
  for (size_t i = 0; i < n; i++) {
    cin >> x;
	a.push(x);
  }
  for (size_t i = 0; i < n; i++) {
    cin >> x;
	b.push(x);
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
