#include <iostream>
using namespace std;

int main()
{
	int number, max,i,j,k,length,begin,end;
	bool flag = true,be=false,en=false;
	int input[200000];
	int *map,*current;
	while (cin >> number >> max)
	{
		length = number;
		for (i = 0; i < number; i++)
		{
			cin >> input[i];
		}
		if (max > number)
		{
			cout << "NO" << endl;
			continue;
		}

		map = new int[max + 1];
		map[0] = 0;
		for (k = 1; k < max + 1; k++)//¹¹Ôì¹þÏ£±í
		{
			map[k] = 1;
		}

		current = new int[200000];
		current[0] = 0;

			for (k = 1; k < max + 1; k++)
			{
				current[k] = 0;
			}

		for (j = 0; j <max; j++)
				{
					for (k = 1; k < max + 1; k++)
					{
						if (input[j] == k) current[k]++;
					}
				}

		for (begin = 0; begin < number - max + 1;begin++,be=true)
		{
			for (end = max +begin - 1; end< number; end++,en=true)
			{
				
				for (k = 1; k < max + 1; k++)
				{
					if (input[begin - 1] ==k && be == true)
					{
						current[k]--;
						be = false;
					}
					if (input[end] == k && en == true)
					{
						current[k]++;
						en = false;
					}
				}
				
					
						
				for (k = 1; k < max + 1; k++)
				{
					if (current[k] < map[k]) flag = false;
				}

				if (flag == true && (end - begin + 1) < length)
				{
					length = end - begin + 1;
				
					break;
				}
				
			}
		}
		if (length == 0) cout << "NO"<<endl;
		else cout << length << endl;
		delete[]current;
		delete[]map;
	}
	return 0;
}