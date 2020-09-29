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

int IsDict(int & n, const string & s) {
	int ans = -1, b = n;
	for (n++; s[n] != '}'; n++) {
		if (s[n] == ':')
			ans = 1;
		else if (ans == -1 && s[n] == ',')
			ans = 0;
		else if (s[n] == '{')
			IsDict(n, s);
	}
	if (b + 1 != n && ans == -1)
		ans = 0;
	return ans;
}

int main(void) {
	int num, i = 0;
	string s;
	cin >> s;
	if (IsDict(i, s))
		printf("dict\n");
	else
		printf("set\n");
	return 0;
}