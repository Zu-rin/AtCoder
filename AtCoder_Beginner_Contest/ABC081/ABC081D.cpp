#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, ma = 1, mi = 1, x;
	cin >> num;
	cout << 2 * num - 1 << "\n";
	vector<int> d(num + 1);
	for (i = 1; i <= num; i++) {
		cin >> d[i];
		if (d[ma] < d[i])
			ma = i;
		if (d[mi] > d[i])
			mi = i;
	}
	if (abs(d[ma]) >= abs(d[mi]))
		x = ma;
	else
		x = mi;
	for (i = 1; i <= num; i++)
		printf("%d %d\n", x, i);
	if (d[x] > 0) {
		for(i = 1; i< num; i++)
			printf("%d %d\n", i, i + 1);
	}
	else {
		for (i = num; i > 1; i--)
			printf("%d %d\n", i, i - 1);
	}
	return 0;
}