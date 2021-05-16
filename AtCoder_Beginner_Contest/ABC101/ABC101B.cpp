#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int S(int n) {
	int ans = 0;
	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main(void) {
	int n, s;
	cin >> n;
	s = S(n);
	if (n % s == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}