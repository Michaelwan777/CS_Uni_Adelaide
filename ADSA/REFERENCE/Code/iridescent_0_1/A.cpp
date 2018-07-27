#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N;
		string S;
		cin >> N >> S;
		int total = 0, add = 0;
		for(int i = 0; i < S.size(); i++)
		{
			while(S[i] != '0')
			{
				while(total < i)
					total++, add++;
				S[i]--;
				total++;
			}
		}
		cout << "Case #" << t << ": " << add << endl;
	}
}
