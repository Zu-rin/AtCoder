#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int i = 0, start = 0, end = 0, num, k, len = 0, ans = 0;
	cin >> num >> k;
	vector<int> s(num);
	for (; i < num; i++)
		scanf_s("%d", &s[i]);
	long long pro = 1;
	while (end < num) {
		if (s[end] == 0) {
			cout << num << "\n";
			return 0;
		}
		if (pro * s[end] > k) {
			if (start == end)
				end++;
			else {
				len--;
				pro /= s[start];
			}
			start++;
			continue;
		}
		pro *= s[end];
		len++;
		end++;
		ans = max(ans, len);
	}
	cout << ans << "\n";
	return 0;
}