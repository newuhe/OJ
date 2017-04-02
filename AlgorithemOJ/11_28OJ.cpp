#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	string a;
	int value[256];
	value['I'] = 1;
	value['V'] = 5;
	value['X'] = 10;
	value['L'] = 50;
	value['C'] = 100;
	value['D'] = 500;
	value['M'] = 1000;
	
	while (cin >> a)
	{
		int number=0;
		for (int i = 0; i < a.length(); i++)
		{
			if (i==(a.length()-1)||value[a[i]]>=value[a[i+1]])
				number += value[a[i]];
			else
				number -= value[a[i]];
		}
		cout << number << endl;
	}
	return 0;
}