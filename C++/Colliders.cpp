#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int parent[MAXN], loc[MAXN];
vector<int> factor[MAXN];
bool vis[MAXN];

void sieve() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            factor[j].push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, m;
    cin >> n >> m;

    while (m--) {
        char op; 
        int x;
        cin >> op >> x;
        
        if (op == '+') {
            if (vis[x]) {
                cout << "Already on\n";
            } else {
                for (int p: factor[x]) {
                    if (parent[p]) {
                        cout << "Conflict with " << parent[p] << '\n';
                        goto END;
                    }
                }
                for (int p: factor[x]) {
                    parent[p] = x;
                }
                vis[x] = true;
                cout << "Success\n";
            }
        } else {
            if (!vis[x]) {
                cout << "Already off\n";
            } else {
                for (int p: factor[x]) {
                    parent[p] = 0;
                }
                vis[x] = false;
                cout << "Success\n";
            }
        }
        END:;
    }

    return 0;
}
