#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, j, k, sum = 0;
	double a = 0.5, ans = 0.0;
	cin >> num;
	vector<int> s(num, 0), t(num);
	vector<double> v(num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &t[i]);
		s[i] = sum;
		sum += t[i];
	}
	for (i = 0; i < num; i++)
		cin >> v[i];
	vector<double> d(sum);
	for (i = 0; i < (sum >> 1); i++) {
		d[i] = a;
		d[sum - i - 1] = a;
		a += 1.0;
	}
	if (sum & 1)
		d[i] = a - 0.25;
	for (i = 0; i < num; i++) {
		for (j = s[i]; j < s[i] + t[i]; j++)
			d[j] = min(d[j], v[i]);
	}
	for (i = 1; i < num; i++) {
		a = min(v[i - 1], v[i]) + 0.5;
		for (j = s[i] - 1; j >= 0; j--) {
			if (d[j] > a)
				d[j] = a;
			else if (d[j] == a) {
				if (d[j - 1] < d[j])
					d[j] -= 0.25;
				break;
			}
			else
				break;
			a += 1.0;
		}
		a = min(v[i - 1], v[i]) + 0.5;
		for (j = s[i]; j < sum; j++) {
			if (d[j] > a)
				d[j] = a;
			else if (d[j] == a) {
				if (d[j] > d[j + 1])
					d[j] -= 0.25;
				break;
			}
			else
				break;
			a += 1.0;
		}
	}
	for (i = 0; i < sum; i++)
		ans += d[i];
	printf("%.10lf\n", ans);
	return 0;
}