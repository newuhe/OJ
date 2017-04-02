#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int number,i,j,maxvalue;
	static int value[2002],sum[2002],f[2002][2002];
	sum[0] = 0;
	cin >> number;

	for (i = 1; i <= number; i++)
	{	
		cin >> value[i];
		
	}
	
	for (i = 1; i <= number; i++)
	{
		sum[i] = sum[i - 1] + value[number - i + 1];
	}
	
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number; j++)
		{
			f[i][j] = f[i][j - 1];//利用动态规划减少一重循环
			if (i - (j * 2)>=0)
				f[i][j] = max(f[i][j], sum[i] - f[i - (j * 2)][j * 2]);
			if (i - (j * 2)+1>= 0)
				f[i][j] = max(f[i][j], sum[i] - f[i - (j * 2) + 1][(j * 2) - 1]);
		}
	}
	cout << f[number][1];
	system("pause");
	return 0;
}