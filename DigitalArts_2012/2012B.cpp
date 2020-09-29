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
	cin >> s;
	a = s;
	sort(s.begin(), s.end());
	if (s[0] == 'z') {
		if (s.size() == 20)
			ok = 0;
		else {
			s[0] = 'y';
			s += "a";
		}
	}
	else if (*s.rbegin() == 'a') {
		if (s.size() == 1)
			ok = 0;
		else
			s = 'a' + s.size() - 1;
	}
	else {
		(*s.rbegin())--;
		if (s.size() < 20)
			s += "a";
		else
			s[0]++;
	}
	if (ok) {
		if (s == a)
			sort(s.begin(), s.end());
		cout << s << "\n";
	}
	else
		printf("NO\n");
	return 0;
}