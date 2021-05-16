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

int Query(int s, int e) {
	int dist;
	cout << "? " << s << " " << e << endl;
	cin >> dist;
	return dist;
}

int main(void) {
	int num, i, v, ma = 0, d, ans = 0;
	cin >> num;
	for (i = 2; i <= num; i++) {
		d = Query(1, i);
		if (d > ma) {
			ma = d;
			v = i;
		}
	}
	for (i = 1; i <= num; i++) {
		if (i == v)
			continue;
		chmax(ans, Query(v, i));
	}
	cout << "! " << ans << "\n";
	return 0;
}