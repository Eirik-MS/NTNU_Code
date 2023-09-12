#include "LinkedList.h"
#include "TemplateLinkedList.h"
#include "templatefunctions.h"
#include "stdLists.h"
#include "iterators.h"


int main() {
    iterators_vec();
    iterators_set();
    testStdLists();
    testLinkedList();
    testTemplateFunctions();
    testTemplateLinkedList();
    
    //Frivillig oppgave: 
    //testLinkedListOverflow();

    //Uncomment implementasjon av destruktøren i LinkedList.h for å få det til å fungere.
}
