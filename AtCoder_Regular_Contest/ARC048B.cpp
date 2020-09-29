#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, rmax = 100001;
	cin >> num;
	vector<vector<int>> d(rmax, vector<int>(3, 0));
	vector<int> s(rmax, 0), a(num), b(num);
	for (i = 0; i < num; i++) {
		cin >> a[i] >> b[i];
		d[a[i]][--b[i]]++;
	}
	s[0] = d[0][0] + d[0][1] + d[0][2];
	for (i = 1; i < rmax; i++) {
		s[i] = s[i - 1] + d[i][0] + d[i][1] + d[i][2];
	}
	for (i = 0; i < num; i++)
		printf("%d %d %d\n", s[a[i] - 1] + d[a[i]][(b[i] + 1) % 3], num - s[a[i]] + d[a[i]][(b[i] + 2) % 3], max(0, d[a[i]][b[i]] - 1));
	return 0;
}