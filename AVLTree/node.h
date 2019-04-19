// Node Class

using namespace std;

class Node {
    int data;
    Node* lchild;
    Node* rchild;

  public:
    Node() {
        lchild = NULL;
        rchild = NULL;
    };
    void SetData(int value) {
        data = value;
    };
    void SetLeft(Node* left) {
        lchild = left;
    };
    void SetRight(Node* right) {
        rchild = right;
    };
    int Data() {
        return data;
    };
    Node* Left() {
        return lchild;
    };
    Node* Right() {
        return rchild;
    };
};
