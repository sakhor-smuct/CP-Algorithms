#include<bits/stdc++.h>
using namespace std;
#define N 1000000

typedef long long int LL;

void sieve(vector<int>& primes) {
    primes[0] = primes[1] = 0;

    for (LL i=2; i<=N; i++) {
        if (primes[i]) {
            for (LL j=i*i; j<=N; j=j+i)
                primes[j] = 0;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes(N+1, 1);

    sieve(primes);

    for (int i=0; i<=1000; i++) {
        if (primes[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
