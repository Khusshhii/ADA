// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 20;

// variables to be used
// in both functions
vector<int> graph[N];
vector<int> cycles[N];

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[],
			int mark[], int par[], int& cyclenumber)
{

	// already (completely) visited vertex.
	if (color[u] == 2) {
		return;
	}

	// seen vertex, but was not completely visited -> cycle detected.
	// backtrack based on parents to find the complete cycle.
	if (color[u] == 1) {

		cyclenumber++;
		int cur = p;
		mark[cur] = cyclenumber;

		// backtrack the vertex which are
		// in the current cycle thats found
		while (cur != u) {
			cur = par[cur];
			mark[cur] = cyclenumber;
		}
		return;
	}
	par[u] = p;

	// partially visited.
	color[u] = 1;

	// simple dfs on graph
	for (int v : graph[u]) {

		// if it has not been visited previously
		if (v == par[u]) {
			continue;
		}
		dfs_cycle(v, u, color, mark, par, cyclenumber);
	}

	// completely visited.
	color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

// Function to print the cycles
void printCycles(int edges, int mark[], int& cyclenumber)
{

	// push the edges that into the
	// cycle adjacency list
	for (int i = 1; i <= edges; i++) {
		if (mark[i] != 0)
			cycles[mark[i]].push_back(i);
	}

	// print all the vertex with same cycle
	for (int i = 1; i <= cyclenumber; i++) {
		// Print the i-th cycle
		cout << "Cycle Number " << i << ": ";
		for (int x : cycles[i])
			cout << x << " ";
		cout << endl;
	}
}

// Driver Code
int main()
{

	// add edges
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(5, 1);

	addEdge(6, 16);
	addEdge(16, 7);
	addEdge(7, 20);
	addEdge(20, 8);
	addEdge(8, 19);
    addEdge(19, 9);
	addEdge(9, 18);
	addEdge(18, 10);
	addEdge(10, 17);
    addEdge(17, 6);
	

	addEdge(1, 6);
	addEdge(2, 7);
	addEdge(3, 8);
	addEdge(4, 9);
    addEdge(5, 10);

	addEdge(16, 11);
	addEdge(20, 15);
	addEdge(19, 14);
	addEdge(18, 13);
    addEdge(17, 12);
	
    addEdge(11, 12);
	addEdge(12, 13);
	addEdge(13, 14);
	addEdge(14, 15);
    addEdge(15, 11);


	// arrays required to color the
	// graph, store the parent of node
	int color[N];
	int par[N];

	// mark with unique numbers
	int mark[N];

	// store the numbers of cycle
	int cyclenumber = 0;
	int edges = 30;

	// call DFS to mark the cycles
	dfs_cycle(1, 0, color, mark, par, cyclenumber);

	// function to print the cycles
	printCycles(edges, mark, cyclenumber);
}
