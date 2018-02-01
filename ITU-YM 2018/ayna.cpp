#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Word {
	int len = 0;
	char* word = NULL;
	int point = 0;
};

bool compFunc(const Word w1, const Word w2) {
	return std::strcmp(w1.word, w2.word) < 0;
}

int main()
{
	vector<Word> words;
	int nofs;
	cin >> nofs;
	char c;
	cin.get(c);
	for (int i = 0; i < nofs; i++) {
		string str;
		getline(cin, str);

		Word wor;
		wor.word = new char[str.length() + 1];
		std::strcpy(wor.word, str.c_str());
		wor.len = str.length();
		words.push_back(wor);
	}
	sort(words.begin(), words.end(), compFunc);

	//remove duplicates
	for (int i = 1; i < words.size(); i++) {
		if (std::string(words[i - 1].word) == std::string(words[i].word)) {
			words.erase(words.begin() + i--);
		}
	}

	for (int i = 1; i < words.size(); i++) {
		char* w = words[i].word;
		int wl = words[i].len;

		int maxp = 0;
		for (int j = (i - 1); j > -1; j--) {
			char* cur = words[j].word;
			int cl = words[j].len;

			int mn = min(wl, cl);
			int mr = maxp - words[j].point;

			if (mr > mn)
				continue;
			if (mr < 1)
				mr = 1;

			for (; mr <= mn; mr++) {
				bool same = true;
				int ind = 0;
				while (same && ind < mr)
				{
					if (w[ind] != cur[cl - mr + ind])
						same = false;
					ind++;
				}
				if (same)
					maxp = words[j].point + mr;
			}
		}
		words[i].point = maxp;
	}

	int mp = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].point > mp)
			mp = words[i].point;
	}
	cout << mp << endl;
    return 0;
}