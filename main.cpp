#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}


void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}


void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
 
    // Key values used to pick minimum weight edge in cut
    int key[V];
 
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
   
    // First node is always root of MST
    parent[0] = -1;
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
         
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // Print the constructed MST
    printMST(parent, graph);
}


int main()
{
    string fileName, dataFileName;

    cout << "Welcome to the MST Test Program" << endl;
    cout << "Enter output file name: " << endl;
    cin >> fileName;

    int xNodes;
    int yEdges;

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

    cout << "Testing File Data" << endl;
    outFile << "Testing File Data" << endl;
    cout << "Enter file name for graph data: " << endl;
    cin >> dataFileName;
    outFile << "File name for graph data: <" << dataFileName << ">" << endl;

    ifstream data;

    data.open(dataFileName);
    if (!data.is_open()) {
        cout << "file <" << dataFileName << "> cannot be opened or does not exist - program terminated" << endl;
    }
    //else if(file exists but is empty) {cout << "file <" << dataFileName << "> contains no data - program terminated"}

    data >> xNodes;
    data >> yEdges;
    
    if (xNodes < 0) {
        cout << "ERROR: number of vertices: <" << xNodes << "> is less than zero" << endl;
        outFile << "ERROR: number of vertices: <" << xNodes << "> is less than zero" << endl;
        cout << "Empty graph will be created" << endl;
        outFile << "Empty graph will be created" << endl;
        //Create an empty graph
    }
    else if (xNodes == 0 ) {
        cout << "Number of vertices: <" << xNodes << "> is equal to zero" << endl;
        outFile << "Number of vertices: <" << xNodes << "> is equal to zero" << endl;
        cout << "Empty graph will be created" << endl;
        outFile << "Empty graph will be created" << endl;
        //Create an empty graph
    }
    else if (xNodes > 0) {
        cout << "Number of vertices: <" << xNodes << "> is greater than zero" << endl;
        outFile << "Number of vertices: <" << xNodes << "> is greater than zero" << endl;
    }

    if (yEdges < (xNodes -1)) {
        cout << "ERROR: <" << xNodes << "> edges invalid to create connected graph" << endl;
        outFile << "ERROR: <" << xNodes << "> edges invalid to create connected graph" << endl;
        //Create empty graph
        if (yEdges < 0) {
            //program will treat as zero edges – file will not contain edges
        }
    }
    else {
        cout << "Graph with <" << xNodes << "> and <" << yEdges << "> will be created " << endl;
        outFile << "Graph with <" << xNodes << "> and <" << yEdges << "> will be created " << endl;
        //Creat graph with specified number of vertices
    }

    cout << "Number of input edges to process is: <" << yEdges << ">" << endl;
    outFile << "Number of input edges to process is: <" << yEdges << ">" << endl;
    
    //CONTINUE HERE
    



    ifstream myfile;

    //myfile.open(fileName);
    myfile.open("CIS-Land1.dat");
    if (myfile.is_open()){

        myfile >> xNodes;
        myfile >> yEdges;
        




    }
    else {
        cout << "file<" << fileName << "> cannot be opened - program terminated" << endl;
    }
    
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}