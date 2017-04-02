#include <iostream>
using namespace std;

int main()
{
	int allweigh,a;
	int weigh[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		weigh[i] = 0;
	}
	while (cin >> allweigh)
	{
		a = allweigh - 265716;
		for (i = 0; i < 10; i++)
		{
			if (i < 9)
			{
				weigh[i] = a % 3;
				cout << weigh[i]+9 << " ";
			}
			if (i == 9)
			{
				weigh[i] = a % 3;
				cout << weigh[i] + 9 << endl;
			}
			a = int(a / 3);
		}
	
	}

	return 0;

}