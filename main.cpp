//MST Prim Program
//Gunnar Bergstrom
//Create a Minimum Spanning Tree using Prim's algorithm and display the verticies, edges, and weights
//June 11, 2024
//CIS 350

#include <bits/stdc++.h>
#include <queue>

using namespace std;
#define V 6

//Creates minimum key for the starting index of the MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++) {
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

//Prints the MST
void printMST(int parent[], int graph[V][V])
{
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << "    Weight: " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total Cost of MST: " << totalCost << endl;

}


void primMST(int graph[V][V])
{
    //Array to store constructed MST
    int parent[V];
    //Key values used to pick minimum weight edge in cut
    int key[V];
    //To represent set of vertices included in MST
    bool mstSet[V];
    //Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    //Make key 0 so that this vertex is picked first
    key[0] = 0; 
    //First node is root of MST
    parent[0] = -1;
    //The MST will have V vertices
    for (int i = 0; i < V; i++) {        
        //Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        //Add the picked vertex to the MST Set
        mstSet[u] = true;
        //Update key value and parent index of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] and mstSet[v] == false and graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}


int main()
{
    string fileName;
    string dataFileName;

    cout << "Welcome to the MST Test Program" << endl;
    cout << "Enter output file name: " << endl;
    cin >> fileName;

    int graph[V][V];
    int xNodes;
    int yEdges;
    int source;
    int destination;
    int weight;
    bool graphIsEmpty = false;

    ofstream outFile;
    outFile.open(fileName);
    if (!outFile.is_open()) {
        cout << "file<" << fileName << "> cannot be opened - program terminated" << endl;
        return 0;
    }

    outFile << "Welcome to the MST Test Program" << endl;
    cout << "Testing Default Scenario" << endl;
    outFile << "Testing Default Scenario" << endl;
    
    //Create an empty graph and test functionality – No MST
    int testGraph [V][V] = { { 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0 },
                             { 0, 0, 0, 0, 0, 0 } };

    cout << "Testing File Data" << endl;
    outFile << "Testing File Data" << endl;
    cout << "Enter file name for graph data: " << endl;
    cin >> dataFileName;
    outFile << "File name for graph data: <" << dataFileName << ">" << endl;

    ifstream data;

    data.open(dataFileName);
    if (!data.is_open()) {
        cout << "file <" << dataFileName << "> cannot be opened or does not exist - program terminated" << endl;
        outFile << "file <" << dataFileName << "> cannot be opened or does not exist - program terminated" << endl;
        return 0;
    }
    else if(data.is_open() && data.peek() == data.eof()) {
        cout << "file <" << dataFileName << "> contains no data - program terminated" << endl;
        outFile << "file <" << dataFileName << "> contains no data - program terminated" << endl;
        return 0;
    }
    

    data >> xNodes;
    data >> yEdges;
    
    if (xNodes < 0) {
        cout << "ERROR: number of vertices: <" << xNodes << "> is less than zero" << endl;
        outFile << "ERROR: number of vertices: <" << xNodes << "> is less than zero" << endl;
        cout << "Empty graph will be created" << endl;
        outFile << "Empty graph will be created" << endl;
        //Create an empty graph
        int graph [V][V];
        graphIsEmpty = true;
        cout << "Empty Graph - No MST" << endl;
        outFile << "Empty Graph - No MST" << endl;
        return 0;
    }
    else if (xNodes == 0 ) {
        cout << "Number of vertices: <" << xNodes << "> is equal to zero" << endl;
        outFile << "Number of vertices: <" << xNodes << "> is equal to zero" << endl;
        cout << "Empty graph will be created" << endl;
        outFile << "Empty graph will be created" << endl;
        //Create an empty graph
        int graph [V][V];
        graphIsEmpty = true;
    }
    else if (xNodes > 0) {
        cout << "Number of vertices: <" << xNodes << "> is greater than zero" << endl;
        outFile << "Number of vertices: <" << xNodes << "> is greater than zero" << endl;
    }

    if (yEdges < (xNodes -1)) {
        cout << "ERROR: <" << yEdges << "> edges invalid to create connected graph" << endl;
        outFile << "ERROR: <" << yEdges << "> edges invalid to create connected graph" << endl;
        //Create empty graph
        int graph [V][V];
        graphIsEmpty = true;
        if (yEdges < 0) {
            //program will treat as zero edges – file will not contain edges
            int graph [V][V];
        }
        return 0;
    }
    else {
        cout << "Graph with <" << xNodes << "> vertices and <" << yEdges << "> edges will be created " << endl;
        outFile << "Graph with <" << xNodes << "> vertices and <" << yEdges << "> edges will be created " << endl;
        //Creat graph with specified number of vertices and edges
        int graph [V][V];
    }

    cout << "Number of input edges to process is: <" << yEdges << ">" << endl;
    outFile << "Number of input edges to process is: <" << yEdges << ">" << endl;
    
    //attempt to add all edges from the input file to the graph
    for (int i = 0; i < yEdges; i++) {

        data >> source;
        data >> destination;
        data >> weight;

        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Weight: " << weight<< endl;
        outFile << "Source: " << source << endl;
        outFile << "Destination: " << destination << endl;
        outFile << "Weight: " << weight<< endl;

        graph[source][destination] = weight;
        graph[destination][source] = weight;


        if (weight == 0) {
            cout << "Empty Graph - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << ">" << endl;
            outFile << "Empty Graph - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << ">" << endl;
        
        }
        else if ((source < 0) or (source > xNodes)) {
            cout <<  "Invalid Source or Destination Vertex - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << "> - Edge request ignored" << endl;
            outFile <<  "Invalid Source or Destination Vertex - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << "> - Edge request ignored" << endl;

        }
        else if (weight < 0) {
            cout << "Invalid Weight - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << "> - Edge request ignored" << endl; 
            outFile << "Invalid Weight - Cannot Add Edge: <" << source << ">, <" << destination << ">, <" << weight << "> - Edge request ignored" << endl;
        }
        else {
            //Edge can be added to graph undirected graph so there are two edges added to graph adjacency list
            cout << "Edge Added: <" << source << ">, <" << destination << ">, <" << weight << ">" << endl;
            outFile << "Edge Added: <" << source << ">, <" << destination << ">, <" << weight << ">" << endl;
        }

    }

    //Print the full graph adjacency list
    cout << "Full Graph - Adjacency List" << endl;
    outFile << "Full Graph - Adjacency List" << endl;
    //For each vertex display graph adjacency list to user and output file in format
    for (int i = 0; i < xNodes; i++) {
        cout << "Adj[" << i << "] -> "; 
        outFile << "Adj[" << i << "] -> ";
        for (int j = 0; j < xNodes; j++){
            if (graph[i][j] > 0 and graph[i][j] <= 100) {
            cout << "(" << j << ", " << graph[i][j] << ") ";
            outFile << "(" << j << ", " << graph[i][j] << ") ";
            }
        }
        cout << endl;
        outFile << endl;
    }
    
    // Print the solution
    cout << "Minimum Spanning Tree" << endl;
    outFile << "Minimum Spanning Tree" << endl;
    
    primMST(graph);
  
    if (graphIsEmpty == true) {
        cout << "Empty Graph - No MST" << endl;
        outFile << "Empty Graph - No MST" << endl;
    }

    //cout << "MST Graph - Adjacency List" << endl;
    //outFile << "MST Graph - Adjacency List" << endl;
    
    cout << "Thank you for running the MST Test Program written by Gunnar Bergstrom!" << endl;
    outFile << "Thank you for running the MST Test Program written by Gunnar Bergstrom!" << endl;

    outFile.close();
    data.close();

    return 0;
}