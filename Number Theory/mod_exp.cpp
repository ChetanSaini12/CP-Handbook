#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1; // Initialize result
    base = base % mod; // Update base if it's greater than or equal to mod

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod; // Ensure result is within mod
        }
        // Now exp must be even
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return result; // Return the final result
}

int main() {
    long long base, exp, mod;

    // Input base, exponent and modulus
    cout << "Enter base, exponent and modulus: ";
    cin >> base >> exp >> mod;

    // Calculate modular exponentiation
    long long result = modularExponentiation(base, exp, mod);

    // Output the result
    cout << base << "^" << exp << " mod " << mod << " = " << result << endl;

    return 0;
}

/*
Time Complexity: O(log(exp))
- The algorithm runs in logarithmic time relative to the exponent due to the halving of exp.
*/
