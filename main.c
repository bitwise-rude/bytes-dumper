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
	
	char *file_to_dump = argv[1]; // TODO: check if file exists
	
	FILE *fp = fopen(file_to_dump, "rb");
	
	// check if file exists
	if (fp == NULL){
		printf("The file can't be opened\n");
	}	

	// read the bytes
	u16 buffer;
	
	while (fread(&buffer, sizeof(buffer),1,fp) > 0){
	printf("DATA:%x\n",buffer);
	}	

	fclose(fp);
}
