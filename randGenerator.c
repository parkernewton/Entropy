/* 
 * randGenerator.c 
 * Parker Newton 
 * 5-18-15 
 * COEN 146L - T 2:15 pm 
 */ 

/*
 * This program generates a random byte stream 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define SIZE 4000000
#define NUM_CHARS 256 

int main(void) { 
	unsigned char str[SIZE]; 
	int freq[NUM_CHARS]; 
	int i, r, freq_count, char_count; 
	freq_count = SIZE / NUM_CHARS; 
	if((NUM_CHARS * freq_count) != SIZE)
		++freq_count; 
	for(i = 0; i < NUM_CHARS; ++i) 
		freq[i] = freq_count; 
	srand(time(NULL));   
	char_count = 0; 
	for(i = 0; i < SIZE; ++i){
		do {
			r = abs(rand()) % NUM_CHARS;   
		} while(freq[r] != freq_count);  
		str[i] = r; 
		--freq[r]; 
		if(++char_count == NUM_CHARS){
			char_count = 0; 
			--freq_count; 
		}
	}
	for(i = 0; i < SIZE; ++i){
		fprintf(stdout, "%hhu\t", str[i]); 
	}
	return 0; 
}

