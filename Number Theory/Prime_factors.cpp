#include <iostream>
#include <vector>
using namespace std;

// Function to find the prime factors of a number with their frequencies
void primeFactors(int n) {
    // Vector to store prime factors
    vector<pair<int, int>> factors;
    
    // Check for the number of times 2 divides n
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count > 0) {
        factors.push_back({2, count});
    }

    // Check for odd factors from 3 onwards
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            factors.push_back({i, count});
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back({n, 1});
    }

    // Print the prime factors and their frequencies
    for (auto factor : factors) {
        cout << "Prime Factor: " << factor.first << ", Frequency: " << factor.second << endl;
    }
}

int main() {
    int n = 100;  // Example number
    cout << "Prime factors of " << n << " are:" << endl;
    primeFactors(n);

    return 0;
}

/*
Time Complexity: O(sqrt(n))
- The loop runs up to sqrt(n) for checking divisibility by potential prime factors.
- Divisibility is checked by both 2 and all odd numbers up to sqrt(n), which makes the complexity O(sqrt(n)).
*/
