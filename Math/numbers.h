#ifndef NUMBERS_H
#define NUMBERS_H

#include <set>
#include <vector>
#include <tuple>


int gcd(const int& a, const int& b);

int lcm(const int& a ,const int& b);

std::vector<bool> sieve_eratosthenes(int upper);

std::set<int> primes(int upper);

std::vector<int> factor(int a);

bool is_prime(int a);

std::tuple<int, int, int> extended_euclidean(const int& a, const int& b);


#endif //NUMBERS_H
