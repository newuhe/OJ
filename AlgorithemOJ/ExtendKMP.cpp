/* http://blog.csdn.net/dyx404514/article/details/41831947 */

#include <iostream>
#include <cstring>
#include <string>
//using namespace std;

const int maxn = 100000;   //字符串长度最大值  
int next[maxn], extend[maxn]; //ex数组即为extend数组
char S[maxn], T[maxn];

//预处理计算next数组  
void GetNext(char *str)
{
	int i = 0, j, po, len = strlen(str);
	next[0] = len;//初始化next[0]  
	while (str[i] == str[i + 1] && i<len - 1)//初始化next[1]  
		i++;
	next[1] = i;
	po = 1;//初始化po的位置  
	for (i = 2; i<len; i++)
	{
		if (next[i - po] + i - 1 <next[po] + po - 1)//第一种情况，可以直接得到next[i]的值  
			next[i] = next[i - po];
		else//第二种情况，要继续匹配才能得到next[i]的值  
		{
			j = next[po] + po - i;
			if (j<0)j = 0;//如果i>po+next[po],则要从头开始匹配  
			while (i + j<len&&str[j] == str[j + i])//计算next[i]  
				j++;
			next[i] = j;
			po = i;//更新po的位置  
		}
	}
}

//计算extend数组  
void GetExtend(char *s1, char *s2)
{
	int i = 0, j, po, len = strlen(s1), l2 = strlen(s2);
	GetNext(s2);//计算子串的next数组  
	while (s1[i] == s2[i] && i<l2&&i<len)//计算ex[0]  
		i++;
	extend[0] = i;
	po = 0;//初始化po的位置  
	for (i = 1; i<len; i++)
	{
		if (next[i - po] + i<extend[po] + po)//第一种情况，直接可以得到ex[i]的值  
			extend[i] = next[i - po];
		else//第二种情况，要继续匹配才能得到ex[i]的值  
		{
			j = extend[po] + po - i;
			if (j<0)j = 0;//如果i>ex[po]+po则要从头开始匹配  
			while (i + j<len&&j<l2&&s1[j + i] == s2[j])//计算ex[i]  
				j++;
			extend[i] = j;
			po = i;//更新po的位置  
		}
	}
}

int main(){
	int number;
	int result1 = 0, result2 = 0, result3 = 0;
	while (std::cin >> number){
		for (int j = 0; j < number; j++){
			result1 = 0;
			result2 = 0;
			result3 = 0;
			std::cin >> T;
			strcpy(S, T);
			strcat(S, T);
			GetNext(T);
			GetExtend(S, T);
			int Tlen = strlen(T);
			int Slen = strlen(S);
			for (int i = 0; i<Tlen; i++)
			{
				if (extend[i] >= Tlen) result2++;
				else if (S[i + extend[i]]<T[extend[i]]) result1++;
				else result3++;
			}
			std::cout << "Case " << j + 1 << ": " << result1 << " " << result2 << " " << result3 << std::endl;
		}
	}
}