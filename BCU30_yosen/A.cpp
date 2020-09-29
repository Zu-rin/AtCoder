#include <iostream>

using namespace std;

int main(void) {
	int num, p, a, i;
	cin >> num >> p;
	for (i = 0; i < num; i++){
		scanf_s("%d", &a);
		p -= a;
		if (p < 0)
			break;
	}
	cout << i << "\n";
	return 0;
}