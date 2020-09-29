#include <iostream>
#include <list>

using namespace std;

int main(void) {
	int num, i, a, n;
	cin >> num;
	list<int> d, ans;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		d.push_front(a);
	}
	n = num;
	for (auto itr = d.begin(); itr != d.end();) {
		if (*itr == n) {
			ans.push_front(n);
			d.erase(itr);
			itr = d.begin();
			n = d.size();
			continue;
		}
		n--;
		itr++;
	}
	if (d.size())
		printf("-1\n");
	else {
		for (auto itr = ans.begin(); itr != ans.end(); itr++)
			printf("%d\n", *itr);
	}
	return 0;
}