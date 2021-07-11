#include <bits/stdc++.h>
using namespace std;
size_t cap;
list<pair<int,int>> keys;

/* Question
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

    NOTE: If you are using any global variables, make sure to clear them in the constructor. 
*/

/* Hint 1:


Lets approach this question bit by bit.
If lets say you never had to remove entries from the LRU cache because we had enough space, what would you use to support and get and set ?
A simple map / hashmap would suffice.

Alright, lets now look at the second part which is where the eviction comes in. We need a data structure which at any given instance can give me the least recently used objects in order. Lets see if we can maintain a linked list to do it. We try to keep the list ordered by the order in which they are used. So whenever, a get operation happens, we would need to move that object from a certain position in the list to the front of the list. Which means a delete followed by insert at the beginning.

Insert at the beginning of the list is trivial. How do we achieve erase of the object from a random position in least time possible ?

How about we maintain another map which stores the pointer to the corresponding linked list node.

Ok, now when we know the node, we would need to know its previous and next node in the list to enable the deletion of the node from the list. We can get the next in the list from next pointer ? What about the previous node ? To encounter that, we make the list doubly linked list.

Now, can you think of an approach using doubly linked list and the map(s) ?

*/

/* Solution approach
As discussed in the previous hint, we solve this problem using :

    originalMap : A hashmap which stores the orginial key to value mapping
    accessList : A doubly linked list which has keys ordered by their access time ( Most recently used key in front of the list to least recently used key at the end of the list ).
    addressMap : A hashmap which saves the mapping of key to address of the key in accessList.

Lets see now how the get and set operation would work :

    get(key) :
    Look for the value corresponding to key in originalMap.
    If key is not found, we don’t need to change accessList. So, return -1.
    If key is found, then we need to move the node corresponding to the key to front of the list in accessList.
    To do that, we find the address of the node for key from addressMap. We make the node->prev->next = node->next;, node->next->prev = node->prev;, node->prev = NULL; node->next = head; head->prev = node;
    We update the head of the accessList to be node now.

    set(key, value)
    If the key is a new entry (it does not exist in the originalMap) AND the cache is full(size = capacity), then we would need to remove the least recently used key lkey.
    We know that this key is the key corresponding to the last node in accessList which is accessible in O(1). To evict, we delete the last node from accessList, and the entry corresponding to lkey(from last node) in addressMap and originalMap.

    Post this, there are 2 cases.
    key is a new entry and is not present in originalMap. In this case, a new node is created for key and inserted at the head of accessList. A new (key,value) entry is created into originalMap and addressMap accordingly.
    key is present in the map, in which case the value needs to be updated. We update the value in the originalMap and then we update the accessList for key exactly the way we did in the case of get operation.

A couple of insights for clean code :

    Note that the update of accessList for key when key is present is a common operation in get and a subcase of set function. We should create a function for it and call that function in both cases to reduce redundancy.
    Also, note that originalMap and addressMap are always of the same size with the same keys ( One with value and the other with address in linkedlist ). If you want to manage less maps, you can just have a masterMap which maps key to a pair of (value, address_in_list).
*/    

/*Editorial
 Node(int x, int y): key(x), val(y) , next(NULL), prev(NULL){}
}typedef Node;

Node* head = NULL;
Node* tail = NULL;
unordered_map<int, Node*> mp;
int cap;

//////////////////////////////
void add(int key, int val){
    Node* A = new Node(key, val);
    A->next = head->next;
    A->prev = head;
    head->next = A;
    A->next->prev = A;
}

void remove(Node* A){
    A->prev->next = A->next;
    A->next->prev = A->prev;
}


//////////////////////////////
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    mp.clear();
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
}

int LRUCache::get(int key) {
    if(mp.find(key) != mp.end()){ // exists in the cache
        Node* node = mp[key];
        int x = node->val;
        mp.erase(key); // from the map
        remove(node); // from the list
        add(key, x); // add to front
        mp[key] = head->next; // update in map
        return x;
    }
    else{
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) != mp.end()){ // exists already
        Node* node = mp[key];
        remove(node);
        mp.erase(key);
        add(key, value);
        mp[key] = head->next;
    }
    else{
        if(mp.size() < cap){
            // Node* node = new Node(value);
            add(key, value);
            mp[key] = head->next;
        }
        else{
            // erase LRU item
            mp.erase(tail->prev->key);
            remove(tail->prev);
            add(key, value);
            mp[key] = head->next;
        }
    }
}


*/

unordered_map< int, list<pair<int,int>>::iterator> m;
LRUCache::LRUCache(int capacity) {
    cap = capacity;
    keys.clear();
    m.clear();
}

int LRUCache::get(int key) {
    if(m.find(key)==m.end())return -1;
    auto it = m[key];
    int value = it->second;
    keys.erase(it);
    keys.push_front(make_pair(key,value));
    m[key] = keys.begin();
    return value;
}

void LRUCache::set(int key, int value) {
    if(m.find(key)!=m.end()){
        keys.erase(m[key]);
    }else{
        if(keys.size()==cap){
            m.erase(keys.end()->first);
            keys.pop_back();
        }
    }
    keys.push_front(make_pair(key,value));
    m[key] = keys.begin();
}