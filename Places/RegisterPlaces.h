//
// Created by reds on 26/1/21.
//

#ifndef NAVITEC_REGISTERPLACES_H
#define NAVITEC_REGISTERPLACES_H

#include <stdlib.h>
#include <stdbool.h>

//
//struct place
//{
//    int
//};

// A structure to represent a
// node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent
// an adjacency list
struct AdjList
{

    // Pointer to head node of list
    struct AdjListNode *head;
};

// A structure to represent a graph.
// A graph is an array of adjacency lists.
// Size of array will be V (number of
// vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
// A utility function to create
// a new adjacency list node
struct AdjListNode* newAdjListNode(
        int dest, int weight);


// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;
    int dist;
};


// Structure to represent a min heap
struct MinHeap
{

    // Number of heap nodes present currently
    int size;

    // Capacity of min heap
    int capacity;

    // This is needed for decreaseKey()
    int *pos;
    struct MinHeapNode **array;
};


// A utility function that creates
// a graph of V vertices
struct Graph* createGraph(int V);

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src,
             int dest, int weight);

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src,
             int dest, int weight);

// A utility function to create a
// new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v,
                                   int dist);

// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity);

// A utility function to swap two
// nodes of min heap.
// Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b);

// A standard function to
// heapify at given idx
// This function also updates
// position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap,
                int idx);

// Function to decreasy dist value
// of a given vertex v. This function
// uses pos[] of min heap to get the
// current index of node in min heap
void decreaseKey(struct MinHeap* minHeap,
                 int v, int dist);

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v);

// A utility function used to print the solution
void printArr(int dist[], int n);

// The main function that calulates
// distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(struct Graph* graph, int src);
#endif //NAVITEC_REGISTERPLACES_H
