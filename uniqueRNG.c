# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void shuffle(int *array, size_t array_size, size_t shuff_size) {
    if (array_size > 1) {
        size_t i;
        for (i = 0; i < shuff_size - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (array_size - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, char * argv[]) {
    int i, n;
    char fname[128];
    if(argc != 3) {
        printf("\n[*] Usage: urng <Number of random numbers> <Output file name>");
        return 0;
    }
    FILE *fw;
    //fname = argv[2];
    strcpy(fname, argv[2]);
    n = atoi(argv[1]);
    fw = fopen(fname, "w");

    int a[n];
    for(i=0 ; i<n ; ++i)
        a[i]=i;

    shuffle(a, n, n);

    for(i = 0 ; i < n ; i++)
        fprintf(fw, "%d\n", a[i]);
    fclose(fw);
    return 0;
}
