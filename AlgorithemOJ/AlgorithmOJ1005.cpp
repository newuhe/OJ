#include <iostream>
#include <string>
using namespace std;

struct Map
{
	string key;
	string value;
};

int Key_Partition(Map *array,long low,long high){
	long pivotpos = low, i;
	Map pivot = array[low];
	Map temp;
	for (i = low + 1; i <= high; i++){
		if (array[i].key < pivot.key){
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

void Key_Sort(Map *array, long low, long high){
	if (low < high){
		long pivotpos = Key_Partition(array, low, high);

		Key_Sort(array, low, pivotpos - 1);
		Key_Sort(array, pivotpos + 1, high);
	}
}


int Letter_Partition(string &array, long low, long high){
	long pivotpos = low, i;
	char pivot = array[low];
	char temp;
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

void Letter_Sort(string &array,int low,int high){
	if (low < high){
		long pivotpos = Letter_Partition(array, low, high);

		Letter_Sort(array, low, pivotpos - 1);
		Letter_Sort(array, pivotpos + 1, high);
	}
}


int Part_Partition(Map *array, long low, long high){
	long pivotpos = low,i;
	Map pivot = array[low],temp;
	for (i = low + 1; i <= high; i++){
		if (array[i].value < pivot.value){
			pivotpos++;
			if (pivotpos != i){
				temp = array[pivotpos];
				array[pivotpos] = array[i];
				array[i] = temp;
			}
		}
	}
		array[low]= array[pivotpos];
		array[pivotpos] = pivot;
		return pivotpos;
	
}

void Part_Sort(Map *array, long low, long high){
	if (low < high){
		long pivotpos = Part_Partition(array,low,high);

		Part_Sort(array, low, pivotpos-1);
		Part_Sort(array, pivotpos+ 1, high);
	}
}

int Value_Partition(string *array, long low, long high){
	long pivotpos = low, i;
	string pivot = array[low], temp;
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

void Value_Sort(string *array, long low, long high){
	if (low < high){
		long pivotpos = Value_Partition(array, low, high);

		Value_Sort(array, low, pivotpos - 1);
		Value_Sort(array, pivotpos + 1, high);
	}
}

int main(){
	long num, result,count;
	
	while (cin >> num){
		result = 0;
		count = 0;
		Map *array = new Map[num];
		string *res = new string[num];
		for (long i = 0; i < num; i++){
			cin >> array[i].value;
			array[i].key = array[i].value;
			Letter_Sort(array[i].key,0,array[i].key.length()-1);
		}
		Key_Sort(array,0,num-1);


		for (int i = 0; i < num; i++) cout << array[i].key<<" ";
		cout << endl;
		for (int i = 0; i < num; i++) cout << array[i].value << " ";
		cout << endl;


		cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
		
		long low = 0, high = 1;
		while (high < num){
			if (array[low].key == array[high].key && high == (low + 1)) {
				result++;
				high++;
				count++;
				continue;
			}
			if (array[low].key == array[high].key && high > (low + 1)){ 
				high++;
				count++;
				continue;
			}
			if (array[low].key != array[high].key) {
				if (count > 0){
					Part_Sort(array, low, high - 1);
					res[result-1] = array[low].value;
				}
				
				low = high;
				high++;
				count = 0;
			}
		}
		if (count > 0) res[result-1] = array[num - 1].value;

		Value_Sort(res,0,result-1);
		cout << result<<endl;
		for (int i = 0; i < result; i++) cout << res[i] << endl;
	}
}