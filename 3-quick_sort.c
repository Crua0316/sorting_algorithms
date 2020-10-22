#include "sort.h"
#include <stdlib.h>
/**
 * swap -function that swaps two values
 * @i: first value
 * @j: second value
 */
void swap(int *i, int *j)
{
	int aux;

	aux = *i;
	*i = *j;
	*j = aux;
}
/**
 * partition - function that divides the array
 * @array: array
 * @size: size
 * @low: low value
 * @high: high value
 *Return: int i
 */
int partition(int *array, size_t size, int low, int high)
{
	int k, l, piv;

	k = low - 1;
	piv = array[high];

	for (l = low; l <= high - 1; l++)
	{
		if (array[l] > piv)
			continue;

		k++;
		swap(&array[l], &array[k]);
		if (k  != l)
			print_array(array, size);

	}

	swap(&array[high], &array[k + 1]);
	if (k + 1 != l)
		print_array(array, size);

	return (k + 1);
}
/**
 * sort - function that sorts an array
 * @array: array
 * @size: size
 * @low: low value
 * @high: high value
 */
void sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int part = partition(array, size, low, high);

		sort(array, size, low, part - 1); /* Sort left partition */
		sort(array, size, part + 1, high); /* Sort rigth partition */
	}
}

/**
 * quick_sort - quick sort methodology
 * @array: array's information
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
