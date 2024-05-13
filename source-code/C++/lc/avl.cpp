#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left, *right;
    int height;
};

int getheight(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

struct node *createnode(int key)
{
    struct node *temp = new struct node;
    temp->value = key;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int getBalance(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getheight(node->left) - getheight(node->right);
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->left), getheight(x->right));
    y->height = max(getheight(y->left), getheight(y->right));

    return x;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }
    if (key < root->value)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = insert(root->right, key);
    }

    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    int bf = getBalance(root);
    cout << " Balance Factor of root node after inserting " << key << ": " << bf
         << endl;
    // LL
    if (bf > 1 && key < root->left->value)
    {
        return leftrotate(root);
    }
    // RR
    if (bf < -1 && key > root->right->value)
    {
        return rightrotate(root);
    }
    // LR
    if (bf > 1 && key > root->right->value)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    // RL
    if (bf < -1 && key < root->left->value)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->value == key)
    {
        return root;
    }
    if (key < root->value)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 67);
    root = insert(root, 54);
    root = insert(root, 88);
    root = insert(root, 53);

    // preOrder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;

    // cout << root->left->left->value;
    cout << root->left->value;
    return 0;
}
