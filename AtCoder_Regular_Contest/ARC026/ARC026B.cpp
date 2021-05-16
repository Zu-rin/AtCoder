#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	ll num, n, i, a = 1;
	cin >> num;
	if (num == 1) {
		printf("Deficient\n");
		return 0;
	}
	n = sqrt(num);
	for (i = 2; i <= n; i++) {
		if (num % i == 0) {
			if (i * i != num)
				a += num / i + i;
			else
				a += i;
		}
	}
	if (a < num)
		printf("Deficient\n");
	else if(a == num)
		printf("Perfect\n");
	else
		printf("Abundant\n");
	return 0;
}