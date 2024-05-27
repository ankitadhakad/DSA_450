#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache
{
    private:

    public:
    class Node{
        public:
        int key,val;
        Node *next,*prev;
        Node(int k,int v)
        {
            key = k;
            val = v;
        }
    };
    int capacity;
    unordered_map<int,Node*>mp;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        head->next = tail;
        tail->prev= head;
    }
    void addNode(Node*newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }
    
    void deleteNode(Node*delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev; 
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here 
        if(mp.find(key) != mp.end())
        {
            Node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = head->next;
    }
};
int main()
{
    return 0;
}