/**
    204. Count Primes
Count the number of prime numbers less than a non-negative number, n.
Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Algo1: O(N * sqrt(P))
  go to n:
    and check 
    if i is prime:
        ++cnt
        add i to primes

Algo2: Eratosphen resheto: O(sqrt(N) * sqrt(N))
    go to sqrt(n);
        for j = 1 to sqrt(n):
            if (ij) not in cache:
                add i*j to cache
    count primes
*/

// Algo1
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

//Algo2
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        std::vector<bool> primes(n, true);
        int primes_cnt = n-2;
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i*i < n; ++i) {
            if (!primes[i]) continue;
            for (int j = 2; i*j < n; ++j) {
                if (i*j < n && primes[i*j]) {
                    primes[i*j] = false;
                    --primes_cnt;
                }
            }
        }
        return primes_cnt;
    }
};

// Algo2 with char (20ms)
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        std::vector<bool> primes(n, true);
        int primes_cnt = n-2;
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i*i < n; ++i) {
            if (!primes[i]) continue;
            for (int j = 2; i*j < n; ++j) {
                if (i*j < n && primes[i*j]) {
                    primes[i*j] = false;
                    --primes_cnt;
                }
            }
        }
        return primes_cnt;
    }
};

//Algo2 enh
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        std::vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i*i < n; ++i) {
            if (primes[i]) {
                for (int j = i*i; j < n j += i) {
                    primes[j] = false;
                }
            }
        }
        int cnt = 0;
        for (auto p : primes) {
            if (p) ++cnt;
        }
        return primes_cnt;
    }
};