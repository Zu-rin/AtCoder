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
	int num, i, ok = true;
	string s, a;
	cin >> s >> a;
	if (s.size() + 1 == a.size()) {
		rep(i, s.size()) {
			if (s[i] != a[i]) {
				ok = false;
				break;
			}
		}
	}
	else
		ok = false;
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}