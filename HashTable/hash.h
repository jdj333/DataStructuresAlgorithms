// Author:        James Jenkins
// Assignment:    Program 5 - Hash Table
// Name: Hash Class

using namespace std;

class Hash {

  private:
    int MAX = 22;
    int HashTable[22];

  public:
    // no argument constructor
    Hash();

    void add(int data) {
       int key = data / 100;

       if(getHashValue(key) == -999){
           insert(data,key);
           //HashTable[key] = data;
       } else{
           cout << "Collision detected at location " << key << ", for value " << data << endl;
           resolveCollision(data, key);
       }
    };

    bool resolveCollision(int val, int loc);

    bool insert(int val, int loc);

    int getHashValue(int loc){
        return HashTable[loc];
    }

    void show();

};

// Hash Constructor with no parameters
Hash::Hash() {
    HashTable[0] = 555;

    for (int i=0; i < MAX; i++){
      HashTable[i] = -999;
      //cout << i << HashTable[i] << endl;
    }

};

// Function Name: resolveCollision
// Purpose:    detects if there is a data collision and resolves collision
// Parameters:  int data, int location (key)
// Returns:     true
// Pre-conditions: none
// Post-conditions:none
bool Hash::resolveCollision(int val, int loc) {
    cout << "Resolving collision... " << endl;
    int count = 0;
    while(HashTable[loc] != -999){
        loc++;
        if(HashTable[loc] == -999){
            insert(val,loc);
            cout << "Open slot found! Inserting data." << endl;
            break;
        }

        //reached end of array, start from beginning, searching for open slot!
        if(loc == MAX) {
            loc = 0;
        }

        count++;
        if(count > MAX) {
            cout << "No more slots available!";
            break;
        }
    }
    HashTable[loc] = val;
    return true;
};

// Function Name: insert
// Purpose:    inserts data into hash table if no colision was detected
// Parameters:  int value, int location (key)
// Returns:     true
// Pre-conditions: before inserting data, a collision must not be present in key location
// Post-conditions:none
bool Hash::insert(int val, int loc){
    HashTable[loc] = val;
    return true;
};

// Function Name: show
// Purpose:    outputs contents of hash table to console
// Parameters:  na
// Returns:     na
// Pre-conditions: none
// Post-conditions:none
void Hash::show() {

    cout << endl << "HASH TABLE contents" << endl;
    cout << "Element\tValue" <<  endl;

    for (int i=0; i<MAX; i++){
      cout << i << "\t" << HashTable[i] << endl;
    }

}
