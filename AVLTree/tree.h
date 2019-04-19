// AVL Tree Class

using namespace std;

// InOrder Traversal - LMR
void InOrderTraverse(Node *r){
    if(r!=NULL){
        InOrderTraverse(r->Left());
        cout << r->Data() << endl;
        InOrderTraverse(r->Right());
    }
}

// PreOrder Traversal - MLR
void PreOrderTraverse(Node *r){
    if(r!=NULL){
        cout << r->Data() << endl;
        PreOrderTraverse(r->Left());
        PreOrderTraverse(r->Right());
    }
}

class Tree{
    Node *root;

    public:
        Tree(){
            root = NULL;
        };
        void push(int data);
        // void pop();
        // void print();
        void print(string orderType);
};

void Tree::push(int data){

    //cout << "PUSH" << endl;
    bool duplicateData = false;

    // Create the root if there is no root
    if(root == NULL){
        cout << "root is NULL" << endl;
        cout << "new node set" << endl;
        Node* newNode = new Node();
        newNode->SetData(data);
        root = newNode;

    } else {
        //cout << "else called" << endl;
        // Create a temp pointer to traverse
        Node *position;
        position = root;


        // First check to make sure the data is not already in the tree.
        while(position != NULL) {


            cout << "Position: " << position->Data() << endl;

            // Check if there was a duplicate found, if so, break out
            if(position->Data() == data) {
                duplicateData = true;
                cout << "Duplicate Found!" << endl;
                break;
            }

            if((position->Left() == NULL) && (position->Right() == NULL) && (duplicateData == false)){

                Node* newNode = new Node();
                newNode->SetData(data);

                if(data < position->Data()){
                    cout << "new node set to left" << endl;
                    position->SetLeft(newNode);
                    break;
                } else if(data > position->Data()){
                    cout << "new node set to right" << endl;
                    position->SetRight(newNode);
                    break;
                }
            } else if(position->Data() > data){ //go left?

                if(position->Left() != NULL){
                    position = position->Left();
                } else{
                    cout << "new node set to left" << endl;
                    Node* newNode = new Node();
                    newNode->SetData(data);
                    position->SetLeft(newNode);
                    break;
                }

            } else if(position->Data() < data){ //go right?

                if(position->Right() != NULL){
                    position = position->Right();
                } else{
                    cout << "new node set to right" << endl;
                    Node* newNode = new Node();
                    newNode->SetData(data);
                    position->SetRight(newNode);
                    break;
                }
            }

        }
    }
}

void Tree::print(string orderType){
    Node *position;
    position = root;

    if(orderType == "inorder"){
        cout << endl << "Printing InOrder Tree:" << endl;
        InOrderTraverse(position);
    }
    if(orderType == "preorder"){
        cout << endl << "Printing PreOrder Tree:" << endl;
        PreOrderTraverse(position);
    }

}
