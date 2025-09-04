import math
import sys

def primes_upto(n: int) -> list[int]:
	"""
	Function: primes_upto
	----------------------
	Generates all prime numbers less than or equal to n using
	an optimized Sieve of Eratosthenes.

	n:		 The maximum number to test for primality.

	returns: A list of prime numbers in ascending order.
	"""

	# Handle edge cases where n < 2 (no primes exist)
	if n < 2:
		 return []

	# If n is less than 3, the only prime is 2
	if n < 3:
		 return [2]

	# The sieve only considers odd numbers starting from 3,
	# because even numbers > 2 are not prime.
	#
	# For example, index 0 corresponds to number 3,
	# index 1 corresponds to number 5, index 2 -> 7, etc.
	m = (n - 3) // 2		 # Highest index representing odd numbers <= n
	sieve_size = m + 1	  # Total number of odd numbers to track

	# Boolean array: False = prime candidate, True = composite
	sieve = [False] * sieve_size

	# Compute the max index 'r' for sieving (only need primes <= sqrt(n))
	r = int(math.sqrt(n) - 3) // 2

	# Main sieve loop: mark composites
	for i in range(r + 1):
		 if sieve[i]:  # If already marked composite, skip
			  continue

		 # Recover the prime number represented by index i
		 p = 2 * i + 3

		 # Start marking from p^2, converted back to index form
		 j = (p * p - 3) // 2
		 while j <= m:
			  sieve[j] = True
			  j += p

	# Collect primes into a list
	primes = [2]  # Start with 2 (the only even prime)
	for i in range(sieve_size):
		 if not sieve[i]:
			  primes.append(2 * i + 3)

	return primes


def main():
	# If a command-line argument is given, use it as the upper limit
	if len(sys.argv) > 1:
		 max_val = int(sys.argv[1])
	else:
		 max_val = 23456790  # Default upper limit if none provided

	# Get all primes up to max_val
	primes = primes_upto(max_val)

	# Print the primes
	print(f"Primes up to {max_val}:")
	for p in primes:
		 print(p)


if __name__ == "__main__":
	main()