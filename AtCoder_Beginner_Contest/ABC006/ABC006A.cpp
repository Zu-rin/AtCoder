#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n;
	string s[10] = { "", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "YES" };
	cin >> n;
	cout << s[n] << "\n";
	return 0;
}