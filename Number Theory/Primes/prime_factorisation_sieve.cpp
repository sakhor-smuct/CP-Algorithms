#include <bits/stdc++.h>
using namespace std;

#define N 100000

int primes[N + 1];

void primeFactorSieve() {
    for (int i = 1; i <= N; i++)
        primes[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (primes[i] == i) {
            for (int j = i; j <= N; j += i) {
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
    }
}

void factorise(int n) {
    if (n <= 1) {
        cout << "No prime factors\n";
        return;
    }

    while (n != 1) {
        cout << primes[n] << " ";
        n /= primes[n];
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    primeFactorSieve();

    int n;
    cin >> n;

    factorise(n);
    return 0;
}
