// Queue Class

using namespace std;

class Queue {
    Node *front;
    Node *rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void append(int data);
        void serve();
        void print();
};

void Queue::append(int data) {

    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);

   if(front == NULL){
       //cout << "First new Node added to Queue." << endl << endl;
       //front->SetPrev(NULL);
       newNode->SetNext(NULL);
       // Set front and rear to the new node
       front = newNode;
       rear = newNode;
       // Set Previous Pointer
       rear->SetPrev(NULL);

   } else if(front != NULL){
       // Set Previous Pointer
       rear->SetPrev(newNode);
       // Set Next Pointer
       newNode->SetNext(rear);
       rear = newNode;
   }

}

// Front gets served and thus deleted first
void Queue::serve() {
    Node *position;
    position = front;

    // set front pointer to next node
    front = front->Prev();

    // remove old front node
    delete position;
}

// Outputs each node value in the queue from front to rear
void Queue::print() {
    Node *position;
    position = front;
    cout << "Queue Output:" << endl;
    if ( position != NULL ) {
        // Nodes already present in the list
        // output to until the bottom of the stack is reached
        while ( position->Prev() != NULL ) {
            cout << position->Data() << endl;
            position = position->Prev();
        }
        cout << endl;
    }
}
