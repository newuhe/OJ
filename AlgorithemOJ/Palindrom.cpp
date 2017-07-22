#include <iostream>  
//#include <algorithm>  
#include <string>  
using namespace std;
const int MAX = 100001;
int len, p[2 * MAX];
char str[2 * MAX], newstr[2 * MAX];

void change()
{
	int i;
	newstr[0] = '@';
	newstr[1] = '#';
	for (i = 0; i < len; i++){
		newstr[2 * i + 2] = str[i];
		newstr[2 * i + 3] = '#';
	}
	newstr[2 * len + 2] = '\0';
	return;
}

/*DP*/
void Manacher()
{
	int i, j, id, maxid = 0, ans = 1;
	len = 2 * len + 2;
	for (i = 0; i < len; i++){
		if (maxid > i){
			p[i] = min(p[2 * id - i], maxid - i);
		}
		else{
			p[i] = 1;
		}
		while (newstr[i + p[i]] == newstr[i - p[i]])
			p[i]++;
		if (p[i] + i > maxid){
			maxid = p[i] + i;
			id = i;
		}
		if (ans < p[i])
			ans = p[i];
	}

	for (i = id, j = 0; i < id + ans; i++){
		if (newstr[i] != '#'){
			str[j] = newstr[i];
			j++;
		}
	}
	str[id + ans] = '\0';
	cout << ans - 1<< endl;
	return;
} 


int main()
{
	int number;
	while (cin >> number){
		for (int i=0; i < number; i++){
			cin >> str;
			len = strlen(str);
			change();
			Manacher();
		}
	}
}

//#include <iostream>
//#include <string>
//#include<stdio.h>
//using namespace std;
//
//string longestPalindromeDP(string s) {
//	int n = s.length();
//	int longestBegin = 0;
//	int maxLen = 1;
//	bool table[1000][1000] = { false };
//	for (int i = 0; i < n; i++) {
//		table[i][i] = true;   //前期的初始化
//	}
//	for (int i = 0; i < n - 1; i++) {
//		if (s[i] == s[i + 1]) {
//			table[i][i + 1] = true; //前期的初始化
//			longestBegin = i;
//			maxLen = 2;
//		}
//	}
//	for (int len = 3; len <= n; len++) {
//		for (int i = 0; i < n - len + 1; i++) {
//			int j = i + len - 1;
//			if (s[i] == s[j] && table[i + 1][j - 1]) {
//				table[i][j] = true;
//				longestBegin = i;
//				maxLen = len;
//			}
//		}
//	}
//	return s.substr(longestBegin, maxLen);
//}
//
//int main(){
//	int n;
//	string s;
//	while (cin >> n){
//		for (int i = 0; i < n; i++){
//			cin >> s;
//			cout << longestPalindromeDP(s).length() << endl;
//		}
//	}
//}