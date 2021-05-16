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

int Solve(string & s) {
	if (s == string(s.size(), 'a'))
		return -1;
	if ("atcoder" < s)
		return 0;
	int i;
	rep(i, s.size()) {
		if (s[i] != 'a')
			break;
	}
	if (s[i] > 't')
		return i - 1;
	return i;
}

int main(void) {
	int num, i;
	string s;
	cin >> num;
	rep(i, num) {
		cin >> s;
		cout << Solve(s) << "\n";
	}
	return 0;
}