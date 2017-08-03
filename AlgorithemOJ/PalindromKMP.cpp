#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int* getnext(string s){
	int *next = new int(s.length());
	next[0] = -1;
	int j = -1;
	for (int i = 1; i < s.length(); i++){
		while (j >= 0 && s[i] != s[j + 1]){
			j = next[j];
		}
		if (s[i] == s[j + 1])
			j++;
		next[i] = j;
	}
	return next;
}

int main(){
	string s;
	std::cin >> s;
	int *next = getnext(s);
	int k = s.length()-1 - next[s.length()-1];
	if (k != 1 && s.length() % k == 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
//int visited[100][100] ={0};
//int graph[100][100] = { 0 };
//
//int GetAmountOfIslands(int n, int m)
//{
//
//	int count = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j<m; j++)
//		{			
//			if (graph[i][j] == 1 && visited[i][j] == 0){
//				if ((graph[i + 1][j] == 1 && visited[i + 1][j] == 0) || (graph[i][j + 1] == 1 && visited[i][j + 1] == 0)){
//					visited[i + 1][j] == 1;
//					visited[i][j+1] == 1;
//					count++;
//				}
//			}
//			visited[i][j] = 1;
//		}
//	return count;
//}
//
//int main(){
//	int n, m;
//	while (cin >> n >> m){
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				cin >> graph[i][j];
//		cout << GetAmountOfIslands(n, m) << endl;
//	}
//}

//int partition(int *a,int low,int high){
//	int pivotpos=low;
//	int pivot = a[low];
//	for (int i = low + 1; i <= high; i++){
//		if (pivot > a[i]){
//			pivotpos++;
//			if (pivotpos != i){
//				int temp = a[pivotpos];
//				a[pivotpos] = a[i];
//				a[i] = temp;
//			}
//		}
//	}
//	a[low] = a[pivotpos];
//	a[pivotpos] = pivot;
//	return pivotpos;
//}
//
//void quicksort(int *a, int low, int high){
//	if (low<high){
//		int pivotpos = partition(a,low,high);
//		quicksort(a, low, pivotpos - 1);
//		quicksort(a, pivotpos + 1, high);
//	}
//}

/*while (fgets(input, 10000, stdin)){
num = strtok(input, " ");
number = atoi(num);
v[vertice_num].push_back(number);
while (num = strtok(NULL, " ")){
if (strcmp(num, "\n")){
number = atoi(num);

}
}

}*/


//³ýÈ¥¿Õ¸ñ
//void s(string test){
//	string result = "";
//	for (int i = 0; test[i] != '\0'; i++)
//	{
//		if (test[i] != ' ')
//			result.append(1, test[i]);
//		else
//			if (test[i + 1] != ' ')
//				result.append(1, test[i]);
//	}
//	cout << result;
//}
