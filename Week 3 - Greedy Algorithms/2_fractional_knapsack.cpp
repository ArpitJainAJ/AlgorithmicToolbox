#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

double get_optimal_value(int capacity, priority_queue <pair<double,pair<int,int>>>& data) {
  double value = 0.0;

  while((capacity!=0)&&(!data.empty())){
	pair<double,pair<int,int>> topdata=data.top();
	pair<int,int> top=topdata.second;
	int wneed=min(top.second,capacity);
	value+=(topdata.first)*wneed;
	capacity-=wneed;
	data.pop();
	}
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
	priority_queue <pair<double,pair<int,int>>> data;
//  vector<int> values(n);
//  vector<int> weights(n);
	int values,weights;
  for (int i = 0; i < n; i++) {
    cin >> values >> weights;
	data.push(make_pair(((double)values)/weights,make_pair(values,weights)));
  }

  double optimal_value = get_optimal_value(capacity, data);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
