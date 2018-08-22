#include <bits/stdc++.h>
using namespace std;
int main() {
	int x = 1000000010;
	bool first_pops = true;
	int first_count, second_count = 0;
	bool second_pops = true;
	bool pops = false;
	string brackets;
	cin >> brackets;
	int len = brackets.size();

	vector<int> first(len, 0);
	vector<int> second(len, 0);


	for (int i = 1; i <= len; i++) {
		if (brackets[i - 1] == '(') {
			first_count++;
		}
		if (brackets[i - 1] == ')') {
			first_count--;
		}

		if (first_count < 0) {
			first_pops = false;
		}

		if (first_pops) {
			first[i] = first_count;
		}
		else {
			first[i] = -x;
		}

	}


	for (int j = len; j > 0; j--) {
		if (brackets[j - 1] == '(') {
			second_count--;
		}
		if (brackets[j - 1] == ')') {
			second_count++;
		}

		if (second_count < 0) {
			second_pops = false;
		}

		if (second_pops) {
			second[j] = second_count;
		}
		else {
			second[j] = -x;
		}

	}


	for (int k = 1; k <= len; k++) {
		int first_1 = first[k - 1];
		for (int l = k; l <= len; l++) {

			if (brackets[l - 1] == '(') {
				first_1--;
			}
			if (brackets[l - 1] == ')') {
				first_1++;
			}

			if (first_1 < 0) {
				break;
			}

			if (second[l + 1] < 0) {
				continue;
			}

			if (first_1 == second[l + 1]) {
				pops = true;
			}
		}
	}


	if (first_pops && second_pops) {
		pops = true;
	}

	if (pops) {
		cout << "possible" << endl;
	}
	else {
		cout << "impossible" << endl;
	}

	return 0;
}
