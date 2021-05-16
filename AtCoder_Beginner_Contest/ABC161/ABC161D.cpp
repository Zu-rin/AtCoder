#include <iostream>
#include <vector>
#include <string>
#include <map>
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

ll ma = 3234566667;
map<ll, int> d;

void Search(ll n) {
	if (n <= ma)
		d[n];
	else
		return;
	if (n % 10)
		Search(n * 10 + (n % 10) - 1);
	Search(n * 10 + (n % 10));
	if(n % 10 < 9)
		Search(n * 10 + (n % 10) + 1);
}

int main(void) {
	ll num, i, k;
	cin >> k;
	for (i = 1; i < 10; i++)
		Search(i);
	auto it = d.begin();
	rep(i, k - 1)
		it++;
	cout << (*it).first << "\n";
	return 0;
}