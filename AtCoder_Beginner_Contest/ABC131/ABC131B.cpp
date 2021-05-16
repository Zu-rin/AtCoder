#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num, k, i, mi, sum = 0;
	cin >> num >> k;
	vector<int> d(num);
	for (i = 0; i < num; i++)
		sum += k + i;
	if (k <= 0 && abs(k) < num)
		printf("%d\n", sum);
	else if(k < 0)
		printf("%d\n", sum - k - num + 1);
	else
		printf("%d\n", sum - k);
	return 0;
}