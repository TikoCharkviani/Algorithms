#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
bool num[MAXN]; 
vector<int> primes;

void generatePrimes(int n) {
    int i,j;
    for(i=2; i <= MAXN; i++) {
        if (num[i] == 1) {
            continue;
        } else {
            primes.push_back(i);
            for(j = i*i; j<=n; j = j+i) {
                num[j] = 1;
            }
        }
    }
}


bool check_condition(int n, int k) {
    generatePrimes(n);
    int cnt = 0;
    for (int i = 2; i < primes.size(); ++i) {
        if (primes[i] == primes[i - 1] + primes[i - 2] + 1 && primes[i] <= n) {
            ++cnt;
        }
    }
    return cnt >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    if (check_condition(n, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
