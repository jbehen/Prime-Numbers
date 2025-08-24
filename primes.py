# This script finds prime numbers up to a certain limit.

prime = [2]  # Initialize a list with the first prime number

# Iterate through numbers from 3 up to 23,456,789
for i in range(3, 23456790):
    # Skip even numbers, as they cannot be prime (except for 2, which is handled)
    if i % 2 == 0:
        continue

    is_prime = True  # Assume the current number is prime
    sqrt_i = i**0.5  # Calculate the square root for optimization

    # Iterate through the prime numbers found so far
    for p in prime:
        # If the current prime number 'p' exceeds the square root of 'i',
        # then 'i' must be prime (no smaller prime factors were found)
        if p > sqrt_i:
            break
        # If 'i' is divisible by 'p', then 'i' is not prime
        elif i % p == 0:
            is_prime = False
            break
    
    # If 'is_prime' is still True, add 'i' to the list of primes
    if is_prime:
        prime.append(i)

# Print all the found prime numbers
for p_num in prime:
    print(p_num)