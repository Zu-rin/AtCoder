#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int a, b, i;
	cin >> a >> b;
	if (a > 0 || b < 0)
		cout << b - a << "\n";
	else
		cout << b - a - 1 << "\n";
	return 0;
}