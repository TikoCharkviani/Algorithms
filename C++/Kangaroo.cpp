#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    
    vector<int> kangaroos(n);
    for (int i = 0; i < n; ++i) {
        cin >> kangaroos[i];
    }
    sort(kangaroos.begin(), kangaroos.end());
    int visible = 0;
    int halfSize = n/2;
    for (int i = 0; i < halfSize; ++i) {
        for(int j = halfSize + i; j < n; ++j) {
            if (kangaroos[i] <= kangaroos[j]/2) {
                visible++;
            }
        }
    }
    int result = n - visible;
    cout << result << endl;
    
    return 0;
}







