#ifndef NUMBERS_H
#define NUMBERS_H

#include <set>
#include <vector>

int gcd(const int& a, const int& b);

int lcm(const int& a ,const int& b);

std::vector<bool> sieve_eratosthenes(int upper);

std::set<int> primes(int upper);

bool is_prime(int a);


#endif //NUMBERS_H
