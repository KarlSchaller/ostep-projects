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
		puts("wgrep: searchterm [file ...]");
		exit(1);
	}
		
	char *key = argv[1];
	size_t buffersize = 64;
	char *buffer = (char *)malloc(buffersize * sizeof(char));
	
	if (argc == 2) {
		while (getline(&buffer, &buffersize, stdin) >= 0) {
			if (strstr(buffer, key) != NULL)
				printf("%s", buffer);
		}
	}
	
	for (int i = 2; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			puts("wgrep: cannot open file");
			exit(1);
		}
		
		while (getline(&buffer, &buffersize, fp) >= 0) {
			if (strstr(buffer, key) != NULL)
				printf("%s", buffer);
		}
		fclose(fp);
	}
	exit(0);
}
