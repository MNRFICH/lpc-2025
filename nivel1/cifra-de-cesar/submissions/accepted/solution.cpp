#include <iostream>
using namespace std;

int main()
{
	int c;
	string s;
	cin >> s >> c;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = s[i] - c;
		if (s[i] < 65)
		{
			s[i] = s[i] + 26;
		}
	}
	cout << s << endl;
	return 0;
}
