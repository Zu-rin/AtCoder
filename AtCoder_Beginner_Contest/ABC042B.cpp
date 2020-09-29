#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i;
	cin >> num >> i;
	vector<string> d(num);
	for (i = 0; i < num; i++)
		cin >> d[i];
	sort(d.begin(), d.end());
	for (i = 0; i < num; i++)
		cout << d[i];
	printf("\n");
	return 0;
}