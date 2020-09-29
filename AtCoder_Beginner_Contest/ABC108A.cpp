#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, ans;
	cin >> num;
	ans = num >> 1;
	ans *= ans + (num & 1);
	cout << ans << "\n";
	return 0;
}