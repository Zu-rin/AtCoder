#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a, k = 0;
	cin >> num;
	for (i = 1; i <= num; i++) {
		cin >> a;
		if (a != i)
			k++;
	}
	if (k <= 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}