#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, k, i, j = 1, ans = 0;
	string s;
	cin >> num >> k >> s;
	k++;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '+')
			j++;
		else
			j--;
		if (j == k) {
			ans++;
			j = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}