# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int main(int argc, char *argv[]){
	int i = 0, len = atoi(argv[1]);
	FILE *fa, *fd;
	char fname_asc[128], fname_desc[128];

	strcpy(fname_asc, "asc_");
	strcpy(fname_desc, "desc_");
	
	strcat(fname_asc, argv[1]);
	strcat(fname_desc, argv[1]);
	
	strcat(fname_asc, ".txt");
	strcat(fname_desc, ".txt");
	
	fa = fopen(fname_asc, "w");
	fd = fopen(fname_desc, "w");
	
	for(i = 0 ; i < len ; i++){
		fprintf(fa, "%d\n", i);
		fprintf(fd, "%d\n", (len - i));
	}
	
	fclose(fa);
	fclose(fd);
	
	return 0;
}
