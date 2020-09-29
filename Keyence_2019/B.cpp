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
	int num, i, a = 0, b = 0;
	string s, k = "keyence";
	cin >> s;
	rep(i, 7) {
		if (s[i] != k[i])
			break;
		a++;
	}
	rep(i, 7) {
		if (s[s.size() - 1 - i] != k[6 - i])
			break;
		b++;
	}
	if (a + b >= 7)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}