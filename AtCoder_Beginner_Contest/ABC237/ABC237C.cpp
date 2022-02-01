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
	int num, i, l = 0, r = 0;
	string s, t;
	cin >> s;
	rep(i, s.size()) {
		if (s[i] == 'a')
			l++;
		else
			break;
	}
	for (i = s.size() - 1; 0 <= i; i--) {
		if (s[i] == 'a')
			r++;
		else
			break;
	}
	t = s = string(max(0, r - l), 'a') + s;
	reverse(t.begin(), t.end());
	if (s == t)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}