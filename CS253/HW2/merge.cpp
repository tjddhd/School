//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 2
//merge.cpp

#include <iostream>
#include "merge.h"

//Purpose: Merges 2 halves of a subarray arr
//Pre: An integer array, arr and beginning p, midpoint q, and endpoint r
//Post: A merged subarray arr
void merge(int arr[], int p, int q, int r)
{
	//original code that was eventually abandoned
	/*const int num1 = q - p +1;
	const int num2 = r - q;
	int left[10000];
	int right[10000];

	for(int i = 1; i < num1; i++)
		left[i] = arr[p + i - 1];
	for(int j = 1; j < num2; j++)
		right[j] = arr[q + j];
	left[num1+1] = 5000000;
	right[num2+1] = 5000000;
	int k = 1, l =1;
	for(int m = p; m < r; m++)
	{
		if(left[k] <= right[l])
		{
			arr[m] = left[k];
			k++;
		}
		else
		{
			arr[m] = right[l];
			l++;
		}

	}*/

	//Assert A [p..q] is in increasing order
	int left_end = q-1, num_elem = r-p+1, tmp_pos = p, temp[10000];

	while((p <= left_end)&&(q<=r))
	{
		if(arr[p] <= arr[q])
		{
			temp[tmp_pos] = arr[p];
			tmp_pos++;
			p++;
		}
		else
		{
			temp[tmp_pos] = arr[q];
			tmp_pos++;
			q++;
		}
	}

	while(p <= left_end)
	{
		temp[tmp_pos] = arr[p];
		p++;
		tmp_pos++;
	}

	while(q <= r)
	{
		temp[tmp_pos] = arr[q];
		q++;
		tmp_pos++;
	}

	for(int j =0; j <= num_elem; j++)
	{
		//Assert A [p..q] is in increasing order && j<=num_elem
		arr[r] = temp[r];
		r--;
		//Assert A [p..q] is in increasing order
	}
	//Assert A [p..q] is in increasing order && j>num_elem
}

//Purpose: Sorts an array of size r
//Pre: An integer array, arr
//Post: A permutation of arr such that it is now in increasing order
void mergeSort(int arr[], int p, int r)
{
	if(r > p)
	{
		int q = (r+p)/2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}
