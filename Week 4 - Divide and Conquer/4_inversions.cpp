#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

inline void show(int a, int i, int b, int j){
	cout<<"Inversion between "<<a<<"("<<i<<") and "<<b<<"("<<j<<")"<<endl;
}


inline long long merge(vector<int>&a, vector<int>& b,size_t left,size_t mid,size_t right){
	long long count=0;
	//cout<<endl<<"Merging taking place between left:"<<left<<", mid:"<<mid<<" and right:"<<right<<endl;
	size_t i=left, j=mid+1,k=left;
	while((i<=mid)&&(j<=right)){
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else{
			//show(a[i],i,a[j],j);
			b[k++]=a[j++];
			count+=mid-i+1;
		}
	}
	while(k<=right){
		if(i<=mid)
			b[k++]=a[i++];
		else if(j<=right)
			b[k++]=a[j++];
	}
	//cout<<"Total count = "<<count<<" between indices "<< left<<" and "<<right<<endl;
	for(left;left<=right;++left)
		a[left]=b[left];
	return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	/*
	if (left==right) return 0;
	else if (left+1==right){
		if(a[left]>a[right]){
			show(a[left],left,a[right],right);
			b[left]=a[left];
			a[left]=a[right];
			a[right]=b[left];
			return 1;
		}
		else
			return 0;
	}
	*/
	if(left==right)
		return 0;
	else if(left+1==right)
		return merge(a,b,left,left, right);
	size_t mid = (right + left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, mid);
	number_of_inversions += get_number_of_inversions(a, b, mid+1, right);
	number_of_inversions += merge(a, b, left, mid, right);
	return number_of_inversions;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> b(n);
	cout << get_number_of_inversions(a, b, 0, n-1) << '\n';
}
