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
	int k, l = -1, r = -1, ans = 0;
	string s;
	cin >> s >> k;
	while (true) {
		chmax(ans, r - l);
		if (r == s.size() - 1)
			break;
		if (s[r + 1] == '.') {
			if (k) {
				k--;
				r++;
			}
			else {
				l++;
				if (s[l] == '.') {
					if (l <= r)
						k++;
					else
						r = l;
				}
			}
		}
		else if (s[r + 1] == 'X') {
			r++;
		}
	}
	cout << ans << "\n";
	return 0;
}