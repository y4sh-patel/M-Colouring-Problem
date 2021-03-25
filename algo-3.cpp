#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class vertex
{
    public:
	int color = 1;
	set<int> edges;
};

void printColours(vector<vertex>&vertices,int n,int maxColors){
    cout << "\n\tMaximum Colours used is : "<<maxColors;
    cout << "\n\tThe colours of vertices are : ";
    cout << "\n\t\tNode  Colour";
    for(int i=0;i<n;i++)
        cout << "\n\t\t  "<<(i+1)<<" ==> "<<vertices[i].color;
}

int canPaint(vector<vertex>& vertices, int n, int m)
{
	vector<int> visited(n, 0);
	int maxColors = 1;
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		queue<int> que;
		que.push(i);
		while (!que.empty())
		{
			int top = que.pop();
			for (auto it = vertices[top].edges.begin(); it != vertices[top].edges.end(); it++)
			{
				if (vertices[top].color == vertices[*it].color)
					vertices[*it].color += 1;

				maxColors = max(maxColors, max(vertices[top].color, vertices[*it].color));
				if (maxColors > m)
					return 0;

				if (!visited[*it]) {
					visited[*it] = 1;
					que.push(*it);
				}
			}
		}
	}
	return maxColors;
}

int main()
{
	int n,m,e;
    cout<<"Enter the number of vertices in Graph : ";
    cin >> n;
    cout<<"Enter the number of colours to be used i.e. m : ";
    cin >> m;
    cout<<"Enter the number of edges : ";
    cin >> e;
	vector<vertex> vertices(n);
	for(int i = 0 ; i < e ; i++){
        int x,y;
        cin>>x>>y;
        vertices[x].edges.insert(y);
		vertices[y].edges.insert(x);
    }
    int maxColors = canPaint(vertices,n,m);
	if(maxColors){
        cout << "\nSolution exists.";
        printColours(vertices,n,maxColors);
    }else
        cout << "Solution doesnot exists.";
	
	return 0;
}