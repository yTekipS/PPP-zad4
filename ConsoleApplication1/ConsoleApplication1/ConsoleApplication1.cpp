#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool Odczyt(vector<string> &wyr) {
	ifstream wyrazy("wyrazy.txt");
	string line;

	if (wyrazy.good()) {
		while (wyrazy >> line) {
			if (line != "") wyr.emplace_back(line);
		}
		return true;
	}
	else return false;
}

 bool spraw(string item) {
	 for (int i = 0; i < item.length() / 2; i++) {
		 if (toupper(item[i]) != toupper(item[item.length() - 1 - i]))return false;
	 }
	 return true;
 }

 void sprawdz(vector <string>& wyr) {
	 ofstream palindromy("palindromy.txt");
	 string l;

	 for (string item : wyr){
		 if (spraw(item)) palindromy << item + '\n';
	 }
 }

int main() {
	vector <string> wyrazy;


	if (Odczyt(wyrazy))sprawdz(wyrazy);
	else cout << "ERROR";

}