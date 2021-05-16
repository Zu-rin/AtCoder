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

int Judge(const string & s) {
	if (s[0] == '0' || s[s.size() - 1] == '1')
		return 0;
	int i;
	rep(i, s.size() >> 1) {
		if (s[i] != s[s.size() - 2 - i])
			return 0;
	}
	return 1;
}

void print(int a, int b) {
	printf("%d %d\n", a, b);
	return;
}

int main(void) {
	int num, i, j, k = 0, t = 1, n = 1;
	list<int> d;
	string s;
	cin >> s;
	if (!Judge(s)) {
		printf("-1\n");
		return 0;
	}
	s[s.size() - 1] = '1';
	for (i = 1; i < s.size(); i++) {
		if (s[i] == '1') {
			print(t, ++n);
			t = n;
			rep(j, k) {
				print(t, ++n);
			}
			k = 0;
		}
		else
			k++;
	}
	return 0;
}