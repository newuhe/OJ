#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

char a[100];


int ma = 0;

int Count(char * a, int n)
{
	int num[100];
	int  b[100];
	int j = -1;
	int flag = 0;
	int count = 0;
	stack<int> p;
	int i;
	for (i = 0; i < n; i++)//标记
	{
		if (a[i] == '(')
		{
			p.push(i);
			b[i] = 0;
		}
		if (a[i] == ')')
		{
			if (!p.empty())
			{
				b[i] = 1;
				b[p.top()] = 1;
				p.pop();
			}
			else b[i] = 0;
		}
	}
	for (i = 0; i < n; i++)//计数
	{
		if (b[i] == 1 && flag == 1)
		{
			num[j]++;
			flag = 1;
		}
		if (b[i] == 1 && flag == 0)
		{
			j++;
			num[j] = 1;
			flag = 1;
		}
		if (b[i] == 0)
		{
			flag = 0;
		}
	}
	if (j == -1) count = 0;
	else
	{
	sort(num, num + j);
	count = num[j];
    }
	return count;
}


int main()
{
	int count=0;
	while (cin >> a)
	{
		do
		{
			ma++;
		} while (a[ma] != '\0');

	count = Count(a,ma);
	cout << count<<endl;
	}
	return 0;
}