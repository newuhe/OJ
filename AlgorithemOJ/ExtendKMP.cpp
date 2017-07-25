/* http://blog.csdn.net/dyx404514/article/details/41831947 */

#include <iostream>
#include <cstring>
#include <string>
//using namespace std;

const int maxn = 100000;   //�ַ����������ֵ  
int next[maxn], extend[maxn]; //ex���鼴Ϊextend����
char S[maxn], T[maxn];

//Ԥ�������next����  
void GetNext(char *str)
{
	int i = 0, j, po, len = strlen(str);
	next[0] = len;//��ʼ��next[0]  
	while (str[i] == str[i + 1] && i<len - 1)//��ʼ��next[1]  
		i++;
	next[1] = i;
	po = 1;//��ʼ��po��λ��  
	for (i = 2; i<len; i++)
	{
		if (next[i - po] + i - 1 <next[po] + po - 1)//��һ�����������ֱ�ӵõ�next[i]��ֵ  
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

//����extend����  
void GetExtend(char *s1, char *s2)
{
	int i = 0, j, po, len = strlen(s1), l2 = strlen(s2);
	GetNext(s2);//�����Ӵ���next����  
	while (s1[i] == s2[i] && i<l2&&i<len)//����ex[0]  
		i++;
	extend[0] = i;
	po = 0;//��ʼ��po��λ��  
	for (i = 1; i<len; i++)
	{
		if (next[i - po] + i<extend[po] + po)//��һ�������ֱ�ӿ��Եõ�ex[i]��ֵ  
			extend[i] = next[i - po];
		else//�ڶ��������Ҫ����ƥ����ܵõ�ex[i]��ֵ  
		{
			j = extend[po] + po - i;
			if (j<0)j = 0;//���i>ex[po]+po��Ҫ��ͷ��ʼƥ��  
			while (i + j<len&&j<l2&&s1[j + i] == s2[j])//����ex[i]  
				j++;
			extend[i] = j;
			po = i;//����po��λ��  
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