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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void) {
	int num, i;
	cin >> num;
	set<pp> st;
	vector<int> x(num), y(num);
	rep(i, num)
		cin >> x[i] >> y[i];
	rep(i, num) {
		for (int j = i + 1; j < num; j++) {
			int a = x[i] - x[j], b = y[i] - y[j];
			int g = gcd(a, b);
			st.insert(pp(a / g, b / g));
			st.insert(pp(-a / g, -b / g));
		}
	}
	cout << st.size() << "\n";
	return 0;
}