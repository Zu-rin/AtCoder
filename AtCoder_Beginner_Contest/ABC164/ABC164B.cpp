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
	int num, i, a, b, c, d;
	cin >> a >> b >> c >> d;
	while (a > 0) {
		c -= b;
		if (c <= 0) {
			printf("Yes\n");
			return 0;
		}
		a -= d;
	}
	printf("No\n");
	return 0;
}