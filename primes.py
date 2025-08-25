import sys
import math

# Get max value from command-line argument, default to 23456790 if none provided
max_val = int(sys.argv[1]) if len(sys.argv) > 1 else 23456790

primes = [2]

for i in range(3, max_val + 1, 2):  # Only check odd numbers
    is_prime = True
    sqrt_i = math.isqrt(i)  # Efficient integer square root

    for p in primes:
        if i % p == 0:
            is_prime = False
            break
        elif p > sqrt_i:
            break

    if is_prime:
        primes.append(i)

# Print all primes
for p in primes:
    print(p)
