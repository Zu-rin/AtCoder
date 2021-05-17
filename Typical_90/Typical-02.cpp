#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
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

string Bracket(int n, int num) {
	int x = 0;
	string ans = "";
	for (int i = num - 1; i >= 0; i--) {
		if (n & (1 << i)) {
			if (x == 0)
				return "";
			x--;
			ans += ")";
		}
		else {
			x++;
			ans += "(";
		}
	}
	if (x)
		return "";
	return ans + "\n";
}

int main(void) {
	int num, i;
	cin >> num;
	if (num & 1)
		return 0;
	set<string> st;
	for (int i = (1 << (num / 2)) - 1; i < (1 << (num - 1)); i++) {
		cout << Bracket(i, num);
	}
	return 0;
}