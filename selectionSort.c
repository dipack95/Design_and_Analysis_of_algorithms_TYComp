# include <stdio.h>
# include <stdlib.h>
void selection_sort(int *arr, int len)
{
	int small, temp, i, j, pos;
	for(i = 0 ; i < len ; i++)
	{
		small = arr[i];
		pos = i;
		for(j = i + 1 ; j < len ; j++)
		{
			if(small > arr[j])
			{
				small = arr[j];
				pos = j;	
			}
		}
		temp = arr[pos];
		arr[pos] = arr[i];
		arr[i] = temp;
	}
}
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("[*]Usage: selection_sort <Input File Name> <Number of elements>\n");
		return 0;
	}	
	int len = atoi(argv[2]), *arr, i;
	
	FILE *fp, *fw;
	fp = fopen(argv[1], "r");
	fw = fopen("sorted_file.txt", "w");
	
	/*int len;
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	rewind(fp);
	printf("Length of file: %d\n\n", len);
	int arr[len];
	int i;*/
	
	arr = (int *)malloc(len * sizeof(int));
	for(i = 0 ; i < len ; i++)
		fscanf(fp, "%d", &arr[i]);
	selection_sort(arr, len);
	for(i = 0 ; i < len ; i++)
		fprintf(fw, "%d\n", arr[i]);
	free(arr);
	
	fclose(fp);
	fclose(fw);
	return 0; 
}
