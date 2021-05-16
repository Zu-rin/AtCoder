#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
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

template <typename T>
class BIT {
	int size;
	vector<T> d;

public:
	BIT(int Size, T Val = 0) {
		size = Size;
		d.resize(size + 1);
		fill(d.begin(), d.end(), Val);
	}
	void add(int pos, T val) {
		while (pos <= size) {
			chmax(d[pos], val);
			pos += pos & -pos;
		}
	}
	T Max(int pos) {
		T ans = 0;
		while (pos) {
			chmax(ans, d[pos]);
			pos -= pos & -pos;
		}
		return ans;
	}
};

int main(void) {
	int num, i, ans, x, y;
	cin >> num;
	BIT<int> bit(1e5);
	map<int, vector<int>> mp;
	rep(i, num) {
		cin >> x >> y;
		mp[x].push_back(y);
	}
	for (auto & v : mp) {
		queue<pp> que;
		for (int a : v.second)
			que.push(pp(a, bit.Max(a - 1) + 1));
		while (!que.empty()) {
			pp x = que.front();
			que.pop();
			bit.add(x.first, x.second);
		}
	}
	cout << bit.Max(100000) << "\n";
	return 0;
}