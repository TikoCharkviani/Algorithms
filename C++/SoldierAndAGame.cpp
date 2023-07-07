// https://codeforces.com/problemset/problem/546/D
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime = sieve(MAXN);

    vector<int> primeCount(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; i++) {
        primeCount[i] = primeCount[i - 1] + isPrime[i];
    }

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << primeCount[b] - primeCount[a - 1] << endl;
    }

    return 0;
}
