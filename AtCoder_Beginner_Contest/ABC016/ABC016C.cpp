#include <stdio.h>
#include <iostream>

using namespace std;

int main(void) {
	int num, pairs, frnd, i = 0, j, ans;
	cin >> num >> pairs;
	int *data = new int[num](), a, b;
	for (; i < pairs; i++) {
		cin >> a >> b;
		a--; b--;
		data[a] |= 1 << b;
		data[b] |= 1 << a;
	}
	for (i = 0; i < num; i++) {
		ans = 0;
		frnd = 0;
		for (j = 0; j < num; j++) {
			if (data[i] >> j & 1)
				frnd |= data[j] & data[i] ^ data[j];
		}
		frnd ^= frnd & (1 << i);
		for (j = 0; j < num; j++) {
			if (frnd & 1)
				ans++;
			frnd >>= 1;
		}
		cout << ans << "\n";
	}
	delete[] data;
	return 0;
}