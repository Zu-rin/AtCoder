#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
typedef struct {
	int l, r;
} range;

int IniSize(int num) {
	// 要素数 num が収まるセグ木のサイズを返す
	int n = 1;
	while (n <= num)
		n <<= 1;
	return (n << 1) - 1;
}

void UpdateAdd(int pos, int n, vector<vector<int>>& d) {
	// 位置 pos(0-index) の値を n で更新する
	// セグ木のサイズは 2^n - 1
	int i = pos + (d.size() >> 1);
	d[i][n]++;
	while (i > 0) {
		i = (i - 1) >> 1;
		d[i][n]++;
	}
	return;
}

void UpdateSub(int pos, int n, vector<vector<int>>& d) {
	// 位置 pos(0-index) の値を n で更新する
	// セグ木のサイズは 2^n - 1
	int i = pos + (d.size() >> 1);
	d[i][n]--;
	while (i > 0) {
		i = (i - 1) >> 1;
		d[i][n]--;
	}
	return;
}

vector<int> Query(int pos, const range tag, range x, vector<vector<int>> &d) {
	// tag で指定した範囲に対して検索を行う
	// 外からの呼び出す時は Query(0, { a, b }, { 0, (num >> 1) + 1 }, st);
	// tag = [a, b)
	if (tag.r <= x.l || x.r <= tag.l)
		return vector<int>(26, 0);
	if (tag.l <= x.l && x.r <= tag.r)
		return d[pos];
	int i;
	vector<int> a, b;
	a = Query((pos << 1) + 1, tag, { x.l, (x.l + x.r + 1) >> 1 }, d);
	b = Query((pos << 1) + 2, tag, { (x.l + x.r + 1) >> 1, x.r }, d);
	rep(i, a.size())
		a[i] += b[i];
	return a;
}

int main(void) {
	int num, i, j, m, n = 1, k, a, b, ans;
	string s, c;
	cin >> num >> s >> m;
	num = IniSize(num);
	vector<int> d;
	vector<vector<int>> st(num, vector<int>(26, 0));
	rep(i, s.size()) {
		UpdateAdd(i, s[i] - 'a', st);
	}
	rep(i, m) {
		cin >> k >> a;
		a--;
		if (k - 1) {
			cin >> b;
			d = Query(0, { a, b }, { 0, (num >> 1) + 1 }, st);
			ans = 0;
			rep(j, d.size()) {
				if (d[j])
					ans++;
			}
			cout << ans << "\n";
		}
		else {
			cin >> c;
			UpdateSub(a, s[a] - 'a', st);
			UpdateAdd(a, c[0] - 'a', st);
			s[a] = c[0];
		}
	}
	return 0;
}