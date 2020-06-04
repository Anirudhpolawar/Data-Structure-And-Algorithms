#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
struct dummynode
{
  public:
    int data;
    dummynode(int val)
    {
      data = val;
    }

};

 dummynode * previous = NULL;

bool IsBinaraySearchTreeHelper(const vector<Node> &tree,int cur)
{
    if(cur>=tree.size())
      return true;

    if(tree[cur].left!=-1&&!IsBinaraySearchTreeHelper(tree,tree[cur].left))
        return false;
    
    if(previous!=NULL&&previous->data>=tree[cur].key)
      return false;

    previous = new dummynode(tree[cur].key);

    if(tree[cur].right!=-1&&!IsBinaraySearchTreeHelper(tree,tree[cur].right))
        return false;
    
    return true;
     
}


bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  previous = NULL;
  return IsBinaraySearchTreeHelper(tree,0);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } 
  else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
