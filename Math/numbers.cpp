#include "numbers.h"


int gcd(const int& a, const int& b)  {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(const int& a, const int& b) {
    return a * b / gcd(a, b);
}

std::vector<bool> sieve_eratosthenes(int upper) {
    std::vector<bool> sieve(upper + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= upper; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= upper; j += i) {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

std::set<int> primes(int upper) {
    std::vector<bool> sieve = sieve_eratosthenes(upper);
    std::set<int> primes;
    for (int i = 2; i <= upper; ++i) {
        if (sieve[i]) primes.insert(i);
    }
    return primes;
}

std::vector<int> factor(int a) {
    std::vector<int> divisors;
    for (int d = 2; d * d <= a; ++d) {
        while (a % d == 0) {
            divisors.push_back(d);
            a /= d;
        }
    }
    if (a != 1) divisors.push_back(a);
    return divisors;
}

bool is_prime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

std::tuple<int, int, int> extended_euclidean(const int &a, const int &b) {
    if (b == 0) return {1, 0, a};
    int x, y, g;
    std::tie(x, y, g) = extended_euclidean(b, a % b);
    return {y, x - (a / b) * y, g};
}
