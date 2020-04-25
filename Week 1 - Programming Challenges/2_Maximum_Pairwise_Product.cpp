#include<iostream>
#include<vector>

using namespace std;

long long maximum_pairwise_product(const vector<int>& v,int& n)
{
	int max1, max2;
	if(v[0]>v[1])
	{
		max1=v[0];
		max2=v[1];
	}
	else
	{
		max1=v[1];
		max2=v[0];
	}
	for(int i=2;i<n;++i)
	{
		if(v[i]>=max1)
		{
			max2=max1;
			max1=v[i];
		}
		else if(v[i]>max2)
		{
			max2=v[i];
		}
	}
	return ((long long) max1)*max2;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];

	cout<<maximum_pairwise_product(v,n);

	return 0;
}
