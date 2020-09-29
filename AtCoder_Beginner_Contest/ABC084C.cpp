#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, j = 0, ans;
	cin >> num;
	num--;
	vector<int> c(num), s(num), f(num);
	for (; i < num; i++)
		scanf_s("%d%d%d", &c[i], &s[i], &f[i]);
	for (; j <= num; j++) {
		ans = 0;
		for (i = j; i < num; i++) {
			if (ans <= s[i])
				ans = s[i];
			else if(ans % f[i] != 0)
				ans += f[i] - (ans % f[i]);
			ans += c[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}