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
    int num, i, j, v, h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }
    cin >> h >> w;
    vector<vector<int>> b(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> b[i][j];
        }
    }
    rep(h, 1 << a.size()) {
        rep(w, 1 << a[0].size()) {
            vector<vector<int>> x;
            rep(i, a.size()) {
                if (h & (1 << i))
                    continue;
                vector<int> y;
                rep(j, a[0].size()) {
                    if (w & (1 << j))
                        continue;
                    y.push_back(a[i][j]);
                }
                x.push_back(y);
            }
            if (x == b) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}