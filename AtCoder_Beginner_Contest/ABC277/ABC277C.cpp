#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

class UnionFind {
private:
    vector<int> p;

public:
    UnionFind(int num) {
        p.resize(num + 1);
        for (int i = 0; i < p.size(); i++)
            p[i] = i;
    }

    int Parent(int n) {
        if (p[n] == n)
            return n;
        return p[n] = Parent(p[n]);
    }

    void Union(int a, int b) {
        a = Parent(a);
        b = Parent(b);
        p[a] = b;
        return;
    }

    int Same(int a, int b) {
        a = Parent(a);
        b = Parent(b);
        return a == b;
    }
};

int main(void) {
    int num = 0, i = 0, a, b, k = 1;
    cin >> num;
    map<int, int> mp;
    UnionFind uf(2 * num + 1);
    rep(i, num) {
        cin >> a >> b;
        if (mp.find(a) == mp.end()) {
            mp[a] = k++;   
        }
        if (mp.find(b) == mp.end()) {
            mp[b] = k++;
        }
        uf.Union(mp[a], mp[b]);
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (uf.Same((*it).second, mp[1])) {
            cout << (*it).first << "\n";
            break;
        }
    }
    return 0;
}