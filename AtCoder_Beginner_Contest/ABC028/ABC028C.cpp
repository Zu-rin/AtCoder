#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int i, j, k;
	vector<int> n(5), data;
	scanf_s("%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	for (i = 0; i < 3; i++)
		for (j = i + 1; j < 4; j++)
			for (k = j + 1; k < 5; k++)
				data.push_back(n[i] + n[j] + n[k]);
	sort(data.begin(), data.end());
	cout << data[7] << "\n";
	return 0;
}