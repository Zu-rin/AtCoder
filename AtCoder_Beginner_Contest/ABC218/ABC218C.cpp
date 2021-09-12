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

typedef struct Figure {
	vector<string> s;

	Figure(int N) {
		int i;
		s.resize(N);
		rep(i, N)
			cin >> s[i];
		trim();
	}

	void rotate() {
		int i, j, h = s.size(),  w = s[0].size();
		vector<string> ans(w, string(h, 0));
		rep(i, h) {
			rep(j, w) {
				ans[j][h - 1 - i] = s[i][j];
			}
		}
		s = ans;
	}

	void trim() {
		for (int t = 0; t < 4; t++) {
			int i = 0;
			while (s[i] == string(s[i].size(), '.'))
				i++;
			s = vector<string>{ s.begin() + i, s.end() };
			rotate();
		}
	}
} fig;

int main(void) {
	int num, i, h, w, ok = 0;
	cin >> num;
	fig a(num), b(num);
	rep(i, 4) {
		if (a.s == b.s) {
			ok = 1;
			break;
		}
		b.rotate();
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}