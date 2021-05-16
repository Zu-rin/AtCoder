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
	string a, b;
	cin >> a >> b;
	a[0] += 'a' - 'A';
	if (a == b)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}