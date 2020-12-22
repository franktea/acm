#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};
 
class Codec {
    struct Node {
        int val = 0;
        bool left = false;
        bool right = false;
    };

    TreeNode* des(Node*& p) {
        TreeNode* n = new TreeNode(p->val);
        bool left = p->left;
        bool right = p->right;
        if(left) { ++p; n->left = des(p); }
        if(right) { ++p; n->right = des(p); }
        return n;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(!root) return ret;
        Node n {root->val, root->left != nullptr, root->right != nullptr};
        ret.append((const char*)(&n), sizeof(n));
        if(root->left) ret.append(serialize(root->left));
        if(root->right) ret.append(serialize(root->right));
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        Node* p = (Node*)(&data[0]);
        return des(p);
    }
};

int main() {
    TreeNode* n = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4)));
    TreeNode* n2 = Codec().deserialize(Codec().serialize(n));
    cout<<n2->val<<"\n";
    cout<<n2->left->val<<"\n";
    cout<<n2->right->val<<"\n";
    cout<<n2->right->left->val<<"\n";
}
