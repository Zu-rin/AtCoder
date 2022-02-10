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

int a;

int Search(int n) {
	vector<int> d(1e6, -1);
	queue<int> que;
	d[n] = 0;
	que.push(n);
	while (!que.empty()) {
		n = que.front();
		que.pop();
		if (n % a == 0 and d[n / a] < 0) {
			d[n / a] = d[n] + 1;
			que.push(n / a);
		}
		string s = to_string(n);
		if (n >= 0 and s[1] != '0') {
			int nx = stoi(s.substr(1) + s[0]);
			if (d[nx] < 0) {
				d[nx] = d[n] + 1;
				que.push(nx);
			}
		}
	}
	return d[1];
}

int main(void) {
	int n, i;
	cin >> a >> n;
	cout << Search(n);
	return 0;
}