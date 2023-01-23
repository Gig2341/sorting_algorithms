#include "sort.h"

/**
 * swap_ints - a function  that swaps integers
 * @ a - fisrt integer
 * @ b - second integer
 * Returns: Null
 */


void swap_ints(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * shell_sort - function that sorts integers in ascending order
 *		using the shell sort algorithm.
 * @ array - an array to be sorted
 * @ size - the size of the array
 * Returns: a shell sorted array in ascending order
 *
 * Description: Uses the knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	
	if (array == NULL || size < 2)
		return;

	for(gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for(; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
