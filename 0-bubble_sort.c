#include "sort.h"

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 * @array: Pointer to array given.
 * @size: Variable of array size.
 *
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < (size - a); b++)
		{
			if (array[b - 1] > array[b])
			{
				tmp = array[b];
				array[b] = array[b - 1];
				array[b - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
