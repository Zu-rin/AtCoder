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

void Eratos(vector<int> &p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (!p[i]) {
			for (j = i; j < p.size(); j += i) {
				p[j]++;
			}
		}
	}
	return;
}

int main(void) {
	int num, i, k, ans = 0;
	cin >> num >> k;
	vector<int> d(num + 1, 0);
	Eratos(d);
	for (int& x : d) {
		if (x >= k)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}