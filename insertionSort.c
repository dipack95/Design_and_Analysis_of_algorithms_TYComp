#include<stdio.h>
#include<stdlib.h>
void isort(int *a, int n) 
{
	int i;
	int j, temp;
	for (j = 1; j < n; j++) 
	{
		temp = a[j];
		i = j - 1;
		while ( a[i] > temp && i >=0) 
		{
			a[i + 1] = a[i];
			i--;
		} 
		a[i + 1] = temp; 
	}	
}
void display(int * array, int n) 
{
	int i = 0;
	while ( i < n) 
	{
		printf("%d\n", array[i++]);
	}
}
int main(int argc, char *argv[]) 
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	int n = atoi(argv[2]);
	int i;	
	int *array = (int *) malloc( n * sizeof(int));

	for( i = 0; i < n; i++)
		fscanf(fp, "%d\n", &array[i]);
	isort(array, n); 
	display(array, n);
	
	return 0;
}
