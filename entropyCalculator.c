/* 
 * entropyCalculator.c 
 * Parker Newton 
 * 5-18-15 
 * COEN 146L - T 2:15 pm 
 */ 

/* 
 * This program calculates the entropy of a byte stream. 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define NUM_CHARS 256

int main(void) {
	int i, count = 0; 
	double entropy = 0.0, prob = 0.0; 
	unsigned char buf;  
	int freq[NUM_CHARS]; 
	for(i = 0; i < NUM_CHARS; ++i)
		freq[i] = 0; 
	while(fscanf(stdin, "%hhu", &buf) == 1){   
		++freq[buf]; 
		++count; 
	}  
	for(i = 0; i < NUM_CHARS; ++i){
		prob = (double)freq[i] / (double)count; 
		entropy += freq[i] != 0 ? prob * log2(1 / prob) : 0;   
	}
	printf("\nEntropy: %0.4lf\n", entropy); 
}

