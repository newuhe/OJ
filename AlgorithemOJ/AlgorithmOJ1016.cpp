#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int *array, long low, long high){
	long pivotpos = low, i;
	int pivot = array[low], temp;
	for (i = low + 1; i <= high; i++){
		if (array[i] < pivot){
			pivotpos++;
			if (pivotpos != i){
				temp = array[pivotpos];
				array[pivotpos] = array[i];
				array[i] = temp;
			}
		}
	}
	array[low] = array[pivotpos];
	array[pivotpos] = pivot;
	return pivotpos;

}

void QuickSort(int *array, int low, int high){
	if (low < high){
		long pivotpos = Partition(array, low, high);

		QuickSort(array, low, pivotpos - 1);
		QuickSort(array, pivotpos + 1, high);
	}
}

int search(int *s,int target, int low, int high){
	int coun = 0;
	while (low<high){
		if ((s[low] + s[high]) == target) { coun++; low++; }
		if ((s[low] + s[high]) < target){
			low++;
		}
		else if ((s[low] + s[high]) > target){
			high--;
		}
	}
	return coun;
}

int main(){
	int number, aim, tmp;
	int i;
	while (cin >> number >> aim){
		int count = 0;
		int *s=new int[number];
		for (i = 0; i < number; i++){
			cin >> s[i];
		}
		//QuickSort(s,0,number-1);
		sort(s, s + number);
		for (i = 0; i < number - 2; i++){
			tmp = aim - s[i];
			count += search(s, tmp, i + 1, number - 1);
		}
		delete[]s;
		cout << "wo yi yue du guan yu chao xi de shuo ming"<<endl;
		cout << count << endl;
	}
	return 0;
}

