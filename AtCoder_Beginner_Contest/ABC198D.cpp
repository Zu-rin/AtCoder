#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll to_int(map<char, int> &mp, string & s) {
	if (mp[s[0]] == 0)
		return -1e10;
	ll ans = 0;
	for (char c : s) {
		ans *= 10;
		ans += mp[c];
	}
	return ans;
}

int Judge(map<char, int> &mp, vector<int> &d, string & a, string & b, string & c) {
	int i = 0;
	for (auto& it : mp) {
		it.second = d[i++];
	}
	ll x = to_int(mp, a);
	ll y = to_int(mp, b);
	ll z = to_int(mp, c);
	return x + y == z;
}

void ans(map<char, int>& mp) {
	return;
}

template <class S, class... T>
void ans(map<char, int>& mp, S &s, T &... t) {
	for (char c : s) {
		cout << mp[c];
	}
	printf("\n");
	ans(mp, t...);
	return;
}

int main(void) {
	string a, b, c;
	map<char, int> mp;
	vector<int> d(10);
	iota(d.begin(), d.end(), 0);
	cin >> a >> b >> c;
	for (char x : a + b + c)
		mp[x];
	if (mp.size() > 10) {
		printf("UNSOLVABLE\n");
		return 0;
	}
	do {
		if (Judge(mp, d, a, b, c)) {
			ans(mp, a, b, c);
			return 0;
		}
	} while (next_permutation(d.begin(), d.end()));
	printf("UNSOLVABLE\n");
	return 0;
}