#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	string sik;
	cin >> sik;
	vector<char> v1;
	v1.push_back('+');
	vector<string> v2;
	for (int i = 0; i < sik.size(); i++) {
		if (sik.at(i) == '+' || sik.at(i) == '-') {
			v1.push_back(sik.at(i));
			string a;
			for (int j = 0; j <i; j++) {			
				a+=sik.at(j);
			}
			v2.push_back(a);
			
			sik=sik.substr(i+1);
			i = 0;	
		}
		
	}
	string e;
	for (int i = 0; i < sik.size(); i++) {
		e += sik.at(i);
	}
	v2.push_back(e);


   /*
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	*/

	int arr[51];
	for (int i = 0; i < 51; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < v2.size(); i++) {
		arr[i] = atoi(v2[i].c_str());
	}
	int cut=v1.size();
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == '-') {
			cut = i-1;
			break;
		}
	}
	int plus = 0;
	int minus = 0;
	for (int i = 0; i <= cut; i++) {
		plus += arr[i];
	}
	for (int i = cut+1; i <= v1.size(); i++) {
		minus += arr[i];
	}
	int result = plus - minus;
	//cout << plus << " " << minus << "\n";
	cout << result;
	return 0;
}