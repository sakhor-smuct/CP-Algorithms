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

void csum(vector<int>& primes, vector<int>& sum) {
    for (int i=1; i<=N; i++) {
        (primes[i]) ? sum[i] = sum[i-1] + 1 : sum[i] = sum[i-1];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes(N+1, 1), sum(N+1, 0);

    sieve(primes);
    csum(primes, sum);

    int Q, a, b;
    cin >> Q;

    while (Q--) {
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << endl;
    }

    return 0;
}
