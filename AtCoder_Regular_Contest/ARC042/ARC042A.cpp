#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
	int num, m, i, a;
	stack<int> st;
	cin >> num >> m;
	vector<int> ok(num + 1, true);
	for (i = num; i > 0; i--)
		st.push(i);
	rep(i, m) {
		cin >> a;
		st.push(a);
	}
	while (!st.empty()) {
		if (ok[st.top()]) {
			cout << st.top() << "\n";
			ok[st.top()] = 0;
		}
		st.pop();
	}
	return 0;
}