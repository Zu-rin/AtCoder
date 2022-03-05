#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
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
	int num, i, s = 0, x;
	cin >> num;
	stack<pp> st;
	st.push(pp(0, 1));
	rep(i, num) {
		cin >> x;
		pp a = st.top();
		if (a.first == x) {
			st.pop();
			if (a.first == a.second + 1) {
				s -= a.second;
			}
			else {
				a.second++;
				st.push(a);
				s++;
			}
		}
		else {
			st.push(pp(x, 1));
			s++;
		}
		cout << s << "\n";
	}
	return 0;
}