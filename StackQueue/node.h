// Node Class

using namespace std;

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
    void SetPrev(Node* aPrev) {
        prev = aPrev;
    };
    int Data() {
        return data;
    };
    Node* Next() {
        return next;
    };
    Node* Prev() {
        return prev;
    };
};
