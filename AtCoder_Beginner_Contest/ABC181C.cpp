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
typedef struct Point_Coordinates {
	ll x, y;
	Point_Coordinates friend operator-(const Point_Coordinates &l, const Point_Coordinates &r) {
		return { l.x - r.x, l.y - r.y };
	}
} point;

ll Cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

char Judge(const point& a, const point& b, const point& c) {
	point x = a - b, y = a - c;
	return Cross(x, y) == 0;
}

int main(void) {
	int num, i;
	cin >> num;
	vector<point> d(num);
	rep(i, num) {
		cin >> d[i].x >> d[i].y;
	}
	rep(i, num) {
		for (int j = i + 1; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				if (Judge(d[i], d[j], d[k])) {
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
	return 0;
}