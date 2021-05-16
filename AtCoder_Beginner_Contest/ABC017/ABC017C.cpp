#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int ruin, jewel, i = 0, min, sum = 0, st = 0, left, right, score;
	scanf_s("%d %d", &ruin, &jewel);
	vector<int> dist(jewel+1);

	for (; i < ruin; i++) {
		scanf_s("%d %d %d", &left, &right, &score);
		dist[left - 1] += score;
		dist[right] -= score;
		sum += score;
	}
	min = sum;
	for (i = 0; i < jewel; i++) {
		st += dist[i];
		if (st < min)
			min = st;
		if (min == 0)
			break;
	}
	cout << sum - min << "\n";
	return 0;
}