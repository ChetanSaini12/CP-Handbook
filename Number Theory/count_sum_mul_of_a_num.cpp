#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find the prime factors of a number with their frequencies
vector<pair<int, int>> primeFactors(int n)
{
    vector<pair<int, int>> factors;
    int count = 0;

    // Check for the number of times 2 divides n
    while (n % 2 == 0)
    {
        n /= 2;
        count++;
    }
    if (count > 0)
    {
        factors.push_back({2, count});
    }

    // Check for odd factors from 3 onwards
    for (int i = 3; i * i <= n; i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
        if (count > 0)
        {
            factors.push_back({i, count});
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
    {
        factors.push_back({n, 1});
    }

    return factors;
}

// Function to calculate the number of divisors
int numOfDivisors(const vector<pair<int, int>> &factors)
{
    int divisors = 1;
    for (auto factor : factors)
    {
        divisors *= (factor.second + 1); // (e1 + 1) * (e2 + 1) * ... * (ek + 1)
    }
    return divisors;
}

// Function to calculate the sum of divisors
int sumOfDivisors(const vector<pair<int, int>> &factors)
{
    int sum = 1;
    for (auto factor : factors)
    {
        int p = factor.first;
        int e = factor.second;
        sum *= (pow(p, e + 1) - 1) / (p - 1); // Sum formula: (p^(e+1) - 1) / (p - 1)
    }
    return sum;
}

// Function to calculate the multiplication of divisors
long long multOfDivisors(const vector<pair<int, int>> &factors, int n)
{
    // Multiplication of divisors is d(n)^(n/2), where d(n) is the product of the divisors
    long long divisors = numOfDivisors(factors);
    long long ans = pow(n, divisors / 2); // n raised to d(n) / 2
    if (divisors % 2) // if n is a perfect square
        ans *= sqrt(n);
    return ans;
}

int main()
{
    int n = 9; // Example number
    vector<pair<int, int>> factors = primeFactors(n);

    int divisors = numOfDivisors(factors);
    int sumDiv = sumOfDivisors(factors);
    long long multDiv = multOfDivisors(factors, n);

    cout << "Number of divisors: " << divisors << endl;
    cout << "Sum of divisors: " << sumDiv << endl;
    cout << "Multiplication of divisors: " << multDiv << endl;

    return 0;
}

/*
Time Complexity:
- The prime factorization part runs in O(sqrt(n)), so all calculations (number, sum, and multiplication of divisors) depend on prime factorization.
- Overall complexity is O(sqrt(n)).
*/
