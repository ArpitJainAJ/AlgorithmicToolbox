#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, long long> p;

vector<int> optimal_points(priority_queue <p,vector<p>,greater<p>>& segments) {
  vector<int> points;
	p top,current;
	long long stop_point;
	while(!segments.empty()){
		top=segments.top();
		segments.pop();
		points.push_back(top.first);
		//cout<<"Pushing value "<<top.first<<endl;
		stop_point=top.second;
		for(long long i=top.first;i<=stop_point;++i){
			//cout<<endl<<"Internal loop working for i="<<i<<endl;
			while(!segments.empty()){
				current=segments.top();
				if(current.first==i){
					stop_point=min(stop_point,current.second);
					segments.pop();
					//cout<<"Poping value "<<*(points.end())<<endl;
					points.pop_back();
					points.push_back(i);
					//cout<<"Pushing new value "<<i<<endl;
				}
				else{
					//cout<<"No more segment match for i="<<i<<endl;
					break;
				}
			}
			if(segments.empty()){
				//cout<<"Exit area 2";
				return points;
			}
		}
	}
	//cout<<"Exit Area 1";
  return points;
}

int main() {
  int n;
  std::cin >> n;
  //vector<Segment> segments(n);
	priority_queue <p,vector<p>,greater<p>> segments;
	long long start, end;
  for (size_t i = 0; i < n; ++i) {
    cin >> start >> end;
	segments.push(make_pair(start,end));
  }
  vector<int> points = optimal_points(segments);
	int m=points.size();
  cout << m << "\n";
  for (size_t i = 0; i < m; ++i) {
    cout << points[i] << " ";
  }
}
