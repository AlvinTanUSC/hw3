#include "llrec.h"  
using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  Node* temp;
  if(head -> val <= pivot){
    smaller = head;
    llpivot(head->next, temp, larger, pivot);
    smaller->next = temp;
  } else {
    larger = head;
    llpivot(head->next, smaller, temp, pivot);
    larger->next = temp;
  }
  head = NULL;
}
