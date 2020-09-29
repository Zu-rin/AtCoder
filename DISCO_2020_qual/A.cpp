#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
 
int Func(int a) {
	if (a == 1)
		return 300000;
	if (a == 2)
		return 200000;
	if (a == 3)
		return 100000;
	else
		return 0;
}
 
int main(void) {
	int ans = 0, i, a, b;
	cin >> a >> b;
	ans += Func(a);
	ans += Func(b);
	if (a == 1 && b == 1)
		ans += 400000;
	cout << ans << "\n";
	return 0;
}