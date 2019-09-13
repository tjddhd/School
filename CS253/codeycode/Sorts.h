/*
 * Sorts.h
 *
 *  Created on: Feb 6, 2012
 *      Author: Thomas Dolan
 */

#ifndef SORTS_H_
#define SORTS_H_

class Sorts
{

	private:
		bool sortTrue;
	public:

		//Desc: Sorts a set of data through use of the insertion sort method
		//Parameters: An array of integers, data, and the size of the array, length
		//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2
		//Post: A permutation of 'data' that is an array ordered in ascending value of distinct
		//      comparable integers for the array of length <= 2
		void insertionSort(int data[], int length);


		//Desc: Sorts a set of data through use of the merge sort method
		//Parameters: An array of integers, data, the initial point from which the set to be
		//            compared will begin at, start, and the final point from which the set to
		//            be compared will end at, end
		//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2
		//     end > start
		//Post: A permutation of 'data' that is an array ordered in ascending value of distinct
		//      comparable integers for the array of length <= 2
		void mergeSort(int data[], int start, int end);


		//Desc: Merges the set of between 'start' and 'end' into ascending order
		//Parameters: An array of integers, data, the initial point from which the set to be
		//            merged will begin at, start, the rounded down midpoint of the set to be
		//            merged, and the final point from which the set to be merged will end at,
		//            end
		//Pre: 'data' is a set of distinct comparable integers for an array of length <= 2
		//     end > start, midpoint > start, data[start...midpoint] & data[midpoint+1....end]
		//     are sprted and permuted into ascending order
		//Post: A permutation of 'data' that has the elements between the 'start' and the 'end'
		//      merged into ascending order
		void merge(int data[], int start, int midpoint, int end);


		//Desc: Shows that the loop for insertion sort is right at all points during runtime
		//Parameters: An array of integer, data, and the endpoint for which the set has sorted
		//            for
		//Pre: 'data' is a set of distinct comparable integers
		//Post: Returns the truth value of the sort sequence up to that point
		bool insertionInvariant(int data[], int endpoint);


		//Desc: Shows that the loop for merge sort is right at all points during runtime
		//Parameters: An array of integer, data, and the endpoint for which the set has sorted
		//            for
		//Pre: 'data' is a set of distinct comparable integers
		//Post: Returns the truth value of the sort sequence up to that point
		bool mergeInvariant(int data[], int start, int endpoint);


		//Desc: Shows that the loop for left portion of the array to be merged is permuted into
		//      ascending order
		//Parameters: An array of integer, data, an array of integers, left, and the endpoint
		//            for which the set has sorted for
		//Pre: 'data' and 'left'is a set of distinct comparable integers
		//Post: Returns the truth value of the sort sequence up to that point by showing that
		//      data and left have the same values
		bool leftInvariant(int data[], int left[], int endpoint);


		//Desc: Shows that the loop for right portion of the array to be merged is permuted into
		//      ascending order
		//Parameters: An array of integer, data, an array of integers, right, the start of
		//            where the array to be sorted is, start, and the endpoint for which the
		//            set has sorted for
		//Pre: 'data' and 'right'is a set of distinct comparable integers
		//Post: Returns the truth value of the sort sequence up to that point by showing that
		//      data and right have the same values
		bool rightInvariant(int data[], int right[], int start, int endpoint);

		bool getTrue(){return sortTrue;}
};

#include"Sorts.hpp"
#endif
