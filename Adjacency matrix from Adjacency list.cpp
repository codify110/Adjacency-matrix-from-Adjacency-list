#include<iostream>
#include<string>
using namespace std;
struct Node
{
int data;
char nodeName;
Node* next;
};

void show(int** ADJ, int size)
{
char c;
cout << "\t";
for (int i = 0; i < size; i++)

cout << char('A' + i) << "\t";
cout << endl;
cout << endl;

for (int i = 0; i < size; i++)
{
cout << char('A' + i) << "|\t";
for (int j = 0; j < size; j++)
cout << ADJ[i][j] << "\t";
cout << endl;
}
}

void showadjlist(Node** adjacencyList, int size)
{
for (int i = 0; i < size; i++)
{
Node* temp = adjacencyList[i];
for (int j = 0; temp != NULL; j++)
{
cout << temp->nodeName << "(" << temp->data << ")";
if (temp->next != NULL)
cout << " -> ";
temp = temp->next;
}
cout << endl;
}
}
int input(string m = "")
{
int data;
cout << m;
cin >> data;
return data;
}
int main()
{
int size = input("Enter NUMBER OF VERTICES: ");

int** adjacencyMatrix = new int*[size];
Node** adjacencyList = new Node*[size];

for (int i = 0; i < size; i++)
{
adjacencyMatrix[i] = new int[size];
for (int j = 0; j < size; j++)
adjacencyMatrix[i][j] = 0;

adjacencyList[i] = new Node;
adjacencyList[i]->nodeName = 'A' + i;
cout << "Enter value of vertex " << adjacencyList[i]->nodeName << ": ";
adjacencyList[i]->data = input();
adjacencyList[i]->next = NULL;
}

for (int i = 0; i < size; i++)
{
cout << "Enter number of adjacent nodes of Vertex " << adjacencyList[i]->nodeName << ": ";
int adjacentNodes = input();
Node* temp = adjacencyList[i];
for (int j = 0; j < adjacentNodes; j++)
{
cout << "PLEASE Enter NAME OF node : ";
char c;
cin >> c;
int node = c - 'A';
Node* n = new Node;
n->nodeName = c;
n->data = adjacencyList[node]->data;
temp->next = n;
temp = temp->next;
adjacencyMatrix[i][node] = 1;
}
temp->next = NULL;
}

cout << endl;
cout << "RESULTANT Adjacency List" << endl;
showadjlist(adjacencyList, size);

cout << endl;
cout << "RESULTANT Adjacency Matrix" << endl;
show(adjacencyMatrix, size);

system("pause");
}
