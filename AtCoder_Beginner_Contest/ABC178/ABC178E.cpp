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

class Solver {
	int maxA, maxB, minA, minB;

public:
	Solver() {
		maxA = maxB = -INF;
		minA = minB = INF;
	}

	void update(int x, int y) {
		int a = x + y, b = x - y;
		chmax(maxA, a);
		chmax(maxB, b);
		chmin(minA, a);
		chmin(minB, b);
	}

	int Ans() {
		return max(maxA - minA, maxB - minB);
	}
};

int main(void) {
	int num, i, x, y;
	Solver d;
	cin >> num;
	rep(i, num) {
		cin >> x >> y;
		d.update(x, y);
	}
	cout << d.Ans() << "\n";
	return 0;
}