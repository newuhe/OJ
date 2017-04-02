#include <iostream> 
using namespace std;
int partition(int *list,int low, int high)
{
	int i,temp;
	int flag = low;
	int pivot=list[low];
	for (i = low + 1; i <= high; i++)
	{
		if (list[i] < pivot)
		{
			flag++;
			temp = list[i];
			list[i] = list[flag];
			list[flag] = temp; 
		}
	}
	list[low] = list[flag];
	list[flag] = pivot;
	return flag;
}
void quicksort(int *list, int low, int high)
{
	if (low < high)
	{
		int mid = partition(list, low, high);
		quicksort(list, low, mid);
		quicksort(list, mid + 1, high);
	}
}



int main(){
	int k,n,mid,i;
	while (cin >> k >> n)
	{
		if (n % 2==0) mid = n/2 - 1;
		else mid = (n - 1) / 2;
		int *num = new int[n];
		for (i = 0; i < n; i++) cin >> num[i];
		quicksort(num,0,n-1);
		for (i = k+1; i >1 ; i--) cout << num[mid -i+1 ]<<" ";
		cout << num[mid] << " ";
		for (i = 1; i < k; i++) cout << num[mid+i]<<" ";
		cout << num[mid + k] << endl;
	}
	return 0;
}