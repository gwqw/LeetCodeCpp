/**
    204. Count Primes
Count the number of prime numbers less than a non-negative number, n.
Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Algo1:
  go to n:
    and check 
    if i is prime:
        ++cnt
        add i to primes

Algo2: Eratosphen resheto:
    go to sqrt(n);
        for j = 1 to sqrt(n):
            if (ij) not in cache:
                add i*j to cache
    count primes
*/

class Solution {
private:
    std::vector<int> primes_cache_;
    bool is_prime(int n) {
        int a = sqrt(n);
        for (auto i : primes_cache_) {
            if (n % i == 0) return false;
            if (i > a) break;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        for (int i = 2; i < n; ++i) {
            if (is_prime(i)) {
                primes_cache_.push_back(i);                
            }
        }
        return primes_cache_.size();
    }
};

