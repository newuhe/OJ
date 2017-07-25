/* http://blog.csdn.net/dyx404514/article/details/41831947 */

#include <iostream>
#include <cstring>
//using namespace std;

const int maxn = 100000;   //字符串长度最大值  
int next[maxn], extend[maxn]; //ex数组即为extend数组

//预处理计算next数组  
void GETNEXT(char *str)
{
	int i = 0, j, po, len = strlen(str);
	next[0] = len;//初始化next[0]  
	while (str[i] == str[i + 1] && i + 1<len)//初始化next[1]  
		i++;
	next[1] = i;
	po = 1;//初始化po的位置  
	for (i = 2; i<len; i++)
	{
		if (next[i - po] + i<next[po] + po)//第一种情况，可以直接得到next[i]的值  
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

int main(){
	int number;
	while (std::cin >> number){

	}
}