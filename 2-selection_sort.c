#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i,j;
	size_t jMin,len = size;
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < len -1; i++)
	{
		jMin = i;
		for(j = i + 1; j < len; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}

		if (jMin != i)
		{
			swap_ints(array + i, array + jMin);
			print_array(array, size);
		}
	}
}
