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

void Swap(int x, vector<int> &d, vector<int> &p) {
	swap(d[x], d[x - 1]);
	p[d[x]] = x;
	p[d[x - 1]] = x - 1;
}

int Solve(vector<int> &d, vector<int> &p, vector<int> &ans) {
	int i;
	vector<char> ok(d.size(), 1);
	rep(i, d.size()) {
		while (p[i] != i) {
			if (ok[p[i]]) {
				ans.push_back(p[i]);
				ok[p[i]] = 0;
				Swap(p[i], d, p);
			}
			else return 0;
		}
	}
	for (i = 1; i < ok.size(); i++) {
		if (ok[i])
			return 0;
	}
	return 1;
}

int main(void) {
	int num, i;
	cin >> num;
	vector<int> d(num), p(num), ans;
	rep(i, num) {
		cin >> d[i];
		p[--d[i]] = i;
	}
	if (Solve(d, p, ans)) {
		for (int a : ans)
			cout << a << "\n";
	}
	else
		printf("-1\n");
	return 0;
}