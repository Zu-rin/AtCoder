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

int main(void) {
	int i, t;
	ll n;
	cin >> t;
	rep(i, t) {
		scanf("%lld", &n);
		if (n & 1ll)
			printf("Odd\n");
		else if (!(n & 3ll))
			printf("Even\n");
		else
			printf("Same\n");
	}
	return 0;
}