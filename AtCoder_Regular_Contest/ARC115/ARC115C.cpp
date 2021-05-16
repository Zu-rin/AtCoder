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

void Eratos(vector<char> &p) {
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i < p.size(); i++) {
		if (p[i]) {
			for (j = i << 1; j < p.size(); j += i)
				p[j] = 0;
		}
	}
	return;
}

int main(void) {
	int num, i, j;
	cin >> num;
	vector<char> d(num + 1, 1);
	vector<int> ans(num + 1, 1), p;
	Eratos(d);
	ans[1] = 1;
	for (i = 2; i <= num; i++) {
		if (d[i])
			p.push_back(i);
		int buf = i;
		for (int x : p) {
			while (buf % x == 0) {
				buf /= x;
				ans[i]++;
			}
		}
	}
	for (i = 1; i < num; i++)
		cout << ans[i] << " ";
	cout << ans[i] << "\n";
	return 0;
}