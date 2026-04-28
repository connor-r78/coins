// must include <stdlib.h> and <errno.h>

#ifndef COINS_LINKED_LIST_H
#define COINS_LINKED_LIST_H

struct LinkedList {
  struct Node* first; 
};

struct Node {
  long data;
  struct Node* parent;
  struct Node* child;
};

struct Node* getNode(struct LinkedList* linkedList, int idx) {
  struct Node* node = linkedList->first; 
  for ( int i = 0; i < idx; ++i ) node = node->child; 
  return node; 
}

struct Node* createNode(int data, struct Node* parent, struct Node* child)
{
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
 
  newNode->data = data;
  newNode->parent = parent;
  newNode->child = child; 

  return newNode;
}

long deleteNode(struct Node* node)
{
  if ( !node ) return EINVAL;

  if ( node->parent ) node->parent->child = node->child;
  if ( node->child ) node->child->parent = node->parent;

  long ret = node->data;

  return ret;
}

struct Node* insertAtHead(struct LinkedList* linkedList, long data)
{
  struct Node* newNode = createNode(data, 0, linkedList->first);
  linkedList->first->parent = newNode;
  linkedList->first = newNode;
  return newNode;
}

#endif
