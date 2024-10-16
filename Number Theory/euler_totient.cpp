#include <iostream>
using namespace std;

// Function to calculate Euler's Totient Function
int eulerTotient(int n) {
    int result = n; // Initialize result as n
    for (int p = 2; p * p <= n; p++) {
        // Check if p is a prime factor of n
        if (n % p == 0) {
            // If yes, subtract multiples of p from result
            while (n % p == 0) {
                n /= p; // Remove the prime factor from n
            }
            result -= result / p; // Apply the formula
        }
    }
    // If n is a prime number greater than 1
    if (n > 1) {
        result -= result / n; // Apply the formula for the remaining prime
    }
    return result; // Return the result
}

int main() {
    int n;

    // Input a number
    cout << "Enter a positive integer: ";
    cin >> n;

    // Calculate Euler's Totient Function
    int result = eulerTotient(n);

    // Output the result
    cout << "Euler's Totient Function φ(" << n << ") = " << result << endl;

    return 0;
}

/*
Time Complexity: O(sqrt(n))
- The algorithm runs in O(sqrt(n)) time due to the loop checking for prime factors.
*/
