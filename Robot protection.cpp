#include <bits/stdc++.h>
using namespace std;
const long double precision = .00001;
struct pops {
	long double first, second;
	pops(long double xloc, long double yloc) : first(xloc), second(yloc) {}
	pops() {}
	pops& operator= (const pops& other) {
		first = other.first, second = other.second;
		return *this;
	}
	int operator== (const pops& other) const {
		return abs(other.first - first) < precision && abs(other.second - second) < precision;
	}
	bool operator< (const pops& other) const {
		return (first < other.first ? true : (abs(other.first - first) < precision && second < other.second));
	}
};
struct vect {
	long double i, j;
};
long double calc_area(vector<pops> hook) {
	long double fin_tot = 0;
	int length = hook.size();
	for (int i = 0, j = 1; i < length; i++, j = (i + 1) % length) {
		fin_tot = fin_tot + (hook[i].first * hook[j].second) - (hook[i].second * hook[j].first);
	}
	return abs(fin_tot) / 2;
}
long double psd(pops v1, pops v2) {
	return pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2);
}

long double multiplic(pops v1, pops v2, pops v3) {
	vect x, y;
	x.i = v2.first - v1.first;
	x.j = v2.second - v1.second;
	y.i = v3.first - v1.first;
	y.j = v3.second - v1.second;
	return (x.i * y.j - x.j * y.i);
}
vector<pops> shape(vector<pops> first) {
	vector<pops> pull;
	long long len = first.size();
	vector<bool> old(len, false);

	int prob = 0;
	for (int i = 1; i < len; i++) {
		if (first[i].first < first[prob].first) {
			prob = i;
		}
	}
	int start = prob;

	do {
		int refr = -1;
		long double stretch = 0;

		for (int i = 0; i < len; i++) {
			if (i == prob || old[i]) {
				continue;
			}
			if (refr == -1) {
				refr = i;
			}
			long double gap = psd(first[i], first[prob]);
			long double prod = multiplic(first[prob], first[i], first[refr]);


			if (prod < 0 || (abs(prod) < precision && gap > stretch)) {
				refr = i;
				stretch = gap;
			}
		}

		prob = refr;
		old[prob] = true;
		pull.push_back(first[prob]);
	} while (start != prob);

	return pull;
}

int main() {

	int number;
	while (cin >> number && number != 0) {
		vector<pops> hook(number);
		for (auto& i : hook) {
			cin >> i.first >> i.second;
		}

		if (number < 3) {
			cout << "0.0" << endl;
			continue;
		}

		vector<pops> pull = shape(hook);

		cout << fixed;
		cout.precision(1);
		cout << calc_area(pull) << endl;
	}

}
