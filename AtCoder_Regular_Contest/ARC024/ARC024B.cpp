#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, a = 0, ans = 0;
	cin >> num;
	vector<int> d(2 * num);
	for (i = 0; i < num; i++) {
		cin >> d[i];
		d[i + num] = d[i];
	}
	for (i = 0; i < d.size() - 1; i++) {
		if (d[i] == d[i + 1])
			a++;
		else
			a = 0;
		ans = max(ans, a);
	}
	if (ans > num)
		printf("-1\n");
	else
		cout << 1 + (ans >> 1) << "\n";
	return 0;
}