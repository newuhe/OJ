#include <iostream>
using namespace std;

void find(int num, int *a,int low,int high)
{
	if (low >= high) return;
	int m = a[low] + a[high];
	if (m == num)
	{
		cout << a[low] << " " << a[high] << endl;
		find(num, a, low + 1, high - 1);
	}
	if (m > num) find(num, a, low, high - 1);
	if (m < num) find(num, a, low + 1, high);
}

int main()
{
	int n, num,i;
	cin >> n;
	int *a = new int[n];
	for (i = 0; i < n; i++) cin >> a[i];
	cin >> num;
	find(num,a,0,n-1);
}