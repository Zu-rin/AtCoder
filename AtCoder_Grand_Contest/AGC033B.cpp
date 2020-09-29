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
	int num, i, j, h, w, sa, sb, al, ar, bl, br, ok = true;
	string s, t;
	cin >> h >> w >> num >> sa >> sb;
	cin >> s >> t;
	al = bl = 1;
	ar = h;
	br = w;
	for (i = num - 1; i >= 0; i--) {
		if (t[i] == 'U')
			ar = min(h, ar + 1);
		else if (t[i] == 'D')
			al = max(1, al - 1);
		else if (t[i] == 'L')
			br = min(w, br + 1);
		else
			bl = max(1, bl - 1);
		if (s[i] == 'U')
			al++;
		else if (s[i] == 'D')
			ar--;
		else if (s[i] == 'L')
			bl++;
		else
			br--;
		if (ar < al || br < bl) {
			ok = false;
			break;
		}
	}
	if (sa < al || ar < sa || sb < bl || br < sb)
		ok = false;
	if (ok)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}