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
	cin >> num;
	vector<int> d(num);
	set<int> st;
	rep(i, num) {
		cin >> d[i];
		st.insert(i);
	}
	st.insert(num);
	rep(i, num) {
		st.erase(d[i]);
		cout << *st.begin() << "\n";
	}
	return 0;
}