#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int h, w, num, i, ans;
	cin >> h >> w;
	ans = (h - 1) * (w - 1) * 2;
	ans += h - 1;
	ans += w - 1;
	cout << ans << "\n";
	return 0;
}