#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 

    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        }
    }

    int count = 0;
    for (int p=2; p<=n; p++) {
        if (prime[p] && prime[p+2]) 
            count++;
    }

    if (count >= k) 
        cout << "YES"; 
    else
        cout << "NO";

    return 0;
}