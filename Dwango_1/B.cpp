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
	int num, i = 0;
	ll l, ans = 0;
	string s;
	cin >> s;
	while (i < s.size()) {
		if (s[i] == '2') {
			l = 0;
			for (; i < s.size() - 1; i+=2) {
				if (s[i] != '2' || s[i + 1] != '5')
					break;
				l++;
			}
			ans += (l + 1) * l / 2;
		}
		i++;
	}
	cout << ans << "\n";
	return 0;
}