#include "LinkedList.h"

#include <iostream>
#include <cassert>

namespace LinkedList {
    std::ostream& operator<<(std::ostream& os, const Node& node){
        os << node.getValue();
        return os;

    }


    Node* LinkedList::insert(Node *pos, const std::string& value){
        // make sure pos isn't nullptr (for debugging purposes)
	assert(pos != nullptr);
	if (pos == begin()) { // if pos is the first node
		// create a new head node, point to the old head node
		head = std::make_unique<Node>(value, std::move(head), nullptr);
		// and make the old head node point back to the new one
		pos->prev = begin();
	} else {
		// find the previous node
		auto prevNode = pos->prev;
		// make the previous node point to (and own) the new node
		prevNode->next = std::make_unique<Node>(value, std::move(prevNode->next), prevNode);
		// make the given node point back to the new node
		pos->prev = prevNode->getNext();
	}
	// return a pointer to the new node
	return pos->prev;
    }
}

void testLinkedList(){
    //Makes three nodes with different values;
    LinkedList::Node node2 {"Node 2", nullptr, nullptr};
    LinkedList::Node node3 {"Node 3", nullptr, nullptr};

    //Makes a list with the three nodes
    LinkedList::LinkedList list;
    list.insert(list.begin(), "Node 1");
    list.insert(list.begin(), "Node 3");

    //Cout our list:
    for (auto it = list.begin(); it != nullptr; it = it->getNext()){
        std::cout << *it << std::endl;
    }
    return;
    
}