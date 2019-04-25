#include <iostream>
#include <stdlib.h>

using namespace std;

class Edge {
public:
	int src;
	int des;
	int wt;
};

class Subset {
public:
	int parent;
	int rank;
};

int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->wt > b1->wt;
}

class Graph {
private:
	int V;
	int E;
public:
	Edge *edge;
	Graph(int V,int E) {
		this->E = E;
		this->V = V;
		this->edge = new Edge[this->E];
	};

	int getV() {
		return this->V;
	};

	int getE() {
		return this->E;
	};

	void printGraph() {
		for (int i = 0; i < this->E; i++) {
			cout << this->edge[i].src << "--->" << edge[i].des<<endl;
		};
	};

	int find(Subset *subset, int i) {
		if (subset[i].parent != i) {
			subset[i].parent = find(subset, subset[i].parent);
		};
		return subset[i].parent;
	};

	void Union(Subset *subset, int x, int y) {
		int xroot = find(subset, x);
		int yroot = find(subset, y);

		if (subset[xroot].rank < subset[yroot].rank) {
			subset[xroot].parent = yroot;
		}
		else {
			if (subset[xroot].rank > subset[yroot].rank) {
				subset[yroot].parent = xroot;
			}
			else {
				subset[xroot].parent = yroot;
				subset[yroot].rank++;
			};
		};
	};

	void KruskalMST() {
		Subset *subset=new Subset[this->getV];
		for (int i = 0; i < this->getV(); i++) {
			subset[i].parent = i;
			subset[i].rank = 0;
		};

		Edge *res = new Edge[this->getV()];

		qsort(this->edge, this->getE(), sizeof(this->edge[0]), myComp);

		int r = 0; /* Edge Count*/
		int k = 0; /* Final Count*/
		while (k < (this->getV() - 1)) {
			Edge edge = this->edge[r++];

			int x = find(subset, edge.src);
			int y = find(subset, edge.des);

			if (x != y) {
				res[k++] = edge;
				Union(subset, x, y);
			};
		};

		for (int i = 0; i < this->getV()-1; i++) {
			cout << res[i].src << "-->" << res[i].des << " " << res[i].wt << endl;
		};

		return;
	};
};

int main() {
	Graph *graph = new Graph(4,5);
	// add edge 0-1 
	graph->edge[0].src = 0;
	graph->edge[0].des = 1;
	graph->edge[0].wt = 10;

	// add edge 0-2 
	graph->edge[1].src = 0;
	graph->edge[1].des = 2;
	graph->edge[1].wt = 6;

	// add edge 0-3 
	graph->edge[2].src = 0;
	graph->edge[2].des = 3;
	graph->edge[2].wt = 5;

	// add edge 1-3 
	graph->edge[3].src = 1;
	graph->edge[3].des = 3;
	graph->edge[3].wt = 15;

	// add edge 2-3 
	graph->edge[4].src = 2;
	graph->edge[4].des = 3;
	graph->edge[4].wt = 4;

	graph->KruskalMST();
	return 0;
};