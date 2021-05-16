#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, a, b, i;
	cin >> num >> a >> b;
	if (num <= a || a > b)
		printf("Takahashi\n");
	else if (a < b)
		printf("Aoki\n");
	else {
		num %= a + 1;
		if (num)
			printf("Takahashi\n");
		else
			printf("Aoki\n");
	}
	return 0;
}