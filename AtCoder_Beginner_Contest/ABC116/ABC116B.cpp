#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int s, i = 1;
	map<int, int> mp;
	scanf_s("%d", &s);
	while (mp[s] == 0) {
		mp[s] = 1;
		if ((s & 1) == 0)
			s >>= 1;
		else
			s = 3 * s + 1;
		i++;
	}
	cout << i << "\n";
	return 0;
}