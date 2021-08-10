#include<iostream>
#include<vector>
using namespace std;



void bfs(int** list,int x,int y,int n,int m) {

	if (x < 0 || y < 0 || x>=n || y>=m) {
		return;
	}

	if (list[x][y] == 1) {	
		list[x][y] = 0;
		
		bfs(list, x + 1, y,n,m);
		bfs(list, x , y+1, n, m);
		bfs(list, x - 1, y, n, m);
		bfs(list, x , y - 1, n, m);
	}
	else{
		return;
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	for (int l = 0; l < t; l++) {
		int num = 0;
		int n, m, k;
		cin >> m >> n >> k;
		//2차원 배열 생성
		int** arr = new int* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[m];
		}
		//2차원 배열 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
		//배추 넣기
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					bfs(arr,i,j,n,m);
					num++;
					/*
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							cout << arr[i][j] << " ";
						}
						cout << "\n";
					}
					cout << "\n";
					*/
				}
			}
		}

		cout << num<<"\n";
	}
	return 0;

}