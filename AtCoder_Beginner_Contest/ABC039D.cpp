#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int h, w;

void Change(const vector<string> &a, vector<string> &b, const string &s) {
	int i, j, k;
	vector<int> dj = { 0, 1, 1, 1, 0, -1, -1, -1 };
	vector<int> di = { -1, -1, 0, 1, 1, 1, 0, -1 };
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (a[i][j] == s[0]) {
				for (k = 0; k < 8; k++) {
					if (i + di[k] >= 0 && i + di[k] < h && j + dj[k] >= 0 && j + dj[k] < w)
						b[i + di[k]][j + dj[k]] = s[0];
				}
			}
		}
	}
}

int main(void) {
	int num, i, ok = true;
	cin >> h >> w;
	string s;
	vector<string> a(h), b(h), c(h);
	for (i = 0; i < h; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	s = ".";
	Change(a, b, s);
	for (i = 0; i < h; i++) {
		c[i] = b[i];
	}
	s = "#";
	Change(b, c, s);
	for (i = 0; i < h; i++) {
		if (a[i] != c[i]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		printf("possible\n");
		for (i = 0; i < h; i++)
			cout << b[i] << "\n";
	}
	else
		printf("impossible\n");
	return 0;
}