#include <iostream>
#include <list>
using namespace std;


class Graph{

public:
	int numVertices;
	list<int>* adjLists;
	bool* visited;
	
	Graph(int vertices)
	{
		numVertices = vertices;
		adjLists = new list<int>[vertices];
	}
	
	void addEdge(int src, int dest)
	{
		adjLists[src].push_back(dest);
		adjLists[dest].push_back(src);
	}
	
	void bfs(int src)
	{
		//initialize visited list to false
		//mark all the vertices as not visited
		
		visited = new bool[numVertices];
		for (int i=0;i<numVertices;i++)
		{
			visited[i] = false;
		}
		
		//create queue object
		list<int> q;
		
		//mark first src as true, meaning its visited
		//push it in the queue 
		visited[src] = true;
		q.push_back(src);
		
		//initialize list iterator
		list<int>::iterator i;
		
		// while queue is not empty, loop through the queue
		while (!q.empty()){
			// dequeue a vertex from the queue
			int currVertex = q.front();
			q.pop_front();
		
			// Get all adjacent vertices of the dequeued
			// vertices. If adjacent has not been visited,
			// then mark it as visited and enqueue it
			for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end();i++)
			{
				int adjVertex = *i;
				if (!visited[adjVertex])
				{
					visited[adjVertex] = true;
					q.push_back(adjVertex);
				}
			}
		
		}
	}
	
};

int main(){

	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	g.bfs(2);


	return 0;
}
