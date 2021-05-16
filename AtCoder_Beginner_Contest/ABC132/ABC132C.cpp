#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, ans = 0, a;
	cin >> num;
	vector<int> d(num);
	a = num >> 1;
	for (i = 0; i < num; i++)
		scanf_s("%d", &d[i]);
	sort(d.begin(), d.end());
	printf("%d\n", d[a] - d[a - 1]);
	return 0;
}