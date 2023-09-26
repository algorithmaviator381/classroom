#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    // Function to get the height of a node
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Function to calculate the balance factor of a node
    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Function to perform a right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Function to perform a left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Function to insert a key into the AVL tree
    Node* insert(Node* root, int key) {
        if (root == nullptr)
            return new Node(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else // Duplicate keys are not allowed
            return root;

        // Update height of the current node
        root->height = 1 + max(height(root->left), height(root->right));

        // Get the balance factor
        int balance = balanceFactor(root);

        // Perform rotations if needed to maintain AVL property
        if (balance > 1) {
            if (key < root->left->key)
                return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balance < -1) {
            if (key > root->right->key)
                return leftRotate(root);
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    // Function to delete a key from the AVL tree
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp; // Copy the contents of the non-empty child
                delete temp;
            } else {
                // Node with two children, get the inorder successor
                Node* temp = minValueNode(root->right);
                // Copy the inorder successor's key to this node
                root->key = temp->key;
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->key);
            }
        }

        // If the tree had only one node, return
        if (root == nullptr)
            return root;

        // Update height of the current node
        root->height = 1 + max(height(root->left), height(root->right));

        // Get the balance factor
        int balance = balanceFactor(root);

        // Perform rotations if needed to maintain AVL property
        if (balance > 1) {
            if (balanceFactor(root->left) >= 0)
                return rightRotate(root);
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balance < -1) {
            if (balanceFactor(root->right) <= 0)
                return leftRotate(root);
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    // Function to find the node with the minimum key value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // Function to search for a key in the AVL tree
    bool search(Node* root, int key) {
        if (root == nullptr)
            return false;
        if (root->key == key)
            return true;
        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Utility function to print the tree in-order
    void inOrder(Node* root) {
        if (root == nullptr)
            return;
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
};

int main() {
    AVLTree tree;
    Node* root = nullptr;

    // Insert elements into the AVL tree
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "In-order traversal of the AVL tree: ";
    tree.inOrder(root);
    cout << endl;

    int key_to_search = 30;
    if (tree.search(root, key_to_search))
        cout << key_to_search << " found in the AVL tree." << endl;
    else
        cout << key_to_search << " not found in the AVL tree." << endl;

    // Delete an element from the AVL tree
    int key_to_delete = 30;
    root = tree.deleteNode(root, key_to_delete);

    cout << "In-order traversal after deleting " << key_to_delete << ": ";
    tree.inOrder(root);
    cout << endl;

    return 0;
}
