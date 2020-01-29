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
		puts("wzip: file1 [file2 ...]");
		exit(1);
	}
	
	char current = 0;
	char next = 0;
	int count = 1;
		
	for (int i = 1; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			puts("wzip: cannot open file");
			exit(1);
		}	
		
		if (!current)
			current = fgetc(fp);
		
		while (current != EOF) {
			while ((next = fgetc(fp)) == current)
				count++;
			if (next == EOF && i < argc - 1)
				break;
			fwrite(&count, sizeof(int), 1, stdout);
			fwrite(&current, sizeof(char), 1, stdout);
			count = 1;
			current = next;
		}
		fclose(fp);
	}
	exit(0);
}
