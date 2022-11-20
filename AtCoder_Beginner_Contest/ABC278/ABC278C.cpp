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

int main(void) {
    int num, q, i, a, b, k;
    map<int, set<int>> mp;
    cin >> num >> q;
    rep(i, q) {
        cin >> k >> a >> b;
        if (k == 1) {
            mp[a].insert(b);
        }
        else if (k == 2) {
            mp[a].erase(b);
        }
        else {
            if (mp[a].find(b) != mp[a].end() and mp[b].find(a) != mp[b].end()) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}