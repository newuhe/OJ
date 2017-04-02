#include <iostream>
using namespace std;

int main()
{
	int number, i, j[100][4];
	int local[4], subnet[4],add[4], ip0[100], ip1[100], ip2[100], ip3[100];
	char a;
	cin >> local[0] >> a >> local[1] >> a >> local[2] >> a >> local[3];
	cin >> subnet[0] >> a >> subnet[1] >> a >> subnet[2] >> a >> subnet[3];
	cin >> number;
	add[0] = local[0] & subnet[0];
	add[1] = local[1] & subnet[1];
	add[2] = local[2] & subnet[2];
	add[3] = local[3] & subnet[3];
	for (i = 0; i < number; i++)
	{
		cin >> ip0[i] >> a >> ip1[i] >> a >> ip2[i] >> a >> ip3[i];
		j[i][0] = subnet[0] & ip0[i];
		j[i][1] = subnet[1] & ip1[i];
		j[i][2] = subnet[2] & ip2[i];
		j[i][3] = subnet[3] & ip3[i];		
	}
	for (i = 0; i < number;i++)
	{
		if ((j[i][0] == add[0]) && (j[i][1] == add[1]) && (j[i][2] == add[2]) && (j[i][3] == add[3])) cout << "INNER" << endl;
		else cout << "OUTER" << endl;
	}
	system("pause");
	return 0;
}