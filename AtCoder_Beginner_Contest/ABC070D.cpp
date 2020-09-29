#include <iostream>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;

void Search(const int n, vector<list<pair<int, int>>> &d, vector<ll> &ans) {
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
		if (ans[(*itr).first] == -1) {
			ans[(*itr).first] = ans[n] + (*itr).second;
			Search((*itr).first, d, ans);
		}
	}
	return;
}

int main(void) {
	int num, i = 0, a, b, c, q, k;
	cin >> num;
	vector<list<pair<int, int>>> d(num + 1);
	vector<ll> ans(num + 1, -1);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d%d%d", &a, &b, &c);
		d[a].push_back(make_pair(b, c));
		d[b].push_back(make_pair(a, c));
	}
	cin >> q >> k;
	ans[k] = 0;
	Search(k, d, ans);
	for (i = 0; i < q; i++) {
		scanf_s("%d%d", &a, &b);
		cout << ans[a] + ans[b] << "\n";
	}
	return 0;
}