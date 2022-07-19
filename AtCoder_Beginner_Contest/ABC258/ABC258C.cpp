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
	int num, i, q, k, x, a = 0;
	string s;
	cin >> num >> q >> s;
	rep(i, q) {
		cin >> k >> x;
		if (k == 1) {
			a -= x;
			if (a < 0)
				a += num;
		}
		else {
			cout << s[(a + x - 1) % num] << "\n";
		}
	}
	return 0;
}