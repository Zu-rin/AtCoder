#include <stdio.h>
#include <iostream>

using namespace std;

int Search(int data[5][5], int num, int sel, int N, int ans) {
	int i = 0;
	if (N == num - 1) {
		for (; i < sel; i++) {
			if (ans ^ data[N][i])
				continue;
			return 0;
		}
		return 1;
	}
	for (; i < sel; i++) {
		if (Search(data, num, sel, N + 1, ans^data[N][i]))
			continue;
		return 0;
	}
	return 1;
}

int main(void) {
	int num, sel, i = 0, j, data[5][5];
	cin >> num >> sel;
	for (; i < num; i++)
		for (j = 0; j < sel; j++)
			cin >> data[i][j];
	if (Search(data, num, sel, 0, 0) == 0)
		cout << "Found\n";
	else
		cout << "Nothing\n";
	return 0;
}