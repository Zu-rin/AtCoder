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
	int num, i, h, ok = 0, a, s = 0;
	cin >> h >> num;
	rep(i, num) {
		cin >> a;
		s += a;
	}
	if (s >= h)
		ok = true;
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}