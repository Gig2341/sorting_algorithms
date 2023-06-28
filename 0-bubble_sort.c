#include "sort.h"

/**
 * swap_ints - a function  that swaps ints
 * @ a - fisrt integer
 * @ b - second integer
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * bubble_sort - function that bubble sorts integers
 * @ array - an array to be sorted
 * @ size - the size of the array
 *
 * Description: prints the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t len = size;
	size_t i = 0;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while( swapped == false)
	{
		swapped = true;
		for (i =0; i < len-1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i,(array + i) + 1);
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
