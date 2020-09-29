#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int x, y, r, num, i, lx, rx, ly, ry;
	cin >> x >> y >> r;
	cin >> lx >> ly >> rx >> ry;
	if (lx <= x - r && rx >= x + r && ly <= y - r && ry >= y + r)
		printf("NO\nYES\n");
	else {
		lx -= x;
		rx -= x;
		ly -= y;
		ry -= y;
		lx *= lx;
		ly *= ly;
		rx *= rx;
		ry *= ry;
		if(max(lx, rx) + max(ly, ry) < r * r)
			printf("YES\nNO\n");
		else
			printf("YES\nYES\n");
	}
	return 0;
}