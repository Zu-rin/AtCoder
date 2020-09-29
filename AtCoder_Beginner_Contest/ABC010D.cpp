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

class MaxFlow {
	struct Edge {
		int to, rev;
		ll cap;
		// 接続先, 容量, 逆辺
		Edge(int t, ll c, int r) {
			to = t;
			cap = c;
			rev = r;
		}
	};
	int num;
	// 0-indexed
	vector<vector<Edge>> d;

public:
	MaxFlow(int n) {
		num = n;
		d.resize(num);
	}

	void AddEdge(int from, int to, ll cap) {
		d[from].push_back(Edge(to, cap, d[to].size()));
		// 無向グラフ
		d[to].push_back(Edge(from, cap, d[from].size() - 1));
		// 有向グラフ
		//d[to].push_back(Edge(from, 0, d[from].size() - 1));
	}

	ll DFS(int n, const int g, ll f, vector<char>& used) {
		if (n == g)
			return f;
		int i;
		used[n] = 1;
		rep(i, d[n].size()) {
			Edge& e = d[n][i];
			if (!used[e.to] && e.cap > 0) {
				int x = DFS(e.to, g, min(f, e.cap), used);
				if (x > 0) {
					e.cap -= x;
					d[e.to][e.rev].cap += x;
					return x;
				}
			}
		}
		return 0;
	}

	ll Solve(int s, int g) {
		ll ans = 0;
		while (true) {
			vector<char> used(num, 0);
			ll f = DFS(s, g, 1ll << 60, used);
			if (!f)
				break;
			ans += f;
		}
		return ans;
	}
};

int main(void) {
	int num, i, g, m, a, b;
	cin >> num >> g >> m;
	MaxFlow d(num + 1);
	rep(i, g) {
		cin >> a;
		d.AddEdge(a, num, 1);
	}
	rep(i, m) {
		cin >> a >> b;
		d.AddEdge(a, b, 1);
	}
	ll ans = d.Solve(0, num);
	cout << ans << "\n";
	return 0;
}