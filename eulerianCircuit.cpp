#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph {
public:
    vector<char> vertices;
    list<int> *adjacents{};
    vector<int> edgeCount;
    int edgeID = 1;
    map<pair<int, int>, int> edges;
    vector<char> expression;
    vector<vector<char>> finalExpression;
    Graph() = default;
    void takeVertices();
    void takeEdges();
    void addEdge(char, char);
    bool isEularian() const;
    void makeCircuit(int);
    void removeEdge(int, int) const;
    void printCircuit();
    bool check();
};

void Graph::takeVertices() {
    string line;
    getline(cin, line);
    for(char & i : line)
        this->vertices.push_back(i);
    this->adjacents = new list<int>[this->vertices.size()];
    for (int i = 0; i < this->vertices.size(); i++)
        edgeCount.push_back(0);
}

void Graph::takeEdges() {
    string line;
    while(getline(cin, line)) {
        if (line.empty()) break;
        addEdge(line[0], line[1]);
        this->edgeID++;
    }
}

void Graph::addEdge(char first, char second) {
    int firstNum, secondNum;
    for(int i = 0; i < this->vertices.size(); i++) {
        if (this->vertices[i] == first) firstNum = i;
        if (this->vertices[i] == second) secondNum = i;
    }
    this->edges[make_pair(firstNum, secondNum)] = this->edgeID;
    this->edges[make_pair(secondNum, firstNum)] = this->edgeID;
    this->edgeCount[firstNum]++;
    this->edgeCount[secondNum]++;
    this->adjacents[firstNum].push_back(secondNum);
    this->adjacents[secondNum].push_back(firstNum);
}

bool Graph::isEularian() const {
    int count = 0;
    for (int i = 0; i < this->vertices.size(); i++)
        if (edgeCount[i] % 2 != 0) count++;
    if (count == 0) {
        return true;
    }
    else {
        cout << "GRAPH NOT EULERIAN" << endl;
        return false;
    }
}

void Graph::makeCircuit(int u) {

    int temp;
    int tempU = u, tempV = -1;
    auto it = this->adjacents[u].begin();
    int v = *it;
    int second = u;

    this->expression.push_back(this->vertices[u]);

    while (tempV != u) {
        temp = this->edgeID + 1;
        it = this->adjacents[second].begin();
        for (; it != this->adjacents[second].end(); it++) {
            v = *it;
            if(v != -1 && this->edges[make_pair(tempU, v)] < temp) {
                temp = this->edges[make_pair(tempU, v)];
                tempV = v;
            }
        }
        second = tempV;
        this->expression.push_back(this->vertices[tempV]);
        removeEdge(tempU, tempV);
        tempU = tempV;
    }
    this->finalExpression.push_back(this->expression);
    this->expression.clear();
    printCircuit();
}

void Graph::removeEdge(int u, int v) const {
    auto iv = find(this->adjacents[u].begin(), this->adjacents[u].end(), v);
    *iv = -1;
    auto iu = find(this->adjacents[v].begin(), this->adjacents[v].end(), u);
    *iu = -1;
}

void Graph::printCircuit() {
    if (this->finalExpression[0].size() == this->edgeID) {
        for (char &i : this->finalExpression[0]) {
            cout << i;
        }
        cout << endl;
    }
    else if (check()) {
        cout << this->finalExpression[0][0];
        int count = 0;
        for (auto & i : this->finalExpression) {
            if (count != 0) {
                for (char j : i) {
                    cout << j;
                }
            }
            else {
                count++;
            }
        }
        for (int i = (int) this->finalExpression.size(); i < this->finalExpression[0].size(); i++) {
            cout << this->finalExpression[0][i];
        }
        cout << endl;
    }
    else {
        char tempChar = this->finalExpression[0][this->finalExpression.size()];
        int tempNum = 0;
        for (int i = 0; i < this->vertices.size(); i++) {
            if (tempChar == this->vertices[i]) {
                tempNum = i;
                break;
            }
        }
        makeCircuit(tempNum);
    }
}

bool Graph::check() {
    int sum = 0;
    for (auto & i : this->finalExpression) {
        sum += (int) i.size();
    }
    if (sum - this->finalExpression.size() + 1 == this->edgeID) {
        return true;
    }
    return false;
}

int main() {
    Graph graph;                                            //Construct graph
    graph.takeVertices();                                   //Take vertices' input
    graph.takeEdges();                                      //Take edges' input
    if (graph.isEularian()) graph.makeCircuit(0);       //Check whether the graph is eularian circuit or not. If the graph is eularian circuit, printCircuit its path
    return 0;
}