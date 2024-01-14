class AVLNode:
    def __init__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None


class AVLTree:
    def __init__(self, key):
        self.root = AVLNode(key)

    def height(self, node):
        return node.height if node else 0

    def balance(self, node):
        return self.height(node.left) - self.height(node.right) if node else 0

    def rotateRight(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        y.height = 1 + max(self.height(y.left), self.height(y.right))
        x.height = 1 + max(self.height(x.left), self.height(x.right))

        return x

    def rotateLeft(self, x):
        y = x.right
        T2 = y.left

        y.left = x
        x.right = T2

        x.height = 1 + max(self.height(x.left), self.height(x.right))
        y.height = 1 + max(self.height(y.left), self.height(y.right))

        return y

    def insert(self, node, key):
        if not node:
            return AVLNode(key)

        if key < node.key:
            node.left = self.insert(node.left, key)
        elif key > node.key:
            node.right = self.insert(node.right, key)
        else:
            return node  # Duplicate keys are not allowed

        node.height = 1 + max(self.height(node.left), self.height(node.right))

        balanceFactor = self.balance(node)

        # Left Heavy
        if balanceFactor > 1:
            if key < node.left.key:
                return self.rotateRight(node)
            else:
                node.left = self.rotateLeft(node.left)
                return self.rotateRight(node)

        # Right Heavy
        if balanceFactor < -1:
            if key > node.right.key:
                return self.rotateLeft(node)
            else:
                node.right = self.rotateRight(node.right)
                return self.rotateLeft(node)

        return node

    def insertKey(self, key):
        self.root = self.insert(self.root, key)

    def search(self, node, key):
        if not node or node.key == key:
            return node

        if key < node.key:
            return self.search(node.left, key)
        else:
            return self.search(node.right, key)

    def displayRoot(self):
        if self.root:
            print(self.root.key)
        else:
            print("Tree is empty")

    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.key, end=" ")
            self.inorder(node.right)

    def preorder(self, node):
        if node:
            print(node.key, end=" ")
            self.preorder(node.left)
            self.preorder(node.right)

    def postorder(self, node):
        if node:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.key, end=" ")

    def inorderTraversal(self):
        self.inorder(self.root)
        print()

    def preorderTraversal(self):
        self.preorder(self.root)
        print()

    def postorderTraversal(self):
        self.postorder(self.root)
        print()

    def getRoot(self):
        return self.root


avlTree = AVLTree(67)
avlTree.insertKey(54)
avlTree.insertKey(88)
avlTree.insertKey(1)
avlTree.insertKey(53)

print("Preorder traversal list   : ", end="")
avlTree.preorderTraversal()
print("Postorder traversal list  : ", end="")
avlTree.postorderTraversal()
print("Inorder traversal list    : ", end="")
avlTree.inorderTraversal()

print("Root node:", avlTree.getRoot().key)
print("Balance factor of root:", avlTree.balance(avlTree.getRoot()))
