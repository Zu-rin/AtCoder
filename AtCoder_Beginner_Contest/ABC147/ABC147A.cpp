#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 22)
		printf("bust\n");
	else
		printf("win\n");
	return 0;
}