/*联合中位数：给出两个长度为n的数组A1,A2,...An, B1,B2,...Bn,所有2n个数互不相同，并且数组A和数组B按照升序排列。要求找出这2n个数的中位数。中位数的定义和之前相同。*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(){
	int num,i,median,left1,right1,left2,right2,mid1,mid2,temp1,temp2;
	while (scanf("%d", &num)!=EOF){
		int *array1, *array2;
		array1 = new int[num];
		array2 = new int[num];
		for (i = 0; i < num; i++){
			scanf("%d", &array1[i]);
		}
		for (i = 0; i < num; i++){
			scanf("%d", &array2[i]);
		}
		left1 = left2 = 0;
		right1 = right2 = num - 1;
		if (num == 1){
				median = array1[0] < array2[0] ? array1[0] : array2[0];
		}
		while (right1>left1&&right2>left2){
			if (left1 == (right1 - 1) && left2 == (right2 - 1)){
				if (array1[left1] < array2[left2])
				{
					median = array1[right1]<array2[left2] ? array1[right1]:array2[left2];
				}
				else
				{
					median = array1[left1]<array2[right2] ? array1[left1] : array2[right2];
				}
				break;
			}
			else{
				mid1 = (left1 + right1)>>1;
				mid2 = (left2 + right2)>>1;
				if (array1[mid1] < array2[mid2]){
					if ((left1 + right1 + 1) % 2 == 0&&(left2 + right2 + 1) % 2 == 0){
						left1 = mid1+1;
						right2 = mid2;
					}
					else{
						left1 = mid1;
						right2 = mid2;
					}
				}
				else{
					if ((left1 + right1 + 1) % 2 == 0 && (left2 + right2 + 1) % 2 == 0){
						right1 = mid1 ;
						left2 = mid2+1;
					}
					else{
						right1 = mid1;
						left2 = mid2;
					}
				}
			}
		}
		free(array1);
		free(array2);
		printf("%d\n", median);
	}
}