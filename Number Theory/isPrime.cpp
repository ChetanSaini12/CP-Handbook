#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Handle special cases
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true;  // 2 and 3 are prime numbers

    // Check for even numbers greater than 2
    if (n % 2 == 0) return false;

    // Check for odd factors from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false; // n is divisible by i, hence not prime
    }
    return true; // n is prime
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}

/*
Time Complexity: O(sqrt(n))
- The function checks for divisibility only up to the square root of n,
- Making it efficient for large values of n.
*/
