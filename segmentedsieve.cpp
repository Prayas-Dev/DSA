#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to find all primes up to 'limit' using the simple Sieve of Eratosthenes
void simpleSieve(int limit, vector<int>& primes) {
    vector<bool> isPrime(limit + 1, true);

    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }

    // Store all prime numbers up to 'limit'
    for (int p = 2; p <= limit; ++p) {
        if (isPrime[p])
            primes.push_back(p);
    }
}

// Segmented Sieve function to find all primes in the range [low, high]
void segmentedSieve(int low, int high) {
    int limit = floor(sqrt(high)) + 1;
    vector<int> primes;
    
    // Step 1: Find all primes up to sqrt(high) using the simple sieve
    simpleSieve(limit, primes);

    // Step 2: Create a boolean array to mark primes in the range [low, high]
    vector<bool> isPrime(high - low + 1, true);

    // Step 3: For each prime number found by the simple sieve
    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];

        // Find the minimum number in the range [low, high] that is a multiple of p
        int start = max(p * p, (low + p - 1) / p * p);

        // Mark multiples of p as not prime in the range [low, high]
        for (int j = start; j <= high; j += p)
            isPrime[j - low] = false;
    }

    // Step 4: Print all primes in the range [low, high]
    for (int i = 0; i <= high - low; i++) {
        if (isPrime[i] && (i + low) != 1)  // Ensure we do not include 1
            cout << i + low << " ";
    }
    cout << endl;
}

int main() {
    int low = 10, high = 50;
    cout << "Primes in range [" << low << ", " << high << "] are: ";
    segmentedSieve(low, high);
    return 0;
}
