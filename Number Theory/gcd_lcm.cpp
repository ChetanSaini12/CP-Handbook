#include <iostream>
using namespace std;

// Function to calculate GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; // Find remainder
        a = temp;  // Update a to the previous value of b
    }
    return a; // a contains the GCD
}

// Function to calculate LCM using the relationship between GCD and LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // LCM(a, b) = (a * b) / GCD(a, b)
}

int main() {
    int num1, num2;

    // Input two numbers
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Calculate GCD and LCM
    int gcdResult = gcd(num1, num2);
    int lcmResult = lcm(num1, num2);
    
    // Output the GCD and LCM
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcdResult << endl;
    cout << "The LCM of " << num1 << " and " << num2 << " is: " << lcmResult << endl;

    return 0;
}

/*
Time Complexity:
- GCD: O(log(min(a, b)))
- LCM: O(log(min(a, b))) due to the GCD calculation.
*/
