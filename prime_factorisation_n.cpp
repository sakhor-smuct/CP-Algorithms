#include<bits/stdc++.h>
using namespace std;

void factorise(int n) {
    for (int i=2; i<=n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n = n / i;
            }
            cout << i << "^" << cnt << ", ";
        }
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    factorise(n);
    return 0;
}
