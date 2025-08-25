import sys
import math

def generate_primes(max_num=23456790):
    primes = [2]
    for i in range(3, max_num + 1, 2):
        is_prime = True
        sqrt_i = math.isqrt(i)
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
    # Get command-line argument if provided, otherwise use default
    if len(sys.argv) > 1:
        max_num = int(sys.argv[1])
    else:
        max_num = 23456790

    primes = generate_primes(max_num)
    for p in primes:
        print(p)