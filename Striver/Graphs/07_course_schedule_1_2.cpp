# include <bits/stdc++.h>
using namespace std ;

// Given a list of tasks and their prerequisites, we need to tell if it's possible to perform those tasks, on a 
// single thread, ie, you can only do one task at once.

//* So, in short, we just need to create a directed graph with the tasks as nodes, and their order as the directed
//* edges. 
//* If the graph is cyclic, then we can't perform the tasks. -> Use toposort or DFS to detect cycle in the graph.