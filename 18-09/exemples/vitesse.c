#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

bool is_prime(long long n) {
	if (n < 2)
		return false;
	for (long long i = 2; i <= (long long)sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

long long sum_primes(long long limit) {
	long long total = 0;
	for (long long i = 2; i < limit; i++) {
		if (is_prime(i)) {
			total += i;
		}
	}
	return total;
}

int main() {
	clock_t start = clock();
	long long limit = 10000000;
	long long result = sum_primes(limit);
	clock_t end = clock();

	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Sum: %lld\n", result);
	printf("C Execution Time: %.2f seconds\n", cpu_time_used);
	return 0;
}
