#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, x, k;
	cin >> x;
	k = x % 100;
	x /= 100;
	x -= k / 5;
	k %= 5;
	if (k > 0)
		x--;
	if (x >= 0)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}