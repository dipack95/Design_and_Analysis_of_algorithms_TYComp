#include<stdio.h>
#include<stdlib.h>

void heapsort(int[], int);
void heapify(int[], int);
void adjust(int[], int);

int main(int argc, char *argv[]) {
	if (argc != 3)	{
		printf("[*]Usage: heap_sort <Input File Name> <Number of elements>\n");
		return 0;
	}

	int len = atoi(argv[2]), *arr, i;

	FILE *fp, *fw;
	fp = fopen(argv[1], "r");
	fw = fopen("sorted_file_heap.txt", "w");

	arr = (int *)malloc(len * sizeof(int));
	for (i = 0 ; i < len ; i++) {
		fscanf(fp, "%d", &arr[i]);
	}

	heapsort(arr, len);

	for (i = 0 ; i < len ; i++) {
		fprintf(fw, "%d\n", arr[i]);
	}

	free(arr);

	fclose(fp);
	fclose(fw);

	return 0;
}

void heapsort(int *array, int n) {
	int i, t;

	heapify(array, n);

	for (i = n - 1 ; i > 0 ; i--)	{
		t = array[0];
		array[0] = array[i];
		array[i] = t;
		adjust(array, i);
	}
}

void heapify(int *array, int n) {
	int item, i, j, k;

	for (k = 1 ; k < n ; k++)	{
		item = array[k];
		i = k;
		j = (i - 1) / 2;

		while ( (i > 0) && (item > array[j]) ) {
			array[i] = array[j];
			i = j;
			j = (i - 1) / 2;
		}

		array[i] = item;
	}
}

void adjust(int *array, int n) {
	int item, i, j;

	j = 0;
	item = array[j];
	i = 2 * j + 1;

	while (i <= n - 1) {
		if (i + 1 <= n - 1) {
			if (array[i] < array[i + 1]) {
				i++;
			}
		}
		if (item < array[i]) {
			array[j] = array[i];
			j = i;
			i = 2 * j + 1;
		}
		else {
			break;
		}
	}
	array[j] = item;
}

