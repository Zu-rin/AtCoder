#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
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
	double n, a = 100;
	cin >> n;
	for (i = 1; i < 10000000; i++) {
		a *= 1.01;
		a = floor(a);
		if (a >= n)
			break;
	}
	cout << i << "\n";
	return 0;
}