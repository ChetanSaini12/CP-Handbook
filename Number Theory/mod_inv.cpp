#include <iostream>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;    // Set x to 1 when b is 0
        y = 0;    // Set y to 0 when b is 0
        return a; // Return gcd(a, b)
    }
    int x1, y1;                              // To store results of recursive call
    int gcd = extendedGCD(b, a % b, x1, y1); // Recursive call
    x = y1;                                  // Update x
    y = x1 - (a / b) * y1;                   // Update y
    return gcd;                              // Return gcd
}

// Function to find the modular inverse
int modularInverse(int a, int m)
{
    int x, y;
    int gcd = extendedGCD(a, m, x, y); // Calculate gcd and coefficients
    if (gcd != 1)
    {
        cout << "Inverse doesn't exist." << endl; // Inverse doesn't exist if gcd != 1
        return -1;                                // Return -1 if inverse doesn't exist
    }
    // Make x positive
    return (x % m + m) % m; // Ensure the result is in the range [0, m-1]
}



int main()
{
    int a, m;

    // Input values
    cout << "Enter a and m: ";
    cin >> a >> m;

    // Calculate modular inverse
    int inv = modularInverse(a, m);

    // Output the result
    if (inv != -1)
    {
        cout << "The modular inverse of " << a << " mod " << m << " is: " << inv << endl;
    }

    return 0;
}

/*
Time Complexity: O(log(min(a, m)))
- The algorithm runs in logarithmic time relative to the smaller of the two numbers due to the recursive nature of the Extended Euclidean Algorithm.
*/
