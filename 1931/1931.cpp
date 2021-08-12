#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {	
			int a, b;
			cin >> a >> b;
			v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end(),cmp);
	/*for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}*/
	int count = 1;
	int temp = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= v[temp].second) {
			count++;
			temp = i;
			//cout << temp<<"\n";
		}
		
	}
	cout << count;
	return 0;

}