/* 
 * entropyCalculator.c 
 * Parker Newton 
 * 5-18-15 
 * COEN 146L - T 2:15 pm 
 */ 

/* 
 * This program calculates the entropy of a byte stream by using the Shannon Entropy Formula. 
 * Entropy is calculated based on the probability of a char appearing in an element of a byte sequence. 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// The size of our frequency array 
#define NUM_CHARS 256

int main(void) 
// Main driver function 

{
	// freq[] stores the frequency of each char we read 
	int i, count = 0; 
	double entropy = 0.0, prob = 0.0; 
	int buf;  
	int freq[NUM_CHARS]; 

	// Initialize all the frequencies to 0 
	for(i = 0; i < NUM_CHARS; ++i)
		freq[i] = 0; 

	// For each char we read from the stdin, 
	// 		increment the frequency of that char
	while((buf = getc(stdin)) != EOF) {
		++freq[buf]; 
		++count;
	}

	/* 
	 * Calculating Entropy: 
	 * 
	 * For each possible char, we calculate the probability of appearance based on its frequency of appearance 
	 * 		divided by the total number of char's we read. 
	 * Entropy is dependent on the probability of appearance, and the algorithm for calculating entropy 
	 * 		based on the Shannon Entropy Formula is described in a Cisco blog post titled "On Information Entropy"
	 * 		(http://blogs.cisco.com/security/on_information_entropy). 
	 */ 
	for(i = 0; i < NUM_CHARS; ++i){
		prob = (double)freq[i] / (double)count; 
		entropy += freq[i] != 0 ? prob * log2(1 / prob) : 0;   
	}

	// We print to the stdout the calculated entropy for our byte sequence 
	printf("\nEntropy: %0.4lf\n", entropy); 

	return 0; 
}

