#include <iostream>
using namespace std;

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If modular inverse doesn't exist
}

// Function to solve the system of congruences using CRT
int chineseRemainder(int a[], int m[], int n) {
    int M = 1; // Product of all moduli
    for (int i = 0; i < n; i++) {
        M *= m[i]; // Calculate M
    }

    int result = 0; // Initialize result

    for (int i = 0; i < n; i++) {
        int Mi = M / m[i]; // Calculate M_i
        int inv = modInverse(Mi, m[i]); // Calculate modular inverse of M_i mod m_i
        if (inv == -1) {
            cout << "Modular inverse doesn't exist for m[" << i << "] = " << m[i] << endl;
            return -1; // If modular inverse doesn't exist
        }
        result += a[i] * Mi * inv; // Update the result
    }

    return result % M; // Return the result modulo M
}

int main() {
    int n;

    // Input number of equations
    cout << "Enter the number of equations: ";
    cin >> n;

    int a[n], m[n];

    // Input values for a and m
    cout << "Enter the values of a (remainders): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the values of m (moduli): ";
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    // Solve using Chinese Remainder Theorem
    int result = chineseRemainder(a, m, n);

    if (result != -1) {
        cout << "The solution x is: " << result << endl;
    }

    return 0;
}

/*
Time Complexity: O(n^2) for the modular inverse calculation in the worst case, 
where n is the number of equations.
*/
