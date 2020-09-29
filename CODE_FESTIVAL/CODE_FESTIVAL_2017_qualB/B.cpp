#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int n, i, a;
	map<int, int> mp;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a);
		mp[a]++;
	}
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a);
		if (mp[a] == 0) {
			printf("NO\n");
			return 0;
		}
		mp[a]--;
	}
	printf("YES\n");
	return 0;
}