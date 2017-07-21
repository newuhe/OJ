#include<iostream>
#include<string>
#include<vector>
#include<cstdio>  
#include<cstring> 
using namespace std;
const int MAXW = 10001, MAXT = 1000001;
char W[MAXW], T[MAXT];
int Next[MAXW] = {0};
int lenW, lenT;


/*next[i] stores the length of common subarray of first i elements*/
void getnext(int lenW)
{
	int i = 0, j = -1;
	Next[i] = -1;
	while (i<lenW) {
		if (j == -1 || W[i] == W[j]) {
			Next[++i] = ++j;
		}
		else j = Next[j];
	}
}
/*KMP to count appearing times*/
int kmp(int pos, int lenW, int lenT)
{
	int i = pos, j = 0, ans = 0;
	while (i<lenT) {
		if (T[i] == W[j] || j == -1) ++i, ++j;
		else j = Next[j];
		if (j == lenW) {
			ans++;
			j = Next[j - 1];
			i--;
		}
	}
	return ans;
}

int main()
{
	int n;
	while (cin >> n){
		while (n--) {
			cin >> W;
			cin >> T;
			lenW = strlen(W);
			lenT = strlen(T);
			getnext(lenW);
			printf("%d\n", kmp(0, lenW, lenT));
		}
	}
	return 0;
}




