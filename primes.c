#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    long max = 23456790;   // default
    if (argc > 1) {
        max = atol(argv[1]);
    }

    // Allocate array for storing primes
    long *primes = malloc((max / 2) * sizeof(long));
    if (!primes) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int count = 0;
    primes[count++] = 2; // first prime

    for (long i = 3; i <= max; i += 2) {
        int is_prime = 1;
        long sqrt_i = (long) sqrt((double)i);

        for (int j = 0; j < count; j++) {
            long p = primes[j];
            if (p > sqrt_i) break;
            if (i % p == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            primes[count++] = i;
        }
    }

    // Print primes
    for (int i = 0; i < count; i++) {
        printf("%ld\n", primes[i]);
    }

    free(primes);
    return 0;
}