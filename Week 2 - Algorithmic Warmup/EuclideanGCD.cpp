#include<iostream>

using namespace std;

int EuclidGCD(int a, int b)
{
	if(b==0)
		return a;
	else
		return EuclidGCD(b,a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<EuclidGCD(a,b);

return 0;
}
