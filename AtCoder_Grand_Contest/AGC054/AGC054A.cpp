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
	int num, i;
	string s;
	cin >> num >> s;
	if (s[0] != s[num - 1]) {
		printf("1\n");
		return 0;
	}
	rep(i, num - 2) {
		if (s[i] != s[0] and s[i + 1] != s[0]) {
			printf("2\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}