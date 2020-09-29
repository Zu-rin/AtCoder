#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, ok = true;
	string s;
	cin >> s;
	if (s.size() & 1)
		ok = false;
	for (i = 0; i < s.size(); i+=2) {
		if (s[i] != 'h' || s[i + 1] != 'i')
			ok = false;
	}
	if (ok)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}