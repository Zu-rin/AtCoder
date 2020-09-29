#include <iostream>
#include <vector>
#define MOD 10007

using namespace std;

int main(void) {
	vector<int> d(3, 0);
	d[2] = 1;
	int num;
	cin >> num;
	for (int i = 3; i < num; i++)
		d[i % 3] = (d[0] + d[1] + d[2]) % MOD;
	printf("%d\n", d[(num - 1) % 3]);
	return 0;
}