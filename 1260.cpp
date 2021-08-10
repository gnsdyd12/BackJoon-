#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void dfs_stack(int start, vector<int>graph[],bool check[]) {
	stack<int> s;
	s.push(start);
	check[start] = true;
	cout << start<<" ";

	while (!s.empty()) {
		int cur_node = s.top();
		s.pop();
		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i];
			if (check[next_node] == false) {
				cout << next_node << " ";
				check[next_node] = true;

				s.push(cur_node);
				s.push(next_node);
				break;
			}
		}
	}
	cout << "\n";
}
void bfs(int start, vector<int>graph[], bool check[]){
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";
		for (int i = 0; i < graph[tmp].size(); i++) {
			if (check[graph[tmp][i]] == false) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, v;
	cin >> n >> m >> v;
	vector<int>* graph = new vector<int>[n + 1];
	bool* check_dfs = new bool [n + 1] ;
	bool* check_bfs = new bool[n + 1];
	for (int i = 0; i <= n; i++) {
		check_dfs[i] = false;
		check_bfs[i] = false;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs_stack(v,graph, check_dfs);
	bfs(v, graph, check_bfs);
	return 0;
}