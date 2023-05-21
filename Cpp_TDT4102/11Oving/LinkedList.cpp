#include "LinkedList.h"



std::ostream& LinkedList::operator<<(std::ostream& os, const Node& node){
    os << node.getValue();
    return os;
    
}


