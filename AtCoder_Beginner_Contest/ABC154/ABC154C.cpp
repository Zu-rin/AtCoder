#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ok = true;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	sort(d.begin(), d.end());
	rep(i, num - 1) {
		if (d[i] == d[i + 1]) {
			ok = false;
			break;
		}
	}
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}