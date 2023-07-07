#include <iostream>
using namespace std;

bool num[1000001];
int main() {
    int i, n, j;
    cin >>n;

    for(i=2; i <= n; i++) {
        if (num[i] == 1) {
            continue;
        } else {
            cout<<i<<" ";
            for(j = i*i; j<=n; j = j+i) {
                num[j] = 1;
            }
        }
    }
    return 0;
}