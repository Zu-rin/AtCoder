#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

vector<int> a;

void Search(int n, vector<int> ok) {
	int i, fin = true;
	rep(i, ok.size()) {
		if (ok[i]) {
			fin = false;
			ok[i] = false;
			Search(10 * n + i + 1, ok);
			ok[i] = true;
		}
	}
	if (fin) {
		a.push_back(n);
	}
	return;
}

int main(void) {
	int num, i, b, x = 0, y = 0;
	cin >> num;
	vector<int> l(num);
	rep(i, num)
		l[i] = i + 1;
	rep(i, num) {
		cin >> b;
		x = 10 * x + b;
	}
	rep(i, num) {
		cin >> b;
		y = 10 * y + b;
	}
	Search(0, l);
	sort(a.begin(), a.end());
	rep(i, a.size()) {
		if (a[i] == x) {
			x = i;
			break;
		}
	}
	rep(i, a.size()) {
		if (a[i] == y) {
			y = i;
			break;
		}
	}
	cout << abs(x - y) << "\n";
	return 0;
}