#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define u16 uint16_t

int main(int argc, char	*argv[]){
	if (argc < 2)
	{
		printf("Invalid Usage\n");
		printf("\tAt least one file is needed as argument\n"); exit(1);
	}
	
	size_t rows = 0;
	size_t cols =10;

	char *file_to_dump = argv[1]; // TODO: check if file exists
	
	FILE *fp = fopen(file_to_dump, "rb");
	
	// check if file exists
	if (fp == NULL){
		printf("The file can't be opened\n");
	}	

	// read the bytes
	u16 buffer;
	size_t row_counter = 0;
	size_t col_counter = 0;

	while (fread(&buffer, sizeof(buffer),1,fp) > 0){
		printf("%x\t",buffer);
		
		col_counter ++;
		if (col_counter > cols){
			printf("\n");
			col_counter = 0;
			row_counter ++;
		}

		if (row_counter> rows && rows != 0){
			break;		
		}

	}
	printf("\n");


	fclose(fp);
}
