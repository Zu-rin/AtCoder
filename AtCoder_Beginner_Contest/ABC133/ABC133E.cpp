#include <iostream>
#include <list>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int num, k;

ll Search(int n, int par, vector<list<int>>&d) {
	int a = k - 2;
	ll ans = 1;
	if (n == 1)
		a++;
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++) {
		if ((*itr) != par) {
			ans *= a--;
			ans %= MOD;
			ans *= Search((*itr), n, d);
			ans %= MOD;
		}
	}
	return ans;
}


int main(void) {
	int a, b, i;
	cin >> num >> k;
	ll ans = k;
	vector<list<int>> d(num + 1);
	for (i = 0; i < num - 1; i++) {
		scanf_s("%d%d", &a, &b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	ans *= Search(1, 0, d);
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}