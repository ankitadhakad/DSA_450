
#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int data;
};

// function to get nodes at each level

//O(N^2);
void EachLevel(Node* root,
               unordered_map<int, vector<int> >& mm,
               int level)
{
    // base case
    if (!root)
        return;

    // adding node to its level
    mm[level].push_back(root->data);

    // increasing level
    level++;

    // moving left
    EachLevel(root->left, mm, level);

    // moving right
    EachLevel(root->right, mm, level);
}

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(unordered_map<int, vector<int> > mm1,
                 unordered_map<int, vector<int> > mm2)
{
    // map to help in checking anagram
    unordered_map<int, int> temp;

    // iterating each level of tree1
    for (auto x : mm1) {
        // storing node for current level
        for (auto y : x.second) {
            temp[y]++;
        }

        // checking if tree1 have node same as tree2
        // level or not
        for (auto y : mm2[x.first]) {
            if (!temp[y])
                return false;
            temp[y]--;
        }
    }

    // clearing map to check level of
    // tree2 as like tree1
    temp.clear();

    // iterating over tree2 levels
    for (auto x : mm2) {
        // storing each level nodes
        for (auto y : x.second) {
            temp[y]++;
        }

        // checking if tree2 have nodes at current
        // level as tree1
        for (auto y : mm1[x.first]) {
            if (!temp[y])
                return false;
            temp[y]--;
        }
    }

    return true;
}

// Utility function to create a new tree Node

 
 //O(NlogN)   
    bool areAnagramsII(Node *root1, Node *root2)
    {queue<Node*>q1;
    queue<Node*>q2;
        if(!root1 && !root2)
        return true;
        if(!root1 || !root2)
        return false;
        q1.push(root1);
        q2.push(root2);
        while(true)
        {
            int n1 = q1.size();
            int n2 = q2.size();
            if(n1!=n2)
            return false;
            if(n1 == 0)
            break;
            vector<int>curr_level1;
            vector<int>curr_level2;
            while(n1--)
            {
                Node *node = q1.front();
                curr_level1.push_back(node->data);
                q1.pop();
                if(node->left)
                q1.push(node->left);
                if(node->right)
                q1.push(node->right);
                
            }
             while(n2--)
            {
                Node *node = q2.front();
                curr_level2.push_back(node->data);
                q2.pop();
                if(node->left)
                q2.push(node->left);
                if(node->right)
                q2.push(node->right);
                
            }
            sort(curr_level1.begin(),curr_level1.end());
            sort(curr_level2.begin(),curr_level2.end());
            if(curr_level1 != curr_level2)
            return false;

        }
        return true;
    }

//O(N)
    bool areAnagramsIII(Node* root1, Node* root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    // start level order traversal of two trees
    // using two queues.
    queue<Node*> q1, q2;
    q1.push(root1);
    q2.push(root2);

    // Hashmap to store the elements that occur in each
    // level.
    unordered_map<int, int> m;

    while (!q1.empty() && !q2.empty()) {
        // n1 (queue size) indicates number of Nodes
        // at current level in first tree and n2 indicates
        // number of nodes in current level of second tree.
        int n1 = q1.size(), n2 = q2.size();

        // If n1 and n2 are different
        if (n1 != n2)
            return false;

        // If level order traversal is over
        if (n1 == 0)
            break;

        // Dequeue all Nodes of current level and
        // Enqueue all Nodes of next level
        while (n1--) {
            Node* node1 = q1.front();
            q1.pop();

            // Insert element into hashmap
            m[node1->data]++;

            // Insert left and right nodes into queue if
            // exists.
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
        }

        while (n2--) {
            Node* node2 = q2.front();
            q2.pop();

            // if element from second tree isn't present in
            // the first tree of same level then it can't be
            // an anagram.
            if (m.find(node2->data) == m.end())
                return false;

            // Reduce frequency of element if present else
            // adds it element to hash map with negative
            // frequency.
            m[node2->data]--;

            // If frequency of the element becomes zero then
            // remove the element from hashmap.
            if (m[node2->data] == 0)
                m.erase(node2->data);

            // Insert left and right nodes into queue if
            // exists.
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
        }

        // If nodes of current levels are anagrams the
        // hashmap wouldn't contain any elements.
        if (m.size() > 0)
            return false;
    }
    if (q1.empty() && q2.empty())
        return true;
    return false;
}
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // maps for both trees
    unordered_map<int, vector<int> > mm1, mm2;

    EachLevel(root1, mm1, 0);
    EachLevel(root2, mm2, 0);

    if (areAnagrams(mm1, mm2))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

