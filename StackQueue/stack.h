// Stack Class

using namespace std;

class Stack {
    Node *top;

    public:
        Stack(){
            top = NULL;
        };
        void push(int data);
        void pop();
        void print();
};

// adds a node node with a data value to the top of the stack
void Stack::push(int data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);

    // check if top is NULL and point next node to NULL
    if ( top == NULL ) {
        //cout << "First new Node added to Stack." << endl << endl;
        newNode->SetNext(NULL);
    } else {
    // if top is not NULL then point the new node to the top
        newNode->SetNext(top);
    }

    // now set top to be the new node
    top = newNode;

}

// removes the top node from a stack
void Stack::pop() {
    Node *position;
    position = top;

    // set top pointer to next node
    top = top->Next();

    // remove old top node
    delete position;

}

// Outputs each node value in the stack from top
void Stack::print() {
    Node *position;
    position = top;
    cout << "Stack Output:" << endl;
    if ( position != NULL ) {
        // Nodes already present in the list
        // output to until the bottom of the stack is reached
        while ( position->Next() != NULL ) {
            cout << position->Data() << endl;
            position = position->Next();
        }
        cout << endl;
    }
}
