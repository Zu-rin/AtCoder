#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	if (s[0] == s[s.size() - 1]) {
		if (s.size() & 1)
			printf("Second\n");
		else
			printf("First\n");
	}
	else{
		if (s.size() & 1)
			printf("First\n");
		else
			printf("Second\n");
	}
	return 0;
}