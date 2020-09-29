#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 63

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, E, s = 0, a, b;
	ll c;
	cin >> num >> E;
	vector<tuple<int, int, ll>> edge(E);
	vector<ll> ans(num, INF);
	rep(i, E) {
		cin >> a >> b >> c;
		edge[i] = make_tuple(a - 1, b - 1, c);
	}
	ans[s] = 0;
	rep(a, E) {
		rep(i, E) {
			if (ans[get<0>(edge[i])] != INF)
				chmax(ans[get<1>(edge[i])],  ans[get<0>(edge[i])] + get<2>(edge[i]));
		}
	}
	c = ans[num - 1];
	rep(i, E) {
		if (ans[get<0>(edge[i])] != INF)
			chmax(ans[get<1>(edge[i])], ans[get<0>(edge[i])] + get<2>(edge[i]));
	}
	c -= ans[num - 1];
	if (c)
		printf("inf\n");
	else
		cout << ans[num - 1] << "\n";
	return 0;
}