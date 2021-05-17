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

int len;

int Judge(vector<int> &d, int k, int n) {
	int i, pos = 0, t = 0;
	for (int& x : d) {
		if (n <= x - pos) {
			pos = x;
			t++;
			if (t == k)
				break;
		}
	}
	if (t < k)
		return 0;
	return n <= len - pos;
}

int Search(vector<int> &d, int k, int l = 1, int r = INF) {
	if (l + 1 == r)
		return l;
	int p = (l + r) / 2;
	if (Judge(d, k, p))
		return Search(d, k, p, r);
	else
		return Search(d, k, l, p);
}

int main(void) {
	int num, k, i;
	cin >> num >> len >> k;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	cout << Search(d, k) << "\n";
	return 0;
}