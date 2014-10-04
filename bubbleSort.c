#include<stdlib.h>
#include<stdio.h>

void bsort(int *array, int n) {
	int i, j, temp;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n-1; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

}


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("[*]Usage: bubble_sort <Input File Name> <Number of elements>\n");
		return 0;
	}	
	int len = atoi(argv[2]), *arr, i;
	
	FILE *fp, *fw;
	fp = fopen(argv[1], "r");
	fw = fopen("sorted_file_bubble.txt", "w");
	
	arr = (int *)malloc(len * sizeof(int));
	for(i = 0 ; i < len ; i++)
		fscanf(fp, "%d", &arr[i]);
	bsort(arr, len);
	for(i = 0 ; i < len ; i++)
		fprintf(fw, "%d\n", arr[i]);
	free(arr);
	
	fclose(fp);
	fclose(fw);
	return 0; 
}

