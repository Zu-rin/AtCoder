#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int i, j, k, num;
	char s[4] = "abc";
	cin >> num;
	vector<int> d(num, 0);
	for (k = pow(3, num); k > 0; k--) {
		for (i = 0; i < num; i++)
			printf("%c", s[d[i]]);
		printf("\n");
		d[num - 1]++;
		j = num - 1;
		while (d[j] == 3 && j > 0) {
			d[j--] = 0;
			d[j]++;
		}
	}
	return 0;
}