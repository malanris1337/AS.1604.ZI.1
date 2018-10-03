#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string encrypt(string str, string key)
{
	string temp = str;

	for (int i = 0; i < str.size(); ++i)
		temp[i] = ((str[i] - 'a') + (key[i] - 'a')) % 26 + 'a';

	return temp;
}

string decrypt(string str, string key)
{
	string temp = str;

	for (int i = 0; i < str.size(); ++i)
		temp[i] = ((str[i] - 'a') - (key[i] - 'a')) % 26 + 'a';

	return temp;
}

int main()
{
	string sif, sof, key, ans, str;
	int q;

	cout << "input filename: ";
	cin >> sif;

	cout << "output filename: ";
	cin >> sof;

	cout << "key: ";
	cin >> key;

	cout << "decrypt / encrypt (0 / 1): ";
	cin >> q;

	ifstream fi;
	fi.open(sif);

	if (!fi.is_open())
	{
		cout << "input file error" << endl;
		return 0;
	}

	ofstream fo;
	fo.open(sof);

	if (!fo.is_open())
	{
		cout << "output file error" << endl;
		return 0;
	}

	fi >> str;
	fi.close();

	if (key.size() > str.size())
		key.resize(str.size());
	else
	{
		int i = key.size();
		int m = i;
		key.resize(str.size());

		while (i < str.size())
		{
			key[i] = key[(i - m) % m];
			++i;
		}
	}

	q ? ans = encrypt(str, key) : ans = decrypt(str, key);
	fo << ans;
	fo.close();

	cout << "successfully" << endl;

    return 0;
}

