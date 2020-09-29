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

int Judge(vector<pp> & d) {
	int i, n = 0;
	rep(i, d.size()) {
		if (n + d[i].first < 0)
			return -1;
		n += d[i].second;
	}
	return n;
}

int main(void) {
	int num, i, j;
	string s;
	cin >> num;
	vector<pp> a, b;
	rep(i, num) {
		pp n = { 0,0 };
		cin >> s;
		rep(j, s.size()) {
			if (s[j] == '(')
				n.second++;
			else
				n.second--;
			chmin(n.first, n.second);
		}
		if (n.second >= 0)
			a.push_back(n);
		else
			b.push_back({ n.first - n.second, -n.second });
	}
	sort(a.begin(), a.end(), greater<pp>());
	sort(b.begin(), b.end(), greater<pp>());
	i = Judge(a);
	j = Judge(b);
	if (i == j && i >= 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}