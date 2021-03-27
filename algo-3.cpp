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
	cout<<n<<endl;
// 	printColours(vertices,n,maxColors);
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		queue<int> que;
		que.push(i);
		while (!que.empty())
		{
			int top = que.front();
            que.pop();
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
	cout<<maxColors<<endl;
	return maxColors;
}

void addOnVertices(int x, int y, vector<vertex> & vertices){
    vertices[x].edges.insert(y);
	vertices[y].edges.insert(x);
}

void takeInput(int n, int m, vector<vertex>& vertices){
    int e;
    cout<<"Enter the number of colours to be used i.e. m : ";
    cin >> m;
    cout<<"Enter the number of edges : ";
    cin >> e;
	for(int i = 0 ; i < e ; i++){
        int x,y;
        cin>>x>>y;
        addOnVertices(x,y,vertices);
    }
}

void addIndianMap(vector<vertex>& vertices){
    addOnVertices(0,1,vertices);
    addOnVertices(0,2,vertices);
    addOnVertices(1,2,vertices);
    addOnVertices(1,4,vertices);
    addOnVertices(1,5,vertices);
    addOnVertices(2,3,vertices);
    addOnVertices(2,5,vertices);
    addOnVertices(2,7,vertices);
    addOnVertices(3,5,vertices);    
    addOnVertices(4,8,vertices);
    addOnVertices(5,6,vertices);
    addOnVertices(5,7,vertices);
    addOnVertices(5,8,vertices);
    addOnVertices(6,7,vertices);
    addOnVertices(7,8,vertices);
    addOnVertices(7,22,vertices);
    addOnVertices(7,23,vertices);
    addOnVertices(8,9,vertices);
    addOnVertices(8,19,vertices);
    addOnVertices(8,21,vertices);
    addOnVertices(8,22,vertices);
    addOnVertices(9,18,vertices);
    addOnVertices(9,19,vertices);
    addOnVertices(10,18,vertices);
    addOnVertices(11,12,vertices);
    addOnVertices(11,17,vertices);
    addOnVertices(12,13,vertices);
    addOnVertices(12,17,vertices);
    addOnVertices(13,14,vertices);
    addOnVertices(13,17,vertices);
    addOnVertices(14,15,vertices);
    addOnVertices(14,17,vertices);
    addOnVertices(15,17,vertices);
    addOnVertices(16,17,vertices);
    addOnVertices(17,18,vertices);
    addOnVertices(18,19,vertices);
    addOnVertices(18,20,vertices);
    addOnVertices(19,20,vertices);
    addOnVertices(19,21,vertices);
    addOnVertices(19,22,vertices);
    addOnVertices(20,21,vertices);
    addOnVertices(20,27,vertices);
    addOnVertices(21,22,vertices);
    addOnVertices(21,26,vertices);
    addOnVertices(21,35,vertices);
    addOnVertices(21,36,vertices);
    addOnVertices(22,23,vertices);
    addOnVertices(23,24,vertices);
    addOnVertices(23,25,vertices);
    addOnVertices(23,26,vertices);
    addOnVertices(25,26,vertices);
    addOnVertices(26,28,vertices);
    addOnVertices(26,29,vertices);
    addOnVertices(26,35,vertices);
    addOnVertices(27,28,vertices);
    addOnVertices(27,32,vertices);
    addOnVertices(27,33,vertices);
    addOnVertices(27,35,vertices);
    addOnVertices(28,29,vertices);
    addOnVertices(28,31,vertices);
    addOnVertices(28,32,vertices);
    addOnVertices(28,35,vertices);
    addOnVertices(31,32,vertices);
    addOnVertices(31,33,vertices);
    addOnVertices(32,33,vertices);
}

void defaultInput(int n,int m,vector<vertex>& vertices){
    n = 37;
    m = 37;
    addIndianMap(vertices);
}

int main()
{
	int n = -1,m;
    cout<<"Enter the number of vertices in Graph (Press - (-1) for Indian Map): ";
    cin >> n;
    bool checkInput = true;
    if(n==-1){
        n = 37;
        checkInput = false;
    }
    vector<vertex> vertices(n);
    if(checkInput)
        takeInput(n,m,vertices);
    else
        defaultInput(n,m,vertices);
        cout<<n<<endl;
    int maxColors = canPaint(vertices,n,m);
	if(maxColors){
        cout << "\nSolution exists.";
        printColours(vertices,n,maxColors);
    }else
        cout << "Solution doesnot exists.";
	
	return 0;
}