#include <iostream>
#include <vector>
#include <algorithm>
#define null 0
using namespace std;

template <typename T>
class Tree; //프로토 타입

template <typename T>
class TreeNode
{
    friend class Tree<T>; //TreeNode는 Babo,Tree는 Trash
private:
    T data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(T data = 0, TreeNode *left = null, TreeNode *right = null)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

public:
    Tree(T data = 0)
    {
        root = new TreeNode<T>(data);
    }
    // Tree 만들기
    /*
                A
            B        C
        D      E      F   G
    H   I  J       K 
    */
    void buildTree()
    {
        root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
        root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
    }

    TreeNode<T> *getRoot()
    {
        return root;
    }

    void visit(TreeNode<T> *current)
    {
        cout << current->data << " ";
    }
    // 전위 순회 Current(root) - Left - Right
    void preorder(TreeNode<T> *current) //자기자신 ,왼쪽 ,오른쪽
    {
        if (current != null)
        { //자신이 끝 값인지 확인
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }
    // 중위순회  left,root,right
    void inorder(TreeNode<T> *current) // 왼쪽 자기자신 오른쪽
    {
        if (current != null)
        { //자신이 끝 값인지 확인
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }
    //후위순회 left,right,root
    void postorder(TreeNode<T> *current)
    {
        if (current != null)
        {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }
};

int main()
{
    
    Tree<char> tree('A');
    tree.buildTree();
    cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;

    cout << "Postorder >> ";
    tree.postorder(tree.getRoot());
    cout << endl;
}