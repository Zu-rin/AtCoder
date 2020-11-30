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

int a, b, c;
double dp[101][101][101] = { 0.0 };

double Search(int x, int y, int z) {
	if (dp[x][y][z] >= 0.0) {
		return dp[x][y][z];
	}
	double ans = 0, sum = (double)(x + y + z);
	ans += (double)x * (Search(x + 1, y, z) + 1.0);
	ans += (double)y * (Search(x, y + 1, z) + 1.0);
	ans += (double)z * (Search(x, y, z + 1) + 1.0);
	return dp[x][y][z] = (ans / sum);
}

int main(void) {
	int num, i, j, k;
	cin >> a >> b >> c;
	rep(i, 100) {
		rep(j, 100) {
			rep(k, 100)
				dp[i][j][k] = -1;
		}
	}
	printf("%.10lf\n", Search(a, b, c));
	return 0;
}