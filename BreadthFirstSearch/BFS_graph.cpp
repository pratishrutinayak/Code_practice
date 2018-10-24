#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector <bool> v;
vector<vector<int> > g;
void addEdge(int a , int b)
{
	g[a].push_back(b);
}

void BFS(int node)
{
	queue<int> data;
	data.push(node);
	v[node] = true;

	if (!data.empty())
	{
		int process_node = data.front();
		data.pop();
		cout << process_node << "\n";
		for (auto i = g[process_node].begin(); i != g[process_node].end(); i++)
		{
			if (!v[*i])
			{
				data.push(*i);
				v[*i] = true;
			}
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;
	v.assign(n, false);
	g.assign(n, vector<int>());

	int a, b;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		addEdge(a, b);
	}
	for (int i = 0; i < n; i++)
	{
		if (!v[i])
		{
			BFS(i);
		}
	}
}