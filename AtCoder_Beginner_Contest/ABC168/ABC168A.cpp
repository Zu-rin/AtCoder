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
	int num, i;
	cin >> num;
	num %= 10;
	if (num == 3)
		printf("bon\n");
	else if (num == 0 || num == 1 || num == 6 || num == 8)
		printf("pon\n");
	else
		printf("hon\n");
	return 0;
}