#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j, sum = 0;
	cin >> num;
	ll ans = num;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	for (i = 0, j = 0; i < num; i++) {
		if (sum + d[i] == (sum ^ d[i])) {
			sum += d[i];
			ans += i - j;
		}
		else {
			sum -= d[j++];
			i--;
		}
	}
	cout << ans << "\n";
	return 0;
}