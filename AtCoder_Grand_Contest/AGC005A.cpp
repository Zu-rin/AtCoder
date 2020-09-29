#include <iostream>
#include <string>
#include <stack>

using namespace std;

int  main(void) {
	string s;
	cin >> s;
	int i;
	stack<int> st;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'S')
			st.push(0);
		else if (!st.empty() && st.top() == 0)
			st.pop();
		else
			st.push(1);
	}
	cout << st.size() << "\n";
	return 0;
}