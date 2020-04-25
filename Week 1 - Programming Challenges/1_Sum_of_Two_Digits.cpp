#include<iostream>
using namespace std;

int Sum_of_Two_Digits(int a, int b)
{
	return a+b;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<Sum_of_Two_Digits(a,b);
	return 0;
}
