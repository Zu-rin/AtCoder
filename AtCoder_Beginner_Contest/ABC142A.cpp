#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	double ans;
	cin >> num;
	if (num % 2 == 0)
		ans = 0.5;
	else
		ans = (double)((num / 2) + 1) / (double)num;
	printf("%.9lf\n", ans);
	return 0;
}