/* 
 * rand.c 
 * Parker Newton 
 * 5-18-15 
 * COEN 146L - T 2:15 pm 
 */ 

/*
 * This program generates a random sequence of bytes. 
 * We partition the block of data to send into parts of size 256. 
 * We are sending a sequence of unsigned char's, each of length 1 byte. 
 * We maintain an array of size 256 that maps each char's ASCII value to its frequency of appearance in our data. 
 * We choose a random value between 0 and 255, and while we are in each part of size 256, we will not reuse the same char. 
 * Finally, The byte sequence is written to the stdout. 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// The size of our byte sequence 
#define SIZE 1048576 

// The size of our frequency array 
#define NUM_CHARS 256 


int main(void) 
// Main driver function 

{ 
	// str[] stores our generated data 
	// freq[] maintains a count of the number of times each char should appear in our data
	// freq_count is a count of the number of parts into which we will partition our data 
	// char_count counts the number of char's we have chosen values for in each part 
	unsigned char str[SIZE]; 
	int freq[NUM_CHARS]; 
	int i, r, freq_count, char_count; 

	// Calculate the number of parts 
	freq_count = SIZE / NUM_CHARS; 

	// If we have parts of unequal size, 
	// 		then increment our freq_count by 1 
	if((NUM_CHARS * freq_count) != SIZE)
		++freq_count; 

	// Intitialize all frequencies to freq_count 
	for(i = 0; i < NUM_CHARS; ++i) 
		freq[i] = freq_count; 

	/* 
	 * Generating random char's: 
	 * 
	 * We will use rand() abs() to generate a random non-negative integer. 
	 * We mod that non-negative by 256 to generate a number between 0 and 255. 
	 * We map that value to a frequency stored in freq[]. 
	 * While that frequency does not equal the current frequency we are looking for (freq_count), 
	 * 		we repeat the above steps. 
	 * We store the randomly-generated char value into our byte sequence. 
	 * We decrement the frequency of that char in freq[]. 
	 * Increment the char_count. If we have reached 256 char's, then we have reached a new part, 
	 * 		so reset the char_count to 0 and decrement the freq_count. 
	 */ 

	srand(time(NULL));   
	char_count = 0; 
	for(i = 0; i < SIZE; ++i){
		do 
			r = abs(rand()) % NUM_CHARS;   
		while(freq[r] != freq_count);  
		str[i] = r; 
		--freq[r]; 
		if(++char_count == NUM_CHARS){
			char_count = 0; 
			--freq_count; 
		}
	}

	// Write our byte sequence to the stdout. 
	for(i = 0; i < SIZE; ++i) 
		putc((int)str[i], stdout); 

	return 0; 
}

