import sys
import math

def generate_primes(max_val):
    primes = [2]
    for i in range(3, max_val + 1):
        # skip even numbers
        if i % 2 == 0:
            continue

        is_prime = True
        sqrt_i = math.isqrt(i)  # faster integer sqrt

        for p in primes:
            if p > sqrt_i:
                break
            if i % p == 0:
                is_prime = False
                break

        if is_prime:
            primes.append(i)
    return primes

if __name__ == "__main__":
    # Get argument or use default
    max_val = int(sys.argv[1]) if len(sys.argv) > 1 else 23456790
    primes = generate_primes(max_val)

    for p in primes:
        print(p)