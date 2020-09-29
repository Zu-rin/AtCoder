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
	int num, i, j, a, b, c;
	cin >> num;
	ll dp[101][4][4][4] = { 0 }, ans = 0;
	dp[0][0][0][0] = 1;
	for(i = 1; i <= num; i++) {
		rep(a, 4) {
			rep(b, 4) {
				rep(c, 4) {
					dp[i][b][c][0] += dp[i - 1][a][b][c];
					dp[i][b][c][1] += dp[i - 1][a][b][c];
					if(b != 1 || c != 3)
						dp[i][b][c][2] += dp[i - 1][a][b][c];
					if(!((min(b, c) == 1 && max(b, c) == 2) || (a == 1 && (b == 2 || c == 2))))
						dp[i][b][c][3] += dp[i - 1][a][b][c];
					rep(j, 4)
						dp[i][b][c][j] %= MOD;
				}
			}
		}
	}
	rep(a, 4) {
		rep(b, 4) {
			rep(c, 4) {
				ans += dp[num][a][b][c];
			}
		}
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}