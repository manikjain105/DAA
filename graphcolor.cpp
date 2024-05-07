#include<iostream>
#include<vector>
using namespace std;
#define V 4
#include <bits/stdc++.h>
// int V = 4;
 void printgraph(int color[]);
 bool graphsafe(bool graph[4][4] , int color[] , int v  , int c)
 {
     for(int i = 0; i<V; i++)
     {
         if (graph[v][i] && color[i] == c)
         return false;
     }
     return true;
 }
bool graphutil(bool graph[V][V] , int m , int color[] , int v)
{
    if(v == V)
    return true;
    for(int c= 1; c<=m; c++)
    {
        if(graphsafe(graph , color , v , c))
        {
            color[v] = c;
            
            if(graphutil(graph , m , color , v+1) == true)
            return true;
            
            color[v] = 0;
            
        }
    }
    return false;
}


bool graphcolor(bool graph[V][V] , int m)
{
    int color[V];
    for(int i =0 ; i<V; i++)
    {
        color[i] = 0;
    }
    
    
    if(graphutil(graph , m , color , 0) == false)
    return false;
    
    printgraph(color);
    return true;
}



void printgraph(int color[])
{
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
 
    cout << "\n";
}
 










int main ()
{
     bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 }
    };
    int m = 3;
    graphcolor(graph , m);
    return 0;
}