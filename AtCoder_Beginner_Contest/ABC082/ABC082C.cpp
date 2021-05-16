#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, i = 0, buf, ans = 0;
	cin >> num;
	vector<int> d(num + 1, 0);
	for (; i < num; i++) {
		scanf_s("%d", &buf);
		if (buf > num) {
			ans++;
			continue;
		}
		d[buf]++;
	}
	for (i = 0; i <= num; i++) {
		while (i <= num && d[i] == 0)
			i++;
		if (i > num)
			break;
		if (d[i] < i)
			ans += d[i];
		else
			ans += d[i] - i;
	}
	cout << ans << "\n";
	return 0;
}