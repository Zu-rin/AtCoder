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

int main(void) {
	int num, i = 0, j, ans = 0;
	string s;
	cin >> num >> s;
	j = num - 1;
	while (true) {
		while (i < num && s[i] == 'R')
			i++;
		while (0 <= j && s[j] == 'W')
			j--;
		if (i >= j)
			break;
		i++;
		j--;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}