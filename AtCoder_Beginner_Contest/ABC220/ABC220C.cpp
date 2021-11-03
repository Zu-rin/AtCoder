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

// n�ȉ��̗v�f�̒��ōő�̓Y������Ԃ�
// n < min(d) : -1
// max(d) < n : d.size() - 1
template<typename T>
int Binary_search(T n, vector<T> &d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i;
	ll x, s = 0, ans;
	cin >> num;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	cin >> x;
	rep(i, num - 1)
		d[i + 1] += d[i];
	ans = x / d[num - 1] * num;
	x %= d[num - 1];
	ans += Binary_search(x, d) + 2;
	cout << ans << "\n";
	return 0;
}