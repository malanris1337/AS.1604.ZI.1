#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <istream>

using namespace std;

char enc(char a, char b)
{
	return (a + b) % 256;
}

char dec(char a, char b)
{
	return (a - b) % 256;
}

int main(int argc, char* argv[])
{
	string in_key, in_text, key, str;

	if (argc < 3)
	{
		cout << "error";
		return 0;
	}

	in_key = argv[1];
	in_text = argv[2];

	ifstream fin_key(in_key, ios::binary), fin_text(in_text, ios::binary);

	if (!fin_key.is_open() || !fin_text.is_open())
	{
		cout << "input file error" << endl;
		return 0;
	}

	ofstream fout_enc("enc.txt", ios::binary), fout_dec("dec.txt", ios::binary);

	vector < char > vkey((istreambuf_iterator < char > (fin_key)), istreambuf_iterator < char >());
	vector < char > :: iterator it = vkey.begin();

	while (true)
	{
		char c;
		fin_text.get(c);

		if (fin_text.eof())
			break;

		char c1 = enc(c, *it);
		fout_enc << c1;
		char c2 = dec(c1, *it);
		fout_dec << c2;

		it++;
		if (it == vkey.end())
			it = vkey.begin();
	}

	cout << "successfully" << endl;

    return 0;
}

