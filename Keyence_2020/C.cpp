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

int main(void) {
	int num, i, k, s;
	cin >> num >> k >> s;
	rep(i, k)
		cout << s << "\n";
	rep(i, num - k)
		cout << s / 2 + 10 << "\n";
	return 0;
}