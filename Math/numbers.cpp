#include "numbers.h"

int gcd(const int& a, const int& b)  {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(const int& a, const int& b) {
    return a * b / gcd(a, b);
}

std::vector<bool> sieve_eratosthenes(int upper) {
    std::vector<bool> sieve(upper, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < upper; ++i) {
        if (sieve[i]) {
            for (int j = 2 * i; j < upper; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

std::set<int> primes(int upper) {
    std::vector<bool> sieve = sieve_eratosthenes(upper);
    std::set<int> primes;
    for (int i = 2; i < upper; ++i) {
        if (sieve[i]) primes.insert(i);
    }
    return primes;
}

bool is_prime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}
