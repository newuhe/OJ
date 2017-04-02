#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
 
int main()
{
	int b;
	string s;
	vector<int> a;
	int i = 0,j=0,k;
	while (cin>>s)
	{
		
		istringstream is(s);
		int inter;
		char ch;
		while (is >> inter)
		{
			a.push_back(inter);
			is >> ch;
		}
		j = a.size();
		cin >> b;

		int mid, left, right;
		left = 0;
		right = j - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (a[mid] == b) //如果数组中已有此值，就在原位置插入  
			{
				left = mid;
				break;
			}
			else if (a[mid] > b)
				right = mid - 1;
			else
				left = mid + 1;
		}

		cout << left<<endl;
		a.clear();
	}
	return 0;
}