#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int n, i, j, k, ans = 0;
	cin >> n;
	vector<string> s(n);
	rep(i, n)
		cin >> s[i];
	rep(i, n) {
		for (j = n - 1; j >= 0; j--) {
			if (s[i][j] == '.') {
				ans++;
				rep(k, j + 1)
					s[i][k] = 'o';
				if (i < n - 1) {
					for (; j < n; j++)
						s[i + 1][j] = 'o';
				}
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}