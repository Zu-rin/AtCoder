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
typedef struct str{
	int a, b, c, d;
	bool operator<(str r) {
		return d < r.d;
	}
} tp;

vector<tp> A;
int Judge(vector<int>& d) {
	int i, ans = 0;
	rep(i, A.size()) {
		if (d[A[i].b] - d[A[i].a] == A[i].c)
			ans += A[i].d;
	}
	return ans;
}

int Search(int n, vector<int> d, int mi, int ma) {
	if (n == d.size()) {
		return Judge(d);
	}
	int ans = 0;
	for (int i = mi; i <= ma; i++) {
		d[n] = i;
		chmax(ans, Search(n + 1, d, i, ma));
	}
	return ans;
}

int main(void) {
	int num, i, ma, q, ans;
	cin >> num >> ma >> q;
	A.resize(q);
	rep(i, q) {
		cin >> A[i].a >> A[i].b >> A[i].c >> A[i].d;
		A[i].a--;
		A[i].b--;
	}
	vector<int> d(num);
	ans = Search(0, d, 1, ma);
	cout << ans << "\n";
	return 0;
}