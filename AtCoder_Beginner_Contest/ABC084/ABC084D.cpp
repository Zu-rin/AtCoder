#include <iostream>
#include <vector>
#define N 100001

using namespace std;

int main(void) {
	int i, j, sum = 0, num, l, r;
	vector<int> p(N, true);
	p[0] = 0;
	p[1] = 0;
	for (i = 2; i < N; i++) {
		while (i < N && !p[i])
			i++;
		for (j = i << 1; j < N; j += i)
			p[j] = false;
	}
	for (i = 1; i <= N >> 1; i++) {
		if (p[i] && p[(i << 1) - 1])
			sum++;
		p[i] = sum;
	}
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d%d", &l, &r);
		l >>= 1;
		r = (r + 1) >> 1;
		printf("%d\n", p[r] - p[l]);
	}
	return 0;
}