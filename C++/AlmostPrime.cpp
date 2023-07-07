#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 3005;
bool isPrime[MAXN];
vector<int> primes;

vector<int> sieve(int n) {
    vector<bool> num(n + 1, false);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (!num[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                num[j] = true;
            }
        }
    }

    return primes;
}
/*void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<MAXN; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j=i*i; j<MAXN; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}
*/

int main() {
    sieve(MAXN);
    int n;
    cin >> n;

    int count = 0;
    for(int i=2; i<=n; ++i) {
        int primeFactors = 0;
        for(int j=0; j<primes.size() && primes[j]<=i; ++j) {
            if(i % primes[j] == 0) {
                ++primeFactors;
            }
        }
        if(primeFactors == 2) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
