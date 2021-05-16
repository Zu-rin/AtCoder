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

int h, w, A, B;

int DFS(int p = 0, int v = 0, int a = 0, int b = 0) {
	if (p == h * w)
		return 1;
	if (v & (1 << p))
		return DFS(p + 1, v, a, b);
	int ans = 0;
	v |= 1 << p;
	if (b < B)
		ans += DFS(p + 1, v, a, b + 1);
	if (a < A) {
		if ((p + 1) % w)
			ans += DFS(p + 1, v | (1 << (p + 1)), a + 1, b);
		if (p < (h - 1) * w)
			ans += DFS(p + 1, v | (1 << (p + w)), a + 1, b);
	}
	return ans;
}

int main(void) {
	cin >> h >> w >> A >> B;
	cout << DFS() << "\n";
	return 0;
}