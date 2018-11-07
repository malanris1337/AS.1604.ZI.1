#include "stdafx.h"

void read(ifstream& f, vector < unsigned char >& v)
{
	while (!f.eof())
		v.push_back(f.get());

	f.close();
}

void pcnt(vector < unsigned char >& v, vector<int>& h)
{
	for (int i = 0; i < v.size(); ++i)
		h[v[i]]++;
}

int vmax(vector < int >& v)
{
	int p = 0, mx = v[0];

	for (int i = 0; i < 256; ++i) 
	{
		if (v[i] >= mx) 
		{
			mx = v[i];
			p = i;
		}
	}

	return p;
}

unsigned char getkey(vector < int >& i, vector < int >& p) 
{
	if (vmax(p) >= vmax(i))
		return (vmax(p) - vmax(i));

	return (vmax(p) + 256 - vmax(i));
}

void decode(vector < unsigned char >& k, vector < unsigned char >& t, string fname)
{
	ofstream f(fname, ios::binary);
	f.clear();

	char c;
	int i = 0;

	for (int j = 0; j < t.size() - 1; ++j) 
	{
		if (i > k.size() - 1) 
			i = 0;

		c = (t[j] - k[i]) % 255;
		f << c;
		t[j] = c;
		i++;
	}

	cout << endl;
	f.close();
}

