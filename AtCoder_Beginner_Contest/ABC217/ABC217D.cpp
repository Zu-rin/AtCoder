#include <iostream>
#include <set>
using namespace std;

int main(void) {
	int i, l, q, c, x;
	cin >> l >> q;
	set<int> st = { 0, l };
	for(i = 0; i < q; i++) {
		scanf("%d%d", &c, &x);
		auto it = st.insert(x).first;
		if (c == 2) {
			cout << *next(it) - *prev(it) << "\n";
			st.erase(it);
		}
	}
	return 0;
}