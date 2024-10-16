## Finding All Prime Factors and Their Frequency

To find all prime factors of a number and their frequency:

1. **Prime Factorization**:
   Start by dividing the number by the smallest prime (2) and continue dividing by 2 until it's no longer divisible. Move to the next prime (3, 5, etc.) and repeat until the number becomes 1.

2. **Tracking Frequency**:
   Keep a count of how many times each prime divides the number. This count represents the frequency of that prime factor.

3. **Optimized Approach**:
   Only check divisibility up to the square root of the number. After that, if the remaining number is greater than 1, it's a prime factor.

### Example:

For `60`, the prime factors and their frequencies are:

- 2 (frequency: 2, divides 60 → 30 → 15)
- 3 (frequency: 1, divides 15 → 5)
- 5 (frequency: 1, divides 5 → 1)

So, prime factorization of `60 = 2^2 * 3^1 * 5^1`.


## Finding Count of Divisors, Sum of Divisors, and Product of Divisors


Once you have the prime factorization, you can calculate various properties of the divisors:

1. **Count of Divisors**: The total number of divisors can be determined from the prime factorization. If a number `n` has a prime factorization `n = p1^e1 * p2^e2 * ... * pk^ek`, where `p1, p2, ..., pk` are prime factors and `e1, e2, ..., ek` are their respective frequencies, the count of divisors is `(e1 + 1) * (e2 + 1) * ... * (ek + 1)`.

2. **Sum of Divisors**: The sum of divisors can also be calculated using prime factorization. For a number `n = p1^e1 * p2^e2 * ... * pk^ek`, the sum of divisors is `(1 + p1 + p1^2 + ... + p1^e1) * (1 + p2 + p2^2 + ... + p2^e2) * ... * (1 + pk + pk^2 + ... + pk^ek)`.

3. **Product of Divisors**: The product of divisors is given by `n^(d/2)`, where `d` is the total number of divisors.

### Example:

For `60`, the prime factorization is `60 = 2^2 * 3^1 * 5^1`.

- **Count of divisors**: `(2 + 1) * (1 + 1) * (1 + 1) = 3 * 2 * 2 = 12`
- **Sum of divisors**: `(1 + 2 + 4) * (1 + 3) * (1 + 5) = 7 * 4 * 6 = 168`
- **Product of divisors**: `60^(12/2) = 60^6 = 46,656,000,000`



## Perfect Number

A number `n` is called a **perfect number** if it equals the sum of its divisors, excluding itself. Mathematically, this can be written as:

n = σ(n) - n
where `σ(n)` represents the sum of all divisors of `n`. In other words, a perfect number is one where the sum of its divisors between 1 and `n-1` equals `n` itself.

### Example:
The number `28` is a perfect number because the divisors of 28 (excluding 28 itself) are 1, 2, 4, 7, and 14, and their sum is:

1 + 2 + 4 + 7 + 14 = 28
Thus, `28` satisfies the condition of being a perfect number.



## Conjectures Involving Primes


- **Goldbach’s Conjecture**: This conjecture suggests that every even integer greater than 2 can be expressed as the sum of two prime numbers. In other words, for any even number `n > 2`, there exist primes `a` and `b` such that `n = a + b`.

- **Twin Prime Conjecture**: According to this conjecture, there are infinitely many pairs of prime numbers `{p, p + 2}`, where both `p` and `p + 2` are prime. These pairs are called twin primes, such as `(3, 5)` and `(11, 13)`.

- **Legendre’s Conjecture**: This conjecture asserts that there is always at least one prime number between any two consecutive perfect squares. For example, between 9 (`3^2`) and 16 (`4^2`), there are primes like 11 and 13.



## Sieve of Eratosthenes

The **Sieve of Eratosthenes** is an ancient algorithm used to efficiently find all prime numbers up to a specified integer `n`. It is named after the ancient Greek mathematician Eratosthenes.

### How It Works

1. **Initialization**: Create a boolean array `prime[0..n]` and initialize all entries as `True`. A value in `prime[i]` will be `False` if `i` is not a prime number.

2. **Marking Non-Primes**: Start with the first prime number, `p = 2`. For each prime number, mark all of its multiples as non-prime (i.e., set them to `False`). This marking starts from `p * p` because any smaller multiple of `p` would have already been marked by a smaller prime factor.

3. **Iteration**: Increment `p` and repeat the marking process until `p * p` exceeds `n`.

4. **Collecting Primes**: After processing, all numbers that remain marked as `True` in the `prime` array are prime numbers.

### Time Complexity

The time complexity of the Sieve of Eratosthenes is `O(n log log n)`, making it much more efficient for finding all primes compared to checking each number individually.


## Fermat's Little Theorem

**Fermat's Little Theorem** is a fundamental theorem in number theory that provides a simple criterion for determining if a number is a prime. It states that if `p` is a prime number and `a` is any integer not divisible by `p`, then:

a^(p-1) ≡ 1 (mod p)

### Explanation

This means that if you raise `a` to the power of `p-1` and then divide by `p`, the remainder will be 1. In simpler terms, the theorem implies that for a prime `p`, any integer `a` that is coprime to `p` will satisfy this property.

### Example

Let’s consider `p = 5` and `a = 2`. Since 5 is prime and 2 is not divisible by 5, we can apply Fermat's theorem:

2^(5-1) = 2^4 = 16

Now, `16 mod 5` gives a remainder of 1, which verifies the theorem.

---

## Euler's Theorem

**Euler's Theorem** is a generalization of Fermat's Little Theorem. It states that if `n` is a positive integer and `a` is an integer coprime to `n`, then:

a^(φ(n)) ≡ 1 (mod n)

where `φ(n)` (Euler's totient function) is the number of integers less than `n` that are coprime to `n`.

### Explanation

Euler's Theorem extends Fermat's theorem to non-prime moduli and states that for any integer `a` that is coprime to `n`, raising `a` to the power of `φ(n)` will yield a remainder of 1 when divided by `n`.

### Example

Let’s consider `n = 10` and `a = 3`. First, we calculate `φ(10)`, which equals 4 (the coprime integers less than 10 are 1, 3, 7, and 9). Now we can apply Euler's theorem:

3^(φ(10)) = 3^4 = 81

Now, `81 mod 10` gives a remainder of 1, verifying Euler's theorem.


## Modular Inverse

The **modular inverse** of an integer `a` with respect to a modulus `m` is an integer `x` such that the following equation holds:

a * x ≡ 1 (mod m)

This means that when you multiply `a` and `x`, the result is congruent to 1 modulo `m`. In other words, `a` and `m` must be coprime (i.e., their greatest common divisor must be 1) for the modular inverse to exist.

### Importance

The modular inverse is crucial in various fields such as cryptography, number theory, and computer science. It is especially useful for solving equations in modular arithmetic and in algorithms like the RSA encryption.

### How to Calculate the Modular Inverse

1. **Using Extended Euclidean Algorithm**: This algorithm not only finds the GCD of two numbers but also provides coefficients (the modular inverses) that express this GCD as a linear combination of the two numbers.

2. **Using Fermat’s Little Theorem**: If `m` is a prime number, the modular inverse of `a` can be calculated as:
a^(m-2) mod m
This is derived from Fermat’s theorem, where \(a^{m-1} \equiv 1 \mod m\).

### Example

Let’s find the modular inverse of `3` modulo `11` using the Extended Euclidean Algorithm.

1. **Apply the Algorithm**:
- We need to find integers `x` and `y` such that:
3x + 11y = 1

- Applying the Extended Euclidean Algorithm, we perform the following steps:
11 = 3 * 3 + 2 3 = 2 * 1 + 1 2 = 1 * 2 + 0

Back substituting to find `1`:

1 = 3 - 1 * 2 2 = 11 - 3 * 3

Substituting for `2`:

1 = 3 - 1 * (11 - 3 * 3) = 4 * 3 - 1 * 11

Thus, the coefficients are `4` (modular inverse) and `-1`.

2. **Conclusion**:
   - Therefore, the modular inverse of `3` modulo `11` is `4`, since:
3 * 4 ≡ 12 ≡ 1 (mod 11)
