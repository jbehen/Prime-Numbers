#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Allocate memory for storing primes (rough estimate)
    int max = 23456790;
    int *prime = malloc(sizeof(int) * (max / 10)); // conservative estimate
    if (!prime) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int count = 0;
    prime[count++] = 2; // start with 2

    for (int i = 3; i <= max; i += 2) { // skip even numbers
        int is_prime = 1;
        double sqrt_i = sqrt((double)i);

        for (int j = 0; j < count; ++j) {
            if (prime[j] > sqrt_i) {
                break;
            }
            if (i % prime[j] == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            prime[count++] = i;
        }
    }

    // Print all primes
    for (int i = 0; i < count; ++i) {
        printf("%d\n", prime[i]);
    }

    free(prime);
    return 0;
}