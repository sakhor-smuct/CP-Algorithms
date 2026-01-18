#include<bits/stdc++.h>
using namespace std;
#define N 100000

typedef long long int LL;

int sieve[N+1] = {0};
vector<int> primes;

void primeSieve() {
    sieve[0] = sieve[1] = 1;

    for (LL i=2; i<=N; i++) {
        if (sieve[i] == 0) {
            primes.push_back(i);
            for (LL j=i*i; j<=N; j=j+i)
                sieve[j] = 1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    primeSieve();

    int t;
    cin >> t;


    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<int> seg(n - m + 1, 0);

        for (auto p : primes) {
            if ((LL)p * p > n) break;

            // otherwise, find the nearest starting point
            int start = (m/p)*p;

            // special case
            if (p>=m and p<=n) start = 2*p;

            for (int j=start; j<=n; j=j+p) {
                if (j < m) continue;

                seg[j - m] = 1;
            }
        }

        for (LL i=m; i<=n; i++) {
            if (seg[i-m] == 0 and i!=1) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
