//
//  main.cpp
//  Lab 6
//
//  Created by Giovanni Masella.
//  Copyright © 2019 Giovanni. All rights reserved.
//

// Description: DFS and Dijkstra's shortest path - lab will determine if an
// undirected graph is cyclic using Dijkstra's shortest path

/* Main.cpp */
#include <iostream>
#include "Graph.hpp"
using namespace std;

int main()
{
    
    //First i am creating a graph G
    cout<<"Create Graph - G" <<endl;
    cout<< "How many vertices in your created graph? ";
    cin >> n;
    Visited = new bool [n];
    int components = 0;
    
    //declaring G of type graph from our class object
    Graph G(n);
    //Need to implement create() to create our graph
    G.Create();
    G.print();
    for(i=0; i<=n; i++)
    {
        Visited[i]=false;
    }
    for(int i=0; i<n; i++)
    {
        Visited[i]=false;
        for(k=0; k<n; k++)
        {
            if(!Visited[k])
            {
                G.DFS(0,k);
                components++;
            }
        }
        
        if(cycles)
        {
            cout<< "This graph is cyclic" << endl;
        }
        else
        {
            cout<<"This graph does NOT contain any cycles" << endl;
        }
        return 0;
    }		
}


