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
	int num, i, a, b, c, d, ao = 1;
	cin >> a >> b >> c >> d;
	vector<char> p(201, 1);
	Eratos(p);
	for (int i = a; i <= b; i++) {
		int ex = 0;
		for (int j = c; j <= d; j++) {
			if (p[i + j]) {
				ex = 1;
				break;
			}
		}
		if (!ex) {
			ao = 0;
			break;
		}
	}
	if (ao)
		printf("Aoki\n");
	else
		printf("Takahashi\n");
	return 0;
}