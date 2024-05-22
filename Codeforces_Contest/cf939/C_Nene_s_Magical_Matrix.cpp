#include <iostream>
#include <vector>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    for (int i = 2; primes.size() < n; ++i) {
        if (isPrime(i)) primes.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << primes[i] << " ";
    }

    return 0;
}
