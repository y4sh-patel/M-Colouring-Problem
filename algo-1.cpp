#include<bits/stdc++.h>
using namespace std;
int** initializeGraph(int n){
    int** temp = new int*[n];
    for(int i=0;i<n;i++){
        temp[i] = new int[n];
    }
    return temp;
}
void printSolution(int color[] , int n){
	cout << "Solution Exists: Following are the assigned colors \n";
	for (int i = 0; i < n; i++){
        cout <<  color[i] << " ";
    }
    cout << endl;
}
bool isSafe(int** graph, int color[] , int n){

	for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (graph[i][j] && color[j] == color[i]){
				return false;
            }
        }
    }
	return true;
}
bool graphColoring(int** graph, int m, int i,int color[],int n){
    if(i == n){
        if(isSafe(graph, color, n)){
            printSolution(color, n);
            return true;
        }
        return false;
    }

    for(int j = 1; j<=m; j++){
        color[i] = j;
        if(graphColoring(graph, m, i + 1, color,n)){
            return true;
        }
        color[i] = 0;
    }
    return false;

}
int main(){

    int n,m,e;
    cout<<"Enter the number of nodes in Graph : ";
    cin >> n;
    cout<<"Enter the number of colours to be used i.e. m : ";
    cin >> m;
    cout<<"Enter the number of edges : ";
    cin >> e;
    int** graph = initializeGraph(n);
    cout<<"Enter the edges: "<<endl;
    for(int i = 0 ; i < e ; i++){
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int color[n]={0};

    bool flag = graphColoring(graph, m, 0, color, n);
    if(!flag){
        cout << "Solution does not exist";
    }
    for(int i=0; i<n; i++){
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}