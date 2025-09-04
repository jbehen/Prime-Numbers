#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function: primes_upto
 * ----------------------
 *  Generates all prime numbers less than or equal to n using
 *  an optimized Sieve of Eratosthenes.
 *
 *  n:      The maximum number to test for primality.
 *  count:  Output parameter; will contain the number of primes found.
 *
 *  returns: Dynamically allocated array of prime numbers (ascending order).
 *           The caller is responsible for freeing this memory.
 */
int* primes_upto(long n, long *count) {
    // Handle edge cases where n < 2 (no primes exist)
    if (n < 2) {
        *count = 0;
        return NULL;
    }

    // If n is less than 3, the only prime is 2
    if (n < 3) {
        int* primes = malloc(sizeof(int));
        primes[0] = 2;
        *count = 1;
        return primes;
    }

    /*
     * The sieve only considers odd numbers starting from 3,
     * because even numbers > 2 are not prime.
     *
     * For example, index 0 corresponds to number 3,
     * index 1 corresponds to number 5, index 2 -> 7, etc.
     */
    int m = (n - 3) / 2;      // Highest index representing odd numbers <= n
    int sieve_size = m + 1;   // Total number of odd numbers to track

    // Allocate a bitset where each bit corresponds to an odd number
    // 0 = prime candidate, 1 = composite
    unsigned char *sieve = 
    calloc((sieve_size + 7) / 8, sizeof(unsigned char));

    // Compute the max index 'r' for sieving (only need primes <= sqrt(n))
    int r = ((int)sqrt(n) - 3) / 2;

    // Main sieve loop: mark composites
    for (int i = 0; i <= r; i++) {
        int byte = i / 8;       // Locate byte containing bit for this index
        int bit = i % 8;        // Locate specific bit inside the byte

		//The Sieve of Eratosthenes is a simple, ancient algorithm for finding all prime 
		//numbers up to a specified limit. The method involves creating a list of numbers 
		//and then iteratively marking as composite all multiples of the first unmarked 
		//number (which is a prime), starting the marking process from the square of the 
		//prime number. This process continues until the square of the current prime 
		//exceeds the limit, at which point all remaining unmarked numbers are prime.

        // If already marked composite, skip
        if (sieve[byte] & (1 << bit)) continue;

        // Recover the prime number represented by index i
        int p = 2 * i + 3;

        // Start marking from p^2, converted back to index form
        int j = (p * p - 3) / 2;
        for (; j <= m; j += p) {
            sieve[j / 8] |= (1 << (j % 8));  // Mark multiples of p as composite
        }
    }

    // Count how many primes were found
    int size = 1; // Start with 2 (the only even prime)
    for (int i = 0; i <= m; i++) {
        if (!(sieve[i / 8] & (1 << (i % 8)))) size++;
    }

    // Allocate array to store primes
    int* primes = malloc(size * sizeof(int));
    primes[0] = 2; // Insert 2 at the beginning
    int idx = 1;

    // Collect all unmarked numbers (odd primes)
    for (int i = 0; i <= m; i++) {
        if (!(sieve[i / 8] & (1 << (i % 8)))) {
            primes[idx++] = 2 * i + 3;
        }
    }

    free(sieve);      // Clean up memory for the sieve
    *count = size;    // Report the total number of primes found
    return primes;
}

int main(int argc, char *argv[]) {
    long max_val;

    // If a command-line argument is given, use it as the upper limit
    if (argc > 1) {
        max_val = atol(argv[1]);   // Convert string arg to long
    } else {
        max_val = 23456790;        // Default upper limit if none provided
    }

    long count;
    // Get all primes up to max_val
    int* primes = primes_upto(max_val, &count);

    // Print the primes
    printf("Primes up to %ld:\n", max_val);
    for (int i = 0; i < count; i++) {
        printf("%d \n", primes[i]);
    }

    free(primes); // Free allocated memory
    return 0;
}
