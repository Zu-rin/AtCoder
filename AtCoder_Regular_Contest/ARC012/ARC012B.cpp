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
	double a, b, l;
	cin >> num >> a >> b >> l;
	for (i = 0; i < num; i++) {
		l = b * l / a;
	}
	printf("%.10lf\n", l);
	return 0;
}