/* http://blog.csdn.net/dyx404514/article/details/41831947 */

#include <iostream>
#include <cstring>
//using namespace std;

const int maxn = 100000;   //�ַ����������ֵ  
int next[maxn], extend[maxn]; //ex���鼴Ϊextend����

//Ԥ�������next����  
void GETNEXT(char *str)
{
	int i = 0, j, po, len = strlen(str);
	next[0] = len;//��ʼ��next[0]  
	while (str[i] == str[i + 1] && i + 1<len)//��ʼ��next[1]  
		i++;
	next[1] = i;
	po = 1;//��ʼ��po��λ��  
	for (i = 2; i<len; i++)
	{
		if (next[i - po] + i<next[po] + po)//��һ�����������ֱ�ӵõ�next[i]��ֵ  
			next[i] = next[i - po];
		else//�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ  
		{
			j = next[po] + po - i;
			if (j<0)j = 0;//���i>po+next[po],��Ҫ��ͷ��ʼƥ��  
			while (i + j<len&&str[j] == str[j + i])//����next[i]  
				j++;
			next[i] = j;
			po = i;//����po��λ��  
		}
	}
}

int main(){
	int number;
	while (std::cin >> number){

	}
}