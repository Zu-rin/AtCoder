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

int main(void) {
	int num, i;
	string s;
	set<string> st;
	cin >> num;
	for(i = 1; i <= num; i++) {
		cin >> s;
		if (!st.count(s)) {
			cout << i << "\n";
			st.insert(s);
		}
	}
	return 0;
}