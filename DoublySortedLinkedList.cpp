#include <iostream>
#include <string>

using namespace std;

class DoublySortedLinkedList {
private:
	class Node {
	public:
		string name;
		int weight;
		Node* nextName;
		Node* nextWeight;

		// Node constructor
		Node(string n, int w) {
			name = n;
			weight = w;
		};
	};

	Node* headName;
	Node* headWeight;

public:
	DoublySortedLinkedList() {
		headName = nullptr;
		headWeight = nullptr;
	};

	void addNode(string n, int w) {
		// Create a new node
		Node* newNode = new Node(n, w);

		// ======== INSERT BY NAME ========
		Node* currNode = headName;
		Node* prevNode = nullptr;

		// Traverse by name until we find the correct location
		while (currNode != nullptr && currNode->name < n) {
			prevNode = currNode;
			currNode = currNode->nextName;
		}

		// If we are at the head, redirect head
		if (currNode == headName) {
			newNode->nextName = headName;
			headName = newNode;
		}
		// Otherwise, insert between prev and curr nodes
		else {
			prevNode->nextName = newNode;
			newNode->nextName = currNode;
		}

		// ======== INSERT BY WEIGHT ========
		currNode = headWeight;
		prevNode = nullptr;

		// Traverse by weight until we find the correct location
		while (currNode != nullptr && currNode->weight < w) {
			prevNode = currNode;
			currNode = currNode->nextWeight;
		}

		// If we are at the head, redirect the head pointer
		if (currNode == headWeight) {
			newNode->nextWeight = headWeight;
			headWeight = newNode;
		}
		// Otherwise, insert between prev and curr nodes
		else {
			prevNode->nextWeight = newNode;
			newNode->nextWeight = currNode;
		}

	};
	
	// Function reads in a name and weight from the console,
	// each on a separate line,
	// and adds it to the linked list in sorted order
	void readInput() {
		string inputName;
		string inputWeight;

		cin >> inputName;
		cin >> inputWeight;

		addNode(inputName, stoi(inputWeight));
	};

	// Print names and weights sorted by name
	void printLLByName() {
		Node* curr = headName;

		cout << "Names and weights sorted by weight: ";
		while (curr != nullptr) {
			cout << curr->name << " - " << curr->weight << ", ";
			curr = curr->nextName;
		}

		cout << endl;
	};

	// Print names and weights sorted by weight
	void printLLByWeight() {
		Node* curr = headWeight;

		cout << "Names and weights sorted by weight: ";
		while (curr != nullptr) {
			cout << curr->name << " - " << curr->weight << ", ";
			curr = curr->nextWeight;
		}

		cout << endl;
	};
};


int main() {
	DoublySortedLinkedList* LL = new DoublySortedLinkedList();

	for (int i = 0; i < 15; i++) {
		LL->readInput();
	}

	LL->printLLByName();
	LL->printLLByWeight();
}