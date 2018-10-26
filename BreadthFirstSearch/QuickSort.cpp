#include<iostream>
#include<stdio.h>

using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}

	}
	swap(&arr[i+1], &arr[high]);
	return (i + 1);

}

void quickSort(int arr[10], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);

	}
	
}

void printSortedArray(int arr[10], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}



int main()
{
	int arr[10] = {10, 30, 20, 70, 60, 50, 80, 80, 15, 25};

	quickSort(arr, 0, 9);
	cout << "Print Sorted Array" << "\n";
	printSortedArray(arr, 9);
	return 0;

}