#include <iostream>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; // Base case: if b is 0, x is 1
        y = 0; // Base case: if b is 0, y is 0
        return a; // Return gcd(a, b)
    }
    int x1, y1; // To store results of recursive call
    int gcd = extendedGCD(b, a % b, x1, y1); // Recursive call
    x = y1; // Update x
    y = x1 - (a / b) * y1; // Update y
    return gcd; // Return gcd
}

// Function to find x and y such that ax + by = c
bool findSolution(int a, int b, int c, int &x, int &y) {
    int gcd = extendedGCD(a, b, x, y); // Calculate gcd and coefficients
    if (c % gcd != 0) {
        cout << "No solution exists." << endl; // No solution if c is not divisible by gcd
        return false; // Return false if no solution exists
    }
    // Scale the solution to the original equation
    x *= c / gcd; // Scale x
    y *= c / gcd; // Scale y
    return true; // Return true if a solution is found
}


// Function to find the k-th smallest non-negative integer value of x
int findKthSmallestX(int a, int b, int c, int k) {
    int x0, y0;
    int g = extendedGCD(a, b, x0, y0); // Find a particular solution
    x0 *= c / g; // Scale to the original equation
    b /= g; // Reduce b by gcd
    int t = 0; // Initial value of t

    // Finding the k-th smallest non-negative x
    // We want x = x0 + b * t to be non-negative
    // Thus, t must be >= -x0 / b
    if (x0 < 0) {
        t = (-x0 + b - 1) / b; // Ceiling of -x0 / b
    }
    
    // The k-th smallest non-negative integer value of x
    return x0 + b * (t + k - 1);
}



int main() {
    int a, b, c, x, y;

    // Input values for a, b, and c
    cout << "Enter coefficients a, b and constant c: ";
    cin >> a >> b >> c;

    // Find solution
    if (findSolution(a, b, c, x, y)) {
        cout << "Solution: x = " << x << ", y = " << y << endl;
    }

    return 0;
}

/*
Time Complexity: O(log(min(a, b)))
- The algorithm runs in logarithmic time relative to the smaller of the two numbers due to the recursive nature of the Extended Euclidean Algorithm.
*/
