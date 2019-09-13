/*
 * Sorts.hpp
 *
 *  Created on: Feb 6, 2012
 *      Author: Thomas Dolan
 */

#ifndef SORTS_HPP_
#define SORTS_HPP_
#include<stdexcept>

	//Desc: Sorts a set of data through use of the insertion sort method
	//Parameters: An array of integers, data, and the size of the array, length
	//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2
	//Post: A permutation of 'data' that is an array ordered in ascending value of distinct
	//      comparable integers for the array of length <= 2
	void Sorts::insertionSort(int data[], int length)
	{
		int temp=0, j=0, i =0;

		//Invariant: The subarray data[1...j-1]is sorted in ascending order
		sortTrue = insertionInvariant(data, j);
		for(i = 1; i < length; i++)
		{
			//Invariant: The subarray data[1...j-1]is sorted in ascending order && i<length
			sortTrue = insertionInvariant(data,j) &&(i<length);
			temp = data[i];
			
			j = i-1;

			while(j>=0 && data[j] > temp)
			{
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
				j = j-1;
			}
		}
		//Invariant: The subarray data[1...j]is sorted in ascending order && i=length
		sortTrue = insertionInvariant(data, j) && (i>=length);
	}


	//Desc: Sorts a set of data through use of the merge sort method
	//Parameters: An array of integers, data, the initial point from which the set to be
	//            compared will begin at, start, and the final point from which the set to
	//            be compared will end at, end
	//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2,
	//     end > start
	//Post: A permutation of 'data' that is an array ordered in ascending value of distinct
	//      comparable integers for the array of length <= 2
	void Sorts::mergeSort(int data[], int start, int end)
	{
		if(start < end)
		{
			int midpoint = (start + end)/2;
			mergeSort(data, start, midpoint);
			mergeSort(data, midpoint +1, end);
			Sorts::merge(data, start, midpoint, end);
		}
	}



	//Desc: Merges the set of between 'start' and 'end' into ascending order
	//Parameters: An array of integers, data, the initial point from which the set to be
	//            merged will begin at, start, the rounded down midpoint of the set to be
	//            merged, and the final point from which the set to be merged will end at,
	//            end
	//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2,
	//     end > start, midpoint > start, data[start...midpoint] & data[midpoint+1....end]
	//     are sprted and permuted into ascending order
	//Post: A permutation of 'data' that has the elements between the 'start' and the 'end'
	//      merged into ascending order
	void Sorts::merge(int data[], int start, int midpoint, int end)
	{
		int leftSentinel = midpoint - start + 1;
		int rightSentinel = end - midpoint;
		int* left;
		int* right;

		try
		{
			left = new int[leftSentinel+1];
			right = new int[rightSentinel+1];
		}
		catch(std::bad_alloc& e)
		{
			throw e;
		}

		int i = -1, j = -1;
		//Invariant: left[0...i] corresponds to the values of data[start...leftSentinel]
		sortTrue = Sorts::leftInvariant(data, left, i);
		for(i = 0; i < leftSentinel; i++)
		{
			//Invariant: left[0...i] corresponds to the values of data[start...leftSentinel] && i < leftSintinel
			sortTrue = leftInvariant(data, left, i) && (i<leftSentinel);
			left[i] = data[start+i-1];
		}
		//Invariant: left[0...i] corresponds to the values of data[start...leftSentinel] && i = leftSentinel
		sortTrue = leftInvariant(data, left, i) && (i>=leftSentinel);


		//Invariant: right[0...i] corresponds to the values of data[midpoint...rightSentinel]
		sortTrue = Sorts::rightInvariant(data, right, midpoint, j);
		for(j = 0; j < rightSentinel; j++)
		{
			//Invariant: right[0...i] corresponds to the values of data[midpoint...rightSentinel] && j < rightSentinel
			sortTrue = rightInvariant(data, right, midpoint, j) && (j < rightSentinel);
			right[j] = data[midpoint+j];
		}
		//Invariant: right[0...i] corresponds to the values of data[midpoint...rightSentinel] && j = rightSentinel
		sortTrue = rightInvariant(data, right, midpoint, j) && (j >= rightSentinel);


		left[leftSentinel+1] = -1;
		right[rightSentinel+1] = -1;
		i = j = 1;
		int k = -1;

		//Invariant: data[0...k] will be permuted into ascending order
		sortTrue = Sorts::mergeInvariant(data,start, k);
		for(k = start; k < end; k++)
		{
			//Invariant: data[0...k] will be permuted into ascending order && k < end
			sortTrue = mergeInvariant(data,start, k) && (k<end);
			if(left[i] <= right[j])
			{
				data[k] = left[i];
				i++;
			}
			else
			{
				data[k] = right[j];
				j++;
			}
		}
		//Invariant: data[0...k] will be permuted into ascending order && k = end
		sortTrue = mergeInvariant(data,start, k) && (k>=end);
	}


	//Desc: Shows that the loop for insertion sort is right at all points during runtime
	//Parameters: An array of integer, data, and the endpoint for which the set has sorted
	//            for
	//Pre: 'data' is a set of distinct comparable integers
	//Post: Returns the truth value of the sort sequence up to that point
	bool Sorts::insertionInvariant(int data[], int endpoint)
	{
		bool isTrue = true;
		for(int i = 1; i < endpoint; i++)
		{
			isTrue = (data[i-1] < data[i]);
		}
		return isTrue;
	}


	//Desc: Shows that the loop for merge sort is right at all points during runtime
	//Parameters: An array of integer, data, and the endpoint for which the set has sorted
	//            for
	//Pre: 'data' is a set of distinct comparable integers
	//Post: Returns the truth value of the sort sequence up to that point
	bool Sorts::mergeInvariant(int data[], int start, int endpoint)
	{
		bool isTrue = true;
		for(int i = start; i < endpoint; i++)
		{
			isTrue = (data[i-1] < data[i]);
		}
		return isTrue;
	}


	//Desc: Shows that the loop for left portion of the array to be merged is permuted into
	//      ascending order
	//Parameters: An array of integer, data, an array of integers, left, and the endpoint
	//            for which the set has sorted for
	//Pre: 'data' and 'left'is a set of distinct comparable integers
	//Post: Returns the truth value of the sort sequence up to that point by showing that
	//      data and left have the same values
	bool Sorts::leftInvariant(int data[], int left[], int endpoint)
	{
		bool isTrue = true;
		for(int i = 0; i < endpoint; i++)
		{
			isTrue = (data[i] == left[i]);
		}
		return isTrue;
	}


	//Desc: Shows that the loop for right portion of the array to be merged is permuted into
	//      ascending order
	//Parameters: An array of integer, data, an array of integers, right, the start of
	//            where the array to be sorted is, start, and the endpoint for which the
	//            set has sorted for
	//Pre: 'data' and 'right'is a set of distinct comparable integers
	//Post: Returns the truth value of the sort sequence up to that point by showing that
	//      data and right have the same values
	bool Sorts::rightInvariant(int data[], int right[], int start, int endpoint)
	{
		bool isTrue = true;
		for(int i = start; i < endpoint; i++)
		{
			isTrue = (data[i] == right[i]);
		}
		return isTrue;
	}

#endif






