#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, k, len = 0, j = 0, a, ans = 0, sum = 0;
	string s;
	queue<int> que;
	cin >> num >> k >> s;
	vector<int> d(num + 2, 0);
	if (s[0] == '0')
		len++;
	for (i = 0; i < num;) {
		a = 0;
		while (i < num && s[i + a] == s[i])
			a++;
		i += a;
		if (a > 0)
			d[len++] = a;
	}
	if (s[num - 1] == '0')
		len++;
	k = (k << 1) + 1;
	if (k >= len) {
		cout << num << "\n";
		return 0;
	}
	for (i = 0; i < k; i++) {
		que.push(d[i]);
		sum += d[i];
	}
	ans = sum;
	for (; i < len; i += 2) {
		que.push(d[i]);
		que.push(d[i + 1]);
		sum += d[i] + d[i + 1];
		sum -= que.front();
		que.pop();
		sum -= que.front();
		que.pop();
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}