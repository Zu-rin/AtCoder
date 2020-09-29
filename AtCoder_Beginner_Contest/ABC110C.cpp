#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int i = 0;
	vector<int> A(26, -1), B(26, -1);
	string a, b;
	cin >> a >> b;
	for (; i < a.size(); i++) {
		if(A[a[i] - 'a'] == -1)
			A[a[i] - 'a'] = b[i] - 'a';
		else if (A[a[i] - 'a'] != b[i] - 'a') {
			printf("No\n");
			break;
		}
		if(B[b[i] - 'a'] == -1)
			B[b[i] - 'a'] = a[i] - 'a';
		else if (B[b[i] - 'a'] != a[i] - 'a') {
			printf("No\n");
			break;
		}
	}
	if (i == a.size())
		printf("Yes\n");
	return 0;
}