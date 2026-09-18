import time


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def sum_primes(limit):
    total = 0
    for i in range(2, limit):
        if is_prime(i):
            total += i
    return total


start = time.time()
limit = 10_000_000
result = sum_primes(limit)
end = time.time()

print(f"Sum: {result}")
print(f"Python Execution Time: {end - start:.2f} seconds")
