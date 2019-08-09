//
//  Graph.hpp
//  Lab 6
//
//  Created by Giovanni Masella.
//  Copyright © 2019 Giovanni. All rights reserved.
//

/* Graph.h */
#include <iostream>
using namespace std;
#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__

int n, e, i, j, k, intitialVertex;
int weight[10][10];
int weightedEdge;
bool * Visited;
bool cycles=false;

struct Vertex
{
    int vertexNum;
    Vertex *next;
};

class Graph
{
public:
    Vertex *headVertexs;
    Graph ( int Vertexs )
    {
        n=Vertexs;
        headVertexs= new Vertex [n];
        for (i=0; i < n; i++)
        {
            headVertexs[i].vertexNum=i;
            headVertexs[i].next=0;
        }
    }
    // THis is where we go to create our graph
    // We create the graph with a given amount of edges and we can weigh the edges here also
    void Create()
    {
        Vertex *previousVertex;
        Vertex *newVertex;
        cout << "Number of edges: ";
        cin >> e;
        cout << endl;
        cout << "Edges are formed [Edge = (v1,v2)]" << endl << endl;
        //For loop assigns edges that connext two vertices
 
        for(i = 1; i <= e; i++)
        {
            cout << "Edge " << i << endl;
            cout << "v1: ";
            cin >> v1;
            cout << "v2: ";
            cin >> v2;
            cout << endl;
            
            newVertex = new Vertex;
            newVertex -> vertexNum = v2;
            /*
             
            //Linking the vertices
             
             */
            if(headVertexs[v1].next==NULL)
            {
                newVertex->next= NULL;
                headVertexs[v1].next=newVertex;
            }
            else
            {
                previousVertex =&headVertexs[v1];
                while(previousVertex->next != NULL)
                {
                    previousVertex= previousVertex->next;
                }
                newVertex->next = NULL;
                previousVertex ->next = newVertex;
            }
            
            newVertex= new Vertex;
            newVertex->vertexNum= v1;
            
            if (headVertexs[v2].next== NULL)
            {
                newVertex->next= NULL;
                headVertexs[v2].next=newVertex;
            }
            else
            {
                previousVertex= &headVertexs[v2];
                while(previousVertex->next != NULL)
                {
                    previousVertex=previousVertex->next;
                }
                newVertex->next= NULL;
                previousVertex->next= newVertex;
            }
        }
    }
       void DFS(int parent, int v)
    {
        Visited[v]=true;
        Vertex* adjacentVertex=headVertexs[v].next;
        while(adjacentVertex)
        {
            if(!Visited[adjacentVertex->vertexNum])
            {
                DFS(v, adjacentVertex->vertexNum);
            }
            else if(parent != adjacentVertex->vertexNum)	
            {
                cycles=true;
            }
            adjacentVertex= adjacentVertex->next;
        }
    }
    
    void print()
    {
        Vertex *tempVertex;
        for(i=0; i<n; i++)
        {
            tempVertex = &headVertexs[i];
            while(tempVertex != NULL)				
            {
                cout<< "(" << tempVertex->vertexNum << ")" << "-->";
                tempVertex=tempVertex->next;
            }
            cout<<endl;
        }
        cout << endl << endl;
    }
    
private: 
    int v1;
    int v2;
};

#endif




