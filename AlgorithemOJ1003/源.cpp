/*动态中位数：输入一组整数a1, a2, …, an ，每输入一个整数，输出到此时为止的中位数。中位数定义：如果数串的大小是偶数 2j，中位数是从小到大排列的第 j 个数；如果数串的大小是奇数 2j+1，中位数是从小到大排列的第 j+1 个数。*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class HeapMax{
public:
	HeapMax();
	void PopMax(int &a);
	void PushMax(int a);
	void SiftUp(int length);
	void SiftDown(int start, int m);
	int GetTop();
	int GetNum();
private:
	int length;
	vector<int> heap;
};

HeapMax::HeapMax(){
	length = 0;
	heap.clear();
}

void HeapMax::SiftUp(int length){
	int j = length;
	int i = (j - 1) / 2;
	int temp = heap[j];
	while (j > 0){
		if (heap[i] >= temp) break;
		else{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

void HeapMax::SiftDown(int start, int m){
	int i = start;
	int j = 2 * i + 1;
	int temp = heap[i];
	while (j <= m){
		if (j<m&&heap[j]<heap[j + 1])j++;
		if (temp >= heap[j]) break;
		else{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

void HeapMax::PopMax(int &a){
	a = heap[0];
	heap[0] = heap[length - 1];
	heap.pop_back();
	length--;
	if (length>0) SiftDown(0, length - 1);
}

void HeapMax::PushMax(int a){
	heap.push_back(a);
	SiftUp(length);
	length++;
}

int HeapMax::GetNum(){
	return heap.size();
}

int HeapMax::GetTop(){
	return heap[0];
}

class HeapMin{
public: 
	HeapMin();
	void PopMin(int &a);
	void PushMin(int a);
	void SiftUp(int length);
	void SiftDown(int start,int m);
	int GetTop();
	int GetNum();
private:
	int length;
	vector<int> heap;
};

HeapMin::HeapMin(){
	length = 0;
	heap.clear();
}

void HeapMin::SiftUp(int length){
	int j = length;
	int i = (j - 1) / 2;
	int temp = heap[j];
	while (j > 0){
		if (heap[i] <= temp) break;
		else{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

void HeapMin::SiftDown(int start,int m){
	int i = start;
	int j = 2 * i + 1;
	int temp = heap[i];
	while (j <= m){
		if (j<m&&heap[j]>heap[j + 1])j++;
		if (temp <= heap[j]) break;
		else{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

void HeapMin::PopMin(int &a){
	a = heap[0];
	heap[0] = heap[length - 1];
	heap.pop_back();
	length--;
	if (length>0) SiftDown(0, length - 1);
}

void HeapMin::PushMin(int a){
	heap.push_back(a);
	SiftUp(length);
	length++;
}

int HeapMin::GetNum(){
	return heap.size();
}

int HeapMin::GetTop(){
	return heap[0];
}

int main(){
    HeapMin heapmin;
	HeapMax heapmax;
	int flag = 0,temp;
	int a,length1=0,length2=0,median=-999999;
	while (scanf("%d",&a)!=EOF){
		if (heapmax.GetNum() == 0 && heapmin.GetNum() == 0 && flag == 0) { median = a; flag = 1; printf("%d ", median); continue; }
		if (heapmax.GetNum() == heapmin.GetNum()){
			if (a >= median)
				heapmin.PushMin(a);
			else{
				if (a < heapmax.GetTop()){
					heapmin.PushMin(median);
					heapmax.PopMax(median);
					heapmax.PushMax(a);
				}
				else{
					heapmin.PushMin(median);
					median = a;
				}
			}
		}
		else if (heapmax.GetNum() == (heapmin.GetNum() - 1)){
			if (a > median){
				if (a > heapmin.GetTop()){
					heapmax.PushMax(median);
					heapmin.PopMin(median);
					heapmin.PushMin(a);
				}
				else{
					heapmax.PushMax(median);
					median = a;
				}
			}
			else{
				heapmax.PushMax(a);
			}
		}
		printf("%d ", median);
	}
}