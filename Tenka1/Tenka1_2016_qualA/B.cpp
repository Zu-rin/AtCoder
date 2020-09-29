#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#define MAX 1 << 30

using namespace std;
typedef long long ll;

int ans = 0;

int Search(int n, vector<list<int>> &d, vector<int> &c) {
	int a = MAX, k = 0;
	for (auto itr = d[n].begin(); itr != d[n].end(); itr++, k++)
		a = min(a, Search(*itr, d, c));
	if (k == 0)
		return c[n];
	ans -= a * (k - 1);
	return a;
}

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	vector<list<int>> d(num);
	vector<int> c(num, i);
	for (i = 1; i < num; i++) {
		scanf_s("%d", &a);
		d[a].push_back(i);
	}
	for (i = 0; i < m; i++) {
		scanf_s("%d", &a);
		scanf_s("%d", &c[a]);
		ans += c[a];
	}
	for(auto itr = d[0].begin(); itr != d[0].end(); itr++)
		Search(*itr, d, c);
	cout << ans << "\n";
	return 0;
}