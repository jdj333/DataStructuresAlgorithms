using namespace std;

// Node class
class Node {
    int data;
    Node* next;
    Node* prev; // prev pointer is needed for the DoubleLinkList

  public:
    Node() {
        next = NULL;
        prev = NULL;
    };
    void SetData(int aData) {
        data = aData;
    };
    void SetNext(Node* aNext) {
        next = aNext;
    };
    int Data() {
        return data;
    };
    Node* Next() {
        return next;
    };
};

// ListList class
class LinkList {
    Node *head;

  public:
    LinkList() {
        head = NULL;
    };
    void Print();
    int Traverse();
    Node * getNode();
    void Append(int data);
    void Delete(int data);
};

/**
 * Print the contents of the list
 */
void LinkList::Print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout << tmp->Data();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else {
    // Parse and print the list
    do {
        cout << tmp->Data() << endl;
        //cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );
        //cout << "NULL" << endl;
    }
}

/**
 * Returns the Node Pointer
 */
Node * LinkList::getNode() {

    return head;
}

/**
 * Append a node to the linked list
 */
void LinkList::Append(int data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->Next() != NULL ) {
            tmp = tmp->Next();
        }

        // Point the last node to the new node
        tmp->SetNext(newNode);
    }
    else {
        // First node in the list
        head = newNode;
    }
}

/**
 * Delete a node from the list
 */
void LinkList::Delete(int data) {

    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL;
    }
    else {
    // Parse thru the nodes
    Node *prev;
    do {
        if ( tmp->Data() == data ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->SetNext(tmp->Next());

    // Delete the current node
    delete tmp;
    }
}

/**
  * Traverse the LinkedList
  */
int LinkList::Traverse() {
      int sum = 0;

      Node *tmp = head;

      if ( tmp == NULL ) {
        return sum;
      }

      // Last/Only node of the list
      if(tmp->Next() == NULL) {
         sum += tmp->Data();
         return sum;
      }
      else {
      // Parse thru the nodes
      Node *prev;
      do {
          //if ( tmp->Data() == data ) break;
          sum += tmp->Data();
          prev = tmp;
          tmp = tmp->Next();
      } while ( tmp != NULL );


      }
      return sum;
}

// DoubleLinkList class
class DoubleLinkList {
    Node *head;

  public:
    DoubleLinkList() {
        head = NULL;
    };
    void Print();
    int Traverse();
    void Append(int data);
    void Delete(int data);
    void storeNode(Node *newHead);
};

/**
 * Print the contents of the DoubleLinkList
 */
void DoubleLinkList::Print() {

    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "EMPTY" << endl;
        return;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout << tmp->Data();
        cout << " --> ";
        cout << "NULL" << endl;
    }
    else {
    // Parse and print the list
    do {
        cout << tmp->Data() << endl;
        //cout << " --> ";
        tmp = tmp->Next();
    }
    while ( tmp != NULL );
        //cout << "NULL" << endl;
    }
}

/**
 * Append a node to the DoubleLinkList
 */
void DoubleLinkList::Append(int data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head;

    if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
    }
    else {
    // First node in the list
    head = newNode;
    }
}

/**
 * Delete a node from the DoubleLinkList
 */
void DoubleLinkList::Delete(int data) {

    // Create a temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL )
    return;

    // Last node of the list
    if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL;
    }
    else {
    // Parse thru the nodes
    Node *prev;
    do {
        if ( tmp->Data() == data ) break;
        prev = tmp;
        tmp = tmp->Next();
    } while ( tmp != NULL );

    // Adjust the pointers
    prev->SetNext(tmp->Next());

    // Delete the current node
    delete tmp;
    }
}

/**
  * Traverse the DoubleLinkList
  */
int DoubleLinkList::Traverse() {
      int sum = 0;

      Node *tmp = head;

      if ( tmp == NULL ) {
        return sum;
      }

      // Last/Only node of the list
      if(tmp->Next() == NULL) {
         return sum;
      }
      else {
      // Parse thru the nodes
      Node *prev;
      do {
          //if ( tmp->Data() == data ) break;
          sum += tmp->Data();
          prev = tmp;
          tmp = tmp->Next();
      } while ( tmp != NULL );


      }
      return sum;
}

/**
  * Traverse the DoubleLinkList
  */
void DoubleLinkList::storeNode(Node *newNode) {

     int sum = 0;

     Node *tmp = newNode;

     // Create a new node



      if ( tmp == NULL ) {
            //do nothing
      }

      // Last/Only node of the list
      if(tmp->Next() == NULL) {
        Node* dNode = new Node();
        dNode->SetData(tmp->Data());
        dNode->SetNext(NULL);
      }
      else {
      // Parse thru the nodes
      Node *prev;
      do {
          Node* dNode = new Node();
          dNode->SetData(tmp->Data());
          dNode->SetNext(NULL);

          prev = tmp;
          tmp = tmp->Next();
          if(tmp->Next() == NULL){
              head = dNode;
          }
      } while ( tmp != NULL );



      }

}
