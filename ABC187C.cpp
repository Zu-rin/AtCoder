#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
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
	int num, i;
	string s;
	set<string> st;
	map<string, int> mp;
	cin >> num;
	rep(i, num) {
		cin >> s;
		st.insert(s);
	}
	for (string t : st) {
		if (t[0] == '!')
			t = t.substr(1);
		if (mp[t] == 1) {
			cout << t << "\n";
			return 0;
		}
		mp[t]++;
	}
	printf("satisfiable\n");
	return 0;
}