#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i = 0, a;
	long long sumT = 0, sumF = 0, ansT = 0, ansF = 0;
	bool sig = true;
	cin >> num;
	for (; i < num; i++) {
		scanf_s("%d", &a);
		sumT += a;
		sumF += a;
		if (sig && sumT >= 0) {
			ansT += sumT + 1;
			sumT = -1;
		}
		else if (!sig && sumT <= 0) {
			ansT += 1 - sumT;
			sumT = 1;
		}
		if (!sig && sumF >= 0) {
			ansF += sumF + 1;
			sumF = -1;
		}
		else if (sig && sumF <= 0) {
			ansF += 1 - sumF;
			sumF = 1;
		}
		sig = !sig;
	}
	cout << min(ansT, ansF) << "\n";
	return 0;
}