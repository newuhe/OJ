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

//优化版，找到最优相同前后缀长度，但不一定最长；找第一次出现更快，但不能找重复次数
///* P为模式串，下标从0开始 */
//void GetNextval(string P, int nextval[])
//{
//	int p_len = P.size();
//	int i = 0;   //P的下标
//	int j = -1;
//	nextval[0] = -1;
//
//	while (i < p_len)
//	{
//		if (j == -1 || P[i] == P[j])
//		{
//			i++;
//			j++;
//			if (P[i] != P[j])             //防止相同的字符在kmp中再进行比较
//				nextval[i] = j;
//			else
//				nextval[i] = nextval[j];  //既然相同就继续往前找前缀
//		}
//		else
//			j = nextval[j];
//	}
//}


/*next[i] stores the length of common subarray of first i elements*/
void getnext(int lenW)
{
	int i = 0, j = -1;
	Next[i] = -1;
	while (i<lenW) {
		if (j == -1 || W[i] == W[j]) {
			++i;
			++j;
			Next[i] = j;
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




