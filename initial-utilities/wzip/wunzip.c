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
#include <string.h>

int main(int argc, char *argv[]) {
	
	
	if (argc == 1) {
		puts("wunzip: file1 [file2 ...]");
		exit(1);
	}
	
	for (int i = 1; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			puts("wunzip: cannot open file");
			exit(1);
		}
		
		int count;
		char c;
		
		while (1) {
			fread(&count, sizeof(int), 1, fp);
			fread(&c, sizeof(char), 1, fp);
			if (feof(fp))
				break;
			for (int j = 0; j < count; j++) {
				fwrite(&c, sizeof(char), 1, stdout);
			}
		}
		fclose(fp);
	}
	exit(0);
}
