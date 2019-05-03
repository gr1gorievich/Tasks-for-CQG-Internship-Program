#include <iostream>
#include <fstream>
using namespace std;

int main() {

	const int len = 25, strings = 8;
	const char ch = '\n';
	char first[len][strings];
	char second[len][strings];
	char third[strings][len];

	ifstream fs("cqg.txt");

	if (!fs) return 1;

	for (int i = 0; i < strings; i++) {
		fs >> first[i];
		fs >> second[i];
		fs.getline(third[i], len, ch);
		cout << first[i] << " " << second[i] << third[i] << endl;
	};

	cout << endl;
	
	for (int i = 0; i < strings-1; i++) {
		for (int j = i + 1; j < strings; j++) {
			if (strcmp(first[j], second[i]) >= 0) {
				continue;
			};
			if (strcmp(second[j], second[i]) < 0) {
				cout << first[j] << " " << second[j] << third[i] << third[j] << endl;
			};
			if (strcmp(second[j], second[i]) >= 0) {
				cout << first[j] << " " << second[i] << third[i] << third[j] << endl;
			}
		}

	}

	fs.close(); 
	return 0;
};


