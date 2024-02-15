#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Graphs
{
public:

  struct Edge {
	int a, b, c;

	Edge& operator=(const Edge& e){
	  if (this == &e) {
		return *this;
	  }
	  a = e.a;
	  b = e.b;
	  c = e.c;
	  return *this;
	}

	bool operator<(const Edge& e) const {
	  return c < e.c;
	}
  };

  static vector<vector<int>> getAdjacencyList() {
	return vector<vector<int>>
	{
	  {1, 3},
	  { 0, 5, 6 },
	  { 6 },
	  { 0, 4 },
	  { 3, 7 },
	  { 1, 6 },
	  { 1, 2, 5 },
	  { 4 }
	};
  }

  static vector<vector<pair<int, int>>> getWeightedAdjacencyList() {
	return
	{
	  { { 1, 10 }, { 5, 5 } },
	  { { 0, 10 }, { 2, 1 } },
	  { { 1, 1 }, { 3, 5 }, { 5, 7 }, {6, 10} },
	  { { 2, 5 }, { 4, 1 } },
	  { { 3, 1 }, { 6, 2 } },
	  { { 0, 5 }, { 2, 7 }, { 6, 100 }, {7 ,3 } },
	  { { 2, 10 }, { 4, 2 }, {5, 100}, {7, 8}, {8, 100}},
	  { { 5, 3 }, { 6, 8 }, {9, 1} },
	  { { 6, 100 }, {9, 1} },
	  { { 7, 1 }, {8, 1} }
	};
  }

  static vector<vector<int>> getAdjacencyMatrix() {
	return vector<vector<int>>{
	  { 0, 1, 0, 1, 0, 0, 0, 0 },
	  { 1, 0, 0, 0, 0, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 0, 1, 0 },
	  { 1, 0, 0, 0, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 0, 0, 0, 1 },
	  { 0, 1, 0, 0, 0, 0, 1, 0 },
	  { 0, 1, 1, 0, 0, 1, 0, 0 },
	  { 0, 0, 0, 0, 1, 0, 0, 0 }
	};
  }

  static vector<Edge> getVectorOfEdges() {
	return {
	  {1, 2, 5},
	  {1, 3, 9},
	  {1, 5, 1},
	  {1, 6, 3},
	  {2, 4, 8},
	  {2, 6, 3},
	  {3, 5, 4},
	  {4, 6, 7},
	  {5, 6, 2}
	};
  }

  static void fillListOfEdges() {

	// List of edges
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
	  int a, b;
	  cin >> a >> b;
	  edges[i] = { a, b };
	}

	cout << "List of edges" << endl;
	for (int i = 0; i < m; ++i) {
	  std::cout << edges[i].first << " " << edges[i].second << std::endl;
	}
  }

  static void fillAdjacencyMatrix() {
	//Adjacency matrix
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < m; ++i) {
	  int a, b;
	  cin >> a >> b;
	  // 1 <= a, b <= n;
	  --a;
	  --b;
	  matrix[a][b] = 1;
	  matrix[b][a] = 1;
	}

	cout << "Adjacency matrix" << endl;
	for (int i = 0; i < n; ++i) {
	  cout << i + 1 << ": ";
	  for (int j = 0; j < n; ++j) {
		cout << matrix[i][j];
	  }
	  cout << endl;
	}
  }

  static void fillAdjacencyList() {
	// Adjacency list
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < m; ++i) {
	  int a, b;
	  cin >> a >> b;
	  --a, --b;
	  matrix[a].push_back(b);
	  matrix[b].push_back(a);
	}

	cout << "Adjacency list" << endl;
	for (int i = 0; i < n; ++i) {
	  cout << i + 1 << ": ";
	  for (int j = 0; j < matrix[i].size(); ++j) {
		cout << matrix[i][j] + 1 << " ";
	  }
	  cout << endl;
	}
  }

  static void dfsList(const vector<vector<int>>& graph, vector<int>& used, int currentVertex) {
	cout << currentVertex + 1 << " ";
	used[currentVertex] = 1;
	for (int i = 0; i < graph[currentVertex].size(); ++i) {
	  int adjacentVertex = graph[currentVertex][i];
	  if (!used[adjacentVertex]) {
		dfsList(graph, used, adjacentVertex);
	  }
	}
  }

  static void dfsMatrix(const vector<vector<int>>& graph, vector<int>& used, int currentVertex) {
	cout << currentVertex + 1 << " ";
	used[currentVertex] = 1;
	for (int i = 0; i < graph[currentVertex].size(); ++i) {
	  if (graph[currentVertex][i] && !used[i]) {
		dfsMatrix(graph, used, i);
	  }
	}
  }

  static void bfsList(const vector<vector<int>>& graph) {
	int startVertex = 0;
	vector<int> used(graph.size(), 0);
	used[startVertex] = 1;
	queue<int> q;
	q.push(startVertex);

	while (!q.empty()) {
	  int currentVertex = q.front();
	  q.pop();
	  cout << currentVertex + 1 << " ";
	  for (int i = 0; i < graph[currentVertex].size(); ++i) {
		int adjacentVertex = graph[currentVertex][i];
		if (!used[adjacentVertex]) {
		  q.push(adjacentVertex);
		  used[adjacentVertex] = 1;

		}
	  }
	}
  }

  static void bfsMatrix(const vector<vector<int>>& graph) {
	int startVertex = 0;
	vector<int> used(graph.size(), 0);
	used[startVertex] = 1;
	queue<int> q;
	q.push(startVertex);

	while (!q.empty()) {
	  int currentVertex = q.front();
	  q.pop();
	  cout << currentVertex + 1 << " ";
	  for (int i = 0; i < graph[currentVertex].size(); ++i) {
		if (graph[currentVertex][i] && !used[i]) {
		  q.push(i);
		  used[i] = 1;
		}
	  }
	}

  }

  static void dfsGraphWithConnectedComponents() {
	vector<vector<int>> graph = {
	  {4, 5},
	  {3},
	  {3},
	  {1, 2, 9},
	  {0},
	  {0},
	  {},
	  {8},
	  {7},
	  {3}
	};
	vector<int> used(graph.size());
	for (int i = 0; i < graph.size(); i++)
	{
	  if (!used[i]) {
		Graphs::dfsList(graph, used, i);
		cout << endl;
	  }
	}
  }

  static void minDistanceInGraph(const vector<vector<int>>& graph, int startVertex) {
	//based on bfs
	//If you want to run it for each vertex you get O(n * (n + m))
	vector<int> used(graph.size(), -1);
	used[startVertex] = 0;
	queue<int> q;
	q.push(startVertex);

	while (!q.empty()) {
	  int currentVertex = q.front();
	  q.pop();
	  cout << currentVertex + 1 << " ";
	  for (int i = 0; i < graph[currentVertex].size(); ++i) {
		int adjacentVertex = graph[currentVertex][i];
		if (used[adjacentVertex] == -1) {
		  q.push(adjacentVertex);
		  used[adjacentVertex] = used[currentVertex] + 1;
		}
	  }
	}
	cout << endl;
	for (int i = 0; i < used.size(); ++i) {
	  cout << i + 1 << " " << used[i] << endl;
	}
  }

  static void topologicalSort(const vector<vector<int>>& graph, vector<int>& used, vector<int>& order, int currentVertex) {
	//base on DFS algorithm
	used[currentVertex] = 1;
	for (int i = 0; i < graph[currentVertex].size(); ++i) {
	  int adjacentVertex = graph[currentVertex][i];
	  if (!used[adjacentVertex]) {
		topologicalSort(graph, used, order, adjacentVertex);
	  }
	}
	order.push_back(currentVertex);
  }

  static void dfsReverse(const vector<vector<int>>& graph, vector<int>& used, vector<int>& component, int currentVertex) {
	//base on DFS algorithm
	component.push_back(currentVertex + 1);
	used[currentVertex] = 1;
	for (int i = 0; i < graph[currentVertex].size(); ++i) {
	  int adjacentVertex = graph[currentVertex][i];
	  if (!used[adjacentVertex]) {
		dfsReverse(graph, used, component, adjacentVertex);
	  }
	}
  }

  static void findStronglyConnectedComponents(const vector<vector<int>>& graph) {
	vector<int> used(graph.size());
	vector<int> order;
	for (int i = 0; i < graph.size(); ++i)
	{
	  if (!used[i]) {
		Graphs::topologicalSort(graph, used, order, i);
	  }
	}
	reverse(order.begin(), order.end());
	vector<vector<int>> reversedGraph(graph.size());
	for (int i = 0; i < graph.size(); ++i)
	{
	  for (int j = 0; j < graph[i].size(); ++j) {
		// i --> graphp[i][j]
		reversedGraph[graph[i][j]].push_back(i);
	  }
	}
	used.assign(graph.size(), 0);
	for (int i = 0; i < order.size(); ++i)
	{
	  if (!used[order[i]]) {
		vector<int> component;
		Graphs::dfsReverse(reversedGraph, used, component, order[i]);
		sort(component.begin(), component.end());
		for (auto a : component)
		{
		  cout << a << " ";
		}
		cout << endl;
	  }
	}
  }

  static vector<vector<int>> listToMatrixOfEdges(const vector<vector<pair<int, int>>>& graph) {
	const int Inf = (int)1e9 + 7;
	vector<vector<int>> graph2(graph.size(), vector<int>(graph.size(), Inf));
	for (int i = 0; i < graph.size(); ++i) {
	  for (int j = 0; j < graph[i].size(); ++j) {
		graph2[i][graph[i][j].first] = graph[i][j].second;
		graph2[graph[i][j].first][i] = graph[i][j].second;
	  }
	}
	return graph2;
  }

  static vector<vector<int>> floydWarshall(vector<vector<int>>& dist) {
	//Floyd-Warshall algorithm
	const int n = (int)dist.size();
	for (int k = 0; k < n; ++k) {
	  for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		  if (i == j) {
			dist[i][j] = 0;
		  }
		  else {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		  }
		}
	  }
	}
	return dist;
  }

  static vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start_vertex) {
	//Dijkstra's algorithm
	const int INF = 1000000000;
	vector<int> dist(graph.size(), INF);
	dist[start_vertex] = 0;
	set<pair<int, int>> s;
	//{dist[v], v}
	s.insert({ 0, start_vertex });

	while (!s.empty()) { //O(m * log(n))
	  int currentVertex = s.begin()->second;
	  s.erase(s.begin());
	  for (int i = 0; i < graph[currentVertex].size(); ++i) {
		int adjacentVertex = graph[currentVertex][i].first;
		int weight = graph[currentVertex][i].second;
		if (dist[currentVertex] + weight < dist[adjacentVertex]) {
		  s.erase({ dist[adjacentVertex], adjacentVertex });
		  dist[adjacentVertex] = dist[currentVertex] + weight;
		  s.insert({ dist[adjacentVertex], adjacentVertex });
		}
	  }
	}
	return dist;
  }

  static void eulerCycle(const vector<vector<int>>& graph, map<pair<int, int>, int>& edges, vector<int>& cycle, int currentVertex) {
	for (int i = 0; i < graph[currentVertex].size(); ++i) {
	  int adjacentVertex = graph[currentVertex][i];
	  int a = currentVertex;
	  int b = adjacentVertex;
	  if (a > b) {
		swap(a, b);
	  }
	  if (edges[{a, b}]) {
		edges[{a, b}]--;
		eulerCycle(graph, edges, cycle, adjacentVertex);
	  }
	}
	cycle.push_back(currentVertex);
  }

  static void testEulerCycle() {
	vector<vector<int>> graph{
	  {1,3,4},
	  {0,2,3,4},
	  {1,3},
	  {0,1,2,4},
	  {0,1,3}
	};

	vector<int> oddVertices;
	for (int i = 0; i < graph.size(); i++)
	{
	  if (graph[i].size() & 1) {
		oddVertices.push_back(i);
	  }
	}
	if (oddVertices.size() > 2) {
	  cout << "No Eulerian cycle and path exists" << endl;
	  exit(0);
	}
	else if (oddVertices.size() == 2) {
	  graph[oddVertices[0]].push_back(oddVertices[1]);
	  graph[oddVertices[1]].push_back(oddVertices[0]);
	}

	vector<int> cycle;
	map<pair<int, int>, int> edges;
	for (int i = 0; i < graph.size(); i++)
	{
	  for (int j = 0; j < graph[i].size(); j++)
	  {
		if (i < graph[i][j]) {
		  edges[make_pair(i, graph[i][j])]++;
		}
	  }
	}
	Graphs::eulerCycle(graph, edges, cycle, 0);
	for (int i = 0; i < cycle.size(); ++i)
	{
	  cout << cycle[i] + 1 << " ";
	}
	cout << endl;

	if (oddVertices.size() == 2) {
	  for (int i = 1; i < cycle.size(); i++) {
		if ((cycle[i - 1] == oddVertices[0] && cycle[i] == oddVertices[1]) || (cycle[i - 1] == oddVertices[1] && cycle[i] == oddVertices[0])) {
		  vector<int> newCycle;
		  for (int j = i; j < i + cycle.size(); j++) {
			int index = j % cycle.size();
			if (index == 0) {
			  continue;
			}
			newCycle.push_back(cycle[index]);
		  }
		  cycle = newCycle;
		}
	  }
	}

	for (int i = 0; i < cycle.size(); ++i)
	{
	  cout << cycle[i] + 1 << " ";
	}
  }

  static int findSet(int v, vector<int>& parent)
  {
	if (parent[v] == v)
	  return v;
	else
	  return parent[v] = findSet(parent[v], parent);
  }

  static void unionSet(int a, int b, vector<int>& parent, vector<int>& sizes)
  {
	a = findSet(a, parent);
	b = findSet(b, parent);
	if (a != b) {
	  if (sizes[a] < sizes[b]) {
		swap(a, b);
	  }
	  parent[b] = a;
	  sizes[a] += sizes[b];
	}
  }

  static void minimumSpanningTreeKruskal(vector<Edge>& edges, int n) {
	sort(edges.begin(), edges.end());

	vector<int> parent(n);
	vector<int> sizes(n, 1);
	for (int i = 0; i < parent.size(); ++i) {
	  parent[i] = i;
	}

	int allCosts = 0;
	for (int i = 0; i < edges.size(); ++i) {
	  int a = edges[i].a;
	  int b = edges[i].b;
	  int c = edges[i].c;
	  if (findSet(a, parent) != findSet(b, parent)) {
		cout << a << " " << b << endl;
		allCosts += c;
		unionSet(a, b, parent, sizes);
	  }
	}
	cout << allCosts << endl;
  }
};