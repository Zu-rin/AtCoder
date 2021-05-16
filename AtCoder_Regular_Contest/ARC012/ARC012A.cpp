#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	if (s == "Sunday" || s == "Saturday")
		printf("0\n");
	else if(s == "Friday")
		printf("1\n");
	else if(s == "Thursday")
		printf("2\n");
	else if (s == "Wednesday")
		printf("3\n");
	else if (s == "Tuesday")
		printf("4\n");
	else
		printf("5\n");
	return 0;
}