#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    long max_val;
    if (argc > 1) {
        max_val = atol(argv[1]);
    } else {
        max_val = 23456790;
    }

    // Allocate array for primes
    long *primes = malloc(sizeof(long) * (max_val / 2));
    if (!primes) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int prime_count = 0;
    primes[prime_count++] = 2;

    for (long i = 3; i <= max_val; i += 2) {
        int is_prime = 1;
        long sqrt_i = (long) sqrt(i);

        for (int j = 0; j < prime_count; j++) {
            long p = primes[j];
            if (i % p == 0) {
                is_prime = 0;
                break;
            } else if (p > sqrt_i) {
                break;
            }
        }

        if (is_prime) {
            primes[prime_count++] = i;
        }
    }

    // Print primes
    for (int k = 0; k < prime_count; k++) {
        printf("%ld\n", primes[k]);
    }

    free(primes);
    return 0;
}
