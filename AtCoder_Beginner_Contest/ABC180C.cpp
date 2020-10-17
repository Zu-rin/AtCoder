#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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
	ll num, i;
	list<ll> ans;
	cin >> num;
	for (i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			if (i * i == num)
				cout << i << "\n";
			else {
				cout << i << "\n";
				ans.push_front(num / i);
			}
		}
	}
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << "\n";
	}
	return 0;
}