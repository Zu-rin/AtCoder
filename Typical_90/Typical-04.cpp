#include <iostream>
#include <vector>
#include <string>
#include <list>
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
	int num, i, j, h, w;
	cin >> h >> w;
	vector<vector<int>> d(h, vector<int>(w));
	vector<int> a(h, 0), b(w, 0);
	rep(i, h) {
		rep(j, w) {
			cin >> d[i][j];
			a[i] += d[i][j];
			b[j] += d[i][j];
		}
	}
	rep(i, h) {
		rep(j, w - 1)
			cout << a[i] + b[j] - d[i][j] << " ";
		cout << a[i] + b[j] - d[i][j] << "\n";
	}
	return 0;
}