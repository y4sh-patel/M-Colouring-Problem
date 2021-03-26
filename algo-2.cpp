#include <bits/stdc++.h>
using namespace std;

void printSolution(int V, int* colors);
/*
	A utility function to check if
	the current color assignment
	is safe for vertex v i.e. checks
	whether the edge exists or not
	(i.e, graph[v][i]==1). If exist
	then checks whether the color to
	be filled in the new vertex(c is
	sent in the parameter) is already
	used by its adjacent
	vertices(i-->adj vertices) or
	not (i.e, color[i]==c)
*/
	
bool isValid(int v, int V, bool* graph, int* color, int c) {
	for (int i = 0; i < V; ++i) {
		if (*(graph + V*v + i) && c == color[i]) return false;
	}
	return true;
}
	
/*
	A recursive utility function
	to solve m coloring problem
*/
	
bool colorGraphRecursive(int V, bool* graph, int m, int* color, int v) {
	/*
		base case: If all the vertices are
		assigned a color then return true
	*/
	if (v == V)
		return true;
	
	/*
		Consider this vertex v and
		try different colors
	*/
	for (int c = 1; c <= m; ++c) {
		/*
			Check if assignment of
			color c to v is valid
		*/
		if (isValid(v, V, graph, color, c)) {
			color[v] = c;
			
			/*
				recur to assign colors to
				rest of the vertices
			*/
			if (colorGraphRecursive(V, graph, m, color, v + 1) == true)
				return true;
			
			/*
				If assigning color c doesn't
				lead to a solution then remove it
			*/
			color[v] = 0;
		}
	}
	
	/*
		If no color can be assigned to
		this vertex then return false
	*/
	return false;
}

/*
	This function solves the m Coloring
	problem using Backtracking. It mainly
	uses colorGraphRecursive() to solve the
	problem. It returns false if the m
	colors cannot be assigned, otherwise
	return true and prints assignments of
	colors to all vertices. Please note
	that there may be more than one solutions,
	this function prints one of the
	feasible solutions.
*/
bool colorGraphStarter(int V, bool* graph, int m) {
	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isValid()
	int color[V];
	for (int i =0; i < V; ++i) {
		color[i] = 0;
	}
	
	// Call colorGraphRecursive() for vertex 0
	if (colorGraphRecursive(V, graph, m, color, 0) == false) {
		cout << "Solution does not exist\n";
		return false;
	}
	
	// Print the solution
	printSolution(V, color);
	return true;
}

/* A utility function to print solution */
void printSolution(int V, int* color) {
	cout << "Solution Exists: Following are the assigned colors\n";
	for (int i = 0; i < V; ++i) cout << color[i] << " ";
	cout << "\n";
}

// driver program to test above function
int main() {
/*
	Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	 |   / |
	 |  /  |
	 | /   |
	(0)---(1)
*/
	
	// ASKING FOR USER INPUT
	
	int V, m;
	cout << "Enter the number of vertices: ";
	cin >> V;

	cout << "Enter the number of colors: ";
	cin >> m;
	
	bool graph[V][V] = {};
	
	/*
		IMPORTANT:
		now we can get adjacency matrix input using two ways:
		1) asking for connected vertices
		2) directly asking for adjacency matrix
		
		Uncomment whichever you seem fit
	*/

	// 1) asking for connected vertices
	int e;
	cout << "Enter the number of edges: ";
	cin >> e;
	cout << "Enter the vertices corresponding to each edge:\n";
	for (int i = 0; i < e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		--v1; --v2;
		graph[v1][v2] = graph[v2][v1] = 1;
	}

//	Sample Input for 1)
//	4
//	3
//	5
//	1 2
//	1 3
//	1 4
//	2 3
//	3 4

//	// 2) directly asking for adjacency matrix
//	printf("Enter the boolean adjacency matrix for the graph in %d x %d format:\n", V, V);
//	for (int i = 0; i < V; ++i) {
//		for (int j = 0; j < V; ++j) {
//			cin >> graph[i][j];
//		}
//	}

////	Sample Input for 2)
////	4
////	3
////	0 1 1 1
////	1 0 1 0
////	1 1 0 1
////	1 0 1 0
	
	// Initiating the Starter function
	colorGraphStarter(V, *graph, m);
	
	return 0;
}
