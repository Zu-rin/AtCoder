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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void Eratos(vector<char>& p) {
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

int Existcp(vector<int> &d) {
	int i, j;
	vector<char> a(1000001, 0), p(1000001, 1);
	Eratos(p);
	rep(i, d.size()) {
		if (a[d[i]] && d[i] > 1)
			return true;
		a[d[i]] = 1;
	}
	rep(i, p.size()) {
		if (p[i]) {
			int s = 0;
			for (j = i; j < a.size(); j += i) {
				if (a[j])
					s++;
			}
			if (s > 1)
				return true;
		}
	}
	return 0;
}

int main(void) {
	int num, i, g;
	cin >> num;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	g = d[num - 1];
	rep(i, num - 1)
		g = gcd(g, d[i]);
	if (g > 1)
		printf("not coprime\n");
	else if (Existcp(d))
		printf("setwise coprime");
	else
		printf("pairwise coprime");
	return 0;
}