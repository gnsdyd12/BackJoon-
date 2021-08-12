#include <iostream>
#include <vector>
using namespace std;

int c_1 = 0;
int c0 = 0;
int c1 = 0;
vector<vector<int>> v(2200, vector<int>(2200, 0));


void devide(int g, int g1, int s, int s1, int n) {
	
	int start = v[g][s];
	
	//cout << g << " " << g1 << " " << s << " " << s1 << "\n";
	if ((n) == 0) {
		return;
	}
	for (int i = g; i < g1; i++) {
		for (int j = s; j < s1; j++) {
			if (start != v[i][j]) {
				
				devide( g, g + (n / 3), s, s + n / 3, n / 3);
				devide( g, g + (n / 3), s + (n / 3), s + (n / 3) * 2, n / 3);
				devide( g, g + (n / 3), s + (n / 3) * 2, s + (n / 3) * 3, n / 3);

				devide( g+(n / 3), g+(n / 3) * 2, s, s + n / 3, n / 3);
				devide( g+(n / 3), g+(n / 3) * 2, s + (n / 3),s + (n / 3) * 2, n / 3);
				devide( g+(n / 3), g+(n / 3) * 2, s + (n / 3) * 2,s + (n / 3) * 3, n / 3);

				devide( g+(n / 3) * 2, g+(n / 3) * 3, s,s + (n / 3), n / 3);
				devide( g+(n / 3) * 2, g+(n / 3) * 3, s + (n / 3),s + (n / 3) * 2, n / 3);
				devide( g+(n / 3) * 2, g+(n / 3) * 3, s +(n / 3) * 2,s + (n / 3) * 3, n / 3);
				return;
			}
		}
	}
	if (start == -1) {
		c_1++;		
		return;
	}
	else if (start == 0) {
		c0++;		
		return;
	}
	else if (start == 1) {
		c1++;		
		return;
	}
	
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}	
	int g = 0;
	int g1 = n;
	int s = 0;
	int s1 = n;	
	devide(g,g1,s,s1,n);
	cout << c_1 << "\n" << c0 << "\n" << c1;

	return 0;
}