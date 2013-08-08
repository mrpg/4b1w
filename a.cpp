// This software is public domain.
// Max R. P. Grossmann, 2013 [mrpg.pw]

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

inline bool erase(string& str, char ch) {
	auto it = find(str.begin(),str.end(),ch);

	if (it == str.end()) {
		return false;
	}
	else {
		str.erase(it);
		return true;
	}
}

bool check(string chs, const string& ref) {
	for (auto& l: ref) {
		if (!erase(chs,l)) {
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv) {
	auto n = stoul(string(argv[2]));
	string all(argv[1]);

	map<string,uint64_t> db;
	string cstr;
	uint64_t cn;

	while (cin >> cstr >> cn) {
		db[cstr] = cn;
	}

	vector<pair<string,uint64_t>> results;

	for (auto& cur: db) {
		if (cur.first.length() == n && check(all,cur.first)) {
			results.push_back(cur);
		}
	}

	sort(results.begin(),results.end(),[](const pair<string,uint64_t>& a, const pair<string,uint64_t>& b){return (a.second > b.second);});

	for (auto& cr: results) {
		cout << cr.first << '\t' << cr.second << endl;
	}
}
