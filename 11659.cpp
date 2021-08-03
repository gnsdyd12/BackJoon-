#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> v;
	int a;
	int sum = 0;
	v.push_back(0);
	for (int k = 0; k < n; k++) {
		cin >> a;
		sum += a;
		v.push_back(sum);
	}
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << v[n2] - v[n1 - 1]<<"\n";
	}
	return 0;
}