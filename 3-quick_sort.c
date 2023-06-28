#include "sort.h"

/**
 * swap_ints - swap two integers in an array
 * @a : The first integer to swap
 * @b : The second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subsetof an array of integers according to
 * 			the lomuto partition scheme (last element as pivot).
 * @array: The array of integers
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */


int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return(above);
}

/**
 * lomuto_sort - implement the quicksort algorithm through recursion.
 * @ array: An array of integers to sort.
 * @ size: the size of the array.
 * @ left: the starting index of the array partition to order
 * @ right: the ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - sort an array of integers in ascending order
 * @ array: an array of integers to sort
 * @ size: the size of the array.
 *
 * Description: prints the array after each swap after using
 * the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
