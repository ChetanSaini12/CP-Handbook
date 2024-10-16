#include <iostream>
#include <vector>
using namespace std;

// Function to implement the Sieve of Eratosthenes
vector<int> sieveOfEratosthenes(int n) {
    // Create a boolean array "isPrime[0..n]" and initialize all entries as true
    vector<bool> isPrime(n + 1, true);
    vector<int> primes; // Vector to store prime numbers

    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // If isPrime[p] is still true, then it is a prime
        if (isPrime[p]) {
            // Marking multiples of p as false
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Collecting all prime numbers
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
    return primes; // Return the list of prime numbers
}

int main() {
    int n;
    cout << "Enter the limit up to which you want to find prime numbers: ";
    cin >> n;

    vector<int> primes = sieveOfEratosthenes(n);

    cout << "Prime numbers up to " << n << " are: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: O(n log(log(n)))
- The Sieve of Eratosthenes efficiently finds all prime numbers up to n by marking non-prime numbers in the array.
*/
