/*
============================================================================
Name        : Karl Schaller
Date        : 01/15/2020
Course      : CIS3207
Homework    : Assignment 0 Unix Utilities
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	size_t buffersize = 64;
	char *buffer = (char *)malloc(buffersize * sizeof(char));
	
	for (int i = 1; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			puts("wcat: cannot open file");
			exit(1);
		}
		
		while (getline(&buffer, &buffersize, fp) >= 0) {
			printf("%s", buffer);
		}
		fclose(fp);
	}
	
	free(buffer);
	exit(0);
}
