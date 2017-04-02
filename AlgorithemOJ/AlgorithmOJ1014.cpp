#include <iostream>
#include <string>
using namespace std;

long result;

void Merge(string *array,string *temp,int low,int mid,int high){
	int index1 = mid,index2=high,index3=high;
	while (index1>(low-1)&&index2>mid){
			if (array[index1]>array[index2]){
				temp[index3] = array[index1];
				index1--;
				index3--;
				result+=index2-mid;
			}
			else{
				temp[index3] = array[index2];
				index2--;
				index3--;
			}
	}
	while (index1>=low){
		temp[index3] = array[index1];
		index1--;
		index3--;
		}
	while (index2>=mid+1){
		temp[index3] = array[index2];
		index2--;
		index3--;
	}
	for (int i = low; i < high + 1;i++){
		array[i] = temp[i];
	}
}

void Inversion(string * array,string*temp,int low,int high){
	if (low == high) return;
	int mid;
	mid= (low + high) / 2;
	Inversion(array,temp, low, mid);
	Inversion(array, temp,mid + 1, high);
	Merge(array,temp,low,mid,high);
}



int main(){
	long  num;
	while (cin >> num){
		result = 0;
		string *array= new string[num];
		string *temp = new string[num];
		for (int i = 0; i < num; i++){
			cin >> array[i];
			temp[i] = array[i];
		}
		Inversion(array,temp,0,num-1);
		cout << "wo yi yue du guan yu chao xi de shuo ming"<<endl;
		cout << result<<endl;
	}
	system("pause");
}