#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

void Solve() {
	int num, i;
	string s;
	cin >> num;
	vector<ll> d(num);
	set<ll> st;
	rep(i, num) {
		cin >> d[i];
	}
	cin >> s;
	for (i = num - 1; i >= 0; i--) {
		for(auto it = st.rbegin(); it != st.rend(); it++) {
			chmin(d[i], d[i] ^ *it);
		}
		if (d[i]) {
			if (s[i] == '1') {
				printf("1\n");
				return;
			}
			st.insert(d[i]);
		}
	}
	printf("0\n");
	return;
}

int main(void) {
	int num;
	cin >> num;
	while (num--) {
		Solve();
	}
	return 0;
}