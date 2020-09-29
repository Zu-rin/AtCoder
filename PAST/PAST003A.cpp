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

string Change(string & s) {
	string ans = s;
	int i;
	rep(i, ans.size()) {
		if ('A' <= ans[i] && ans[i] <= 'Z')
			ans[i] = 'a' + ans[i] - 'A';
	}
	return ans;
}

int main(void) {
	int num, i;
	string s, t;
	cin >> s >> t;
	if (s == t)
		printf("same\n");
	else if (Change(s) == Change(t))
		printf("case-insensitive\n");
	else
		printf("different\n");
	return 0;
}