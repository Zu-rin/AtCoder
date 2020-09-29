#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int main(void) {
	int i;
	ll a, b;
	string l = "", r = "";
	cin >> a >> b;
	a--;
	if (a == 0)
		l += "0";
	while (a > 0) {
		if (a & 1)
			l = "1" + l;
		else
			l = "0" + l;
		a >>= 1;
	}
	while (b > 0) {
		if (b & 1)
			r = "1" + r;
		else
			r = "0" + r;
		b >>= 1;
	}
	vector<vector<ll>> L(2, vector<ll>(l.size() + 1, 0)), R(2, vector<ll>(r.size() + 1 , 0));
	L[1][0] = 1;
	R[1][0] = 1;
	for (i = 0; i < l.size(); i++) {
		if (l[i] == '1') {
			L[1][i + 1] = L[0][i] << 1;
		}
		L[0][i + 1] += (L[0][i] << 1) + 1;
		L[1][i + 1] += (L[1][i] << 1) + 2;
		L[0][i + 1] %= MOD;
		L[1][i + 1] %= MOD;
	}
	for (i = 0; i < r.size(); i++) {
		if (r[i] == '1') {
			R[1][i + 1] = R[0][i] << 1;
		}
		R[0][i + 1] += (R[0][i] << 1) + 1;
		R[1][i + 1] += (R[1][i] << 1) + 2;
		R[0][i + 1] %= MOD;
		R[1][i + 1] %= MOD;
	}
	a = R[0][r.size() - 1] + R[1][r.size() - 1];
	a -= L[0][l.size() - 1] + L[1][l.size() - 1];
	a %= MOD;
	cout << a << "\n";
	return 0;
}