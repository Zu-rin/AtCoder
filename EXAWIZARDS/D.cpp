#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int KJ(const int num) {
	int i = 2;
	long int ans = 1;
	for (; i <= num; i++)
		ans *= i;
	return ans;
}

int main(void) {
	int num, X, i = 0, x, r = 0;
	long int rate;
	cin >> num >> X;
	vector<int> s(num);
	for (; i < num; i++)
		scanf_s("&d", &s[i]);
	sort(s.begin(), s.end());
	for (i = num - 1; i >= 0; i--, r++) {
		x = X % s[i];
		
	}
	return 0;
}