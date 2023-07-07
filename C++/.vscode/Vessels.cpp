#include <iostream>
#include <set>
using namespace std;

int v_num, water, i, n, q_num, type, capacity[200001], vessels[200001];
set<int> st;
set<int>::iterator it;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> capacity[i];
    }
    for (i = 1; i <= n; i++) {
        st.insert(i);
    }
    cin >> q_num;
    for (i = 0; i < q_num; i++) {
        cin >> type;
        if (type == 1) {
            cin >> v_num >> water;
            it = st.lower_bound(v_num);
            while (water > 0 && it != st.end()) {
                if (water >= capacity[*it] - vessels[*it]) {
                    water -= capacity[*it] - vessels[*it];
                    vessels[*it] = capacity[*it];
                    it = st.erase(it);
                } else {
                    vessels[*it] += water;
                    water = 0;
                }
            }
        } else {
            cin >> v_num;
            cout << vessels[v_num] << endl;
        }
    }
    return 0;
}


/*
#include <iostream>
#include <set>
using namespace std;
int v_num, water, i, n, q_num, type, capacity[200001], vessels[200001];
set<int>st;
set<int>::iterator it;

int main() {
    cin>>n;
    for(i=1; i<=n; i++) {
        cin >> capacity[i];
    }
    for(i = 1; i<=n; i++) {
        st.insert(i);
    }
    cin>>q_num;
    for(i = 0; i < type; i++) {
        cin >> type;
        if (type == 1) {
            cin >> v_num>>water;
            it = st.lower_bound(v_num);
            while(water > 0) {
                if (it == st.end())
                    break;
                if (water >= capacity[*it] - vessels[*it]) {
                    water = water - (capacity[*it] - vessels[*it]);
                    vessels[*it] = capacity[*it];
                    it = st.erase(it++);
                } else {
                    vessels[*it] += water;
                    water = 0;
                }
            }
        } else {
            cin >> v_num;
            cout<<vessels[v_num]<<endl;
        }
    }
    return 0;
}


*/