#include <iostream>
#include <vector>
#define T true

using namespace std;

int main(void) {
	int num, b[3], i, j, k, mi, ma;
	scanf_s("%d%d%d%d", &num, &b[0], &b[1], &b[2]);
	vector<vector<int>> a(num, vector<int>(num)), r(num, vector<int>(num)), ok(num, vector<int>(num, false));
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			scanf_s("%d", &a[i][j]);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			scanf_s("%d", &r[i][j]);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j + 2 < num; j += 3) {
			mi = a[i][j] + a[i][j + 1] + a[i][j + 2];
			ma = r[i][j] + r[i][j + 1] + r[i][j + 2];
			if (b[1] < mi)
				continue;
			if (b[1] > ma) {
				while (a[i][j + 1] < r[i][j + 1] && a[i][j] + a[i][j + 1] < b[0] && a[i][j + 1] + a[i][j + 2] < b[0])
					a[i][j + 1]++;
				while (a[i][j + 1] + a[i][j + 2] < b[0] && a[i][j + 2] < r[i][j + 2])
					a[i][j + 2]++;
				while (a[i][j] + a[i][j + 1] < b[0] && a[i][j] < r[i][j])
					a[i][j]++;
				if (a[i][j] + a[i][j] == b[0]) {
					ok[i][j] = T;
					ok[i][j + 1] = T;
				}
				if (a[i][j] + a[i][j] == b[0]) {
					ok[i][j + 2] = T;
					ok[i][j + 1] = T;
				}
			}
			else {
				if (a[i][j] <= a[i][j + 2]) {
					while (a[i][j] + a[i][j + 1] < b[0] && a[i][j] < r[i][j] && mi < b[1]) {
						mi++;
						a[i][j]++;
					}
					while (a[i][j + 1] + a[i][j + 2] < b[0] && a[i][j + 2] < r[i][j + 2] && mi < b[1]) {
						mi++;
						a[i][j + 2]++;
					}
				}
				else {
					while (a[i][j + 1] + a[i][j + 2] < b[0] && a[i][j + 2] < r[i][j + 2] && mi < b[1]) {
						mi++;
						a[i][j + 2]++;
					}
					while (a[i][j] + a[i][j + 1] < b[0] && a[i][j] < r[i][j] && mi < b[1]) {
						mi++;
						a[i][j]++;
					}
				}
				while (mi < b[1] && a[i][j + 1] < r[i][j + 1]) {
					mi++;
					a[i][j + 1]++;
				}
				if (mi == b[1]) {
					ok[i][j] = T;
					ok[i][j + 1] = T;
					ok[i][j + 2] = T;
				}
				else {
					if (a[i][j] + a[i][j] == b[0]) {
						ok[i][j] = T;
						ok[i][j + 1] = T;
					}
					if (a[i][j] + a[i][j] == b[0]) {
						ok[i][j + 2] = T;
						ok[i][j + 1] = T;
					}
				}
			}
		}
	}
	for (i = 0; i < num - 3; i++) {
		for (j = 0; j < num; j++) {
			if (!ok[i][j] && !ok[i + 1][j] && !ok[i + 2][j] && !ok[i + 3][j]) {
				mi = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				ma = r[i][j] + r[i + 1][j] + r[i + 2][j] + r[i + 3][j];
				if (b[2] > mi || b[2] <= ma) {
					for (k = 0; k < 4; k++) {
						while (a[i + k][j] < r[i + k][j] && mi < b[2]) {
							mi++;
							a[i + k][j]++;
						}
					}
					for (k = 0; k < 4; k++)
						ok[i + k][j] = T;
				}
			}
		}
	}
	for (i = 0; i < num - 2; i++) {
		for (j = 0; j < num; j++) {
			if (!ok[i][j] && !ok[i + 1][j] && !ok[i + 2][j]) {
				mi = a[i][j] + a[i + 1][j] + a[i + 2][j];
				ma = r[i][j] + r[i + 1][j] + r[i + 2][j];
				if (b[1] > mi || b[1] <= ma) {
					for (k = 0; k < 3; k++) {
						while (a[i + k][j] < r[i + k][j] && mi < b[1]) {
							mi++;
							a[i + k][j]++;
						}
					}
					for (k = 0; k < 3; k++)
						ok[i + k][j] = T;
				}
			}
		}
	}
	for (i = 0; i < num - 1; i++) {
		for (j = 0; j < num; j++) {
			if (!ok[i][j] && !ok[i + 1][j]) {
				mi = a[i][j] + a[i + 1][j];
				ma = r[i][j] + r[i + 1][j];
				if (b[0] > mi || b[0] <= ma) {
					for (k = 0; k < 2; k++) {
						while (a[i + k][j] < r[i + k][j] && mi < b[0]) {
							mi++;
							a[i + k][j]++;
						}
					}
					for (k = 0; k < 2; k++)
						ok[i + k][j] = T;
				}
			}
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}