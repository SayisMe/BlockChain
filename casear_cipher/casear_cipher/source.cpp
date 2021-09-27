#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int k, a;
	cin >> str >> k;
	k %= 26;
	for (int i = 0; i < str.size(); i++)
	{
		a = str.at(i) - 97 - k;
		if (a < 0)
			a = a % 26 + 26;
		else
			a %= 26;
		str.at(i) = a + 97;
		cout << str[i];
	}
	return 0;
}
