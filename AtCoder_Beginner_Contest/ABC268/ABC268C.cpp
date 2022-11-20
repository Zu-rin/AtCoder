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
    int num, i, a, ans = 0;
    cin >> num;
    vector<int> d(num, 0);
    rep(i, num) {
        cin >> a;
        d[(a - 1 - i + num) % num]++;
        d[(a - i + num) % num]++;
        d[(a + 1 - i + num) % num]++;
    }
    rep(i, num) {
        chmax(ans, d[i]);
    }
    cout << ans << "\n";
    return 0;
}