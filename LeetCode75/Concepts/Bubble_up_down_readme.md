# Bubble Up vs Bubble Down in Binary Trees

Understanding how recursion propagates data through a binary tree is crucial when solving many tree problems. Two common patterns in tree recursion are **Bubble Down** and **Bubble Up**. 

---

## 🌊 Bubble Down

"Bubble Down" refers to passing information **from the root node down to the leaf nodes** using function arguments.

#### Use Cases

* Propagating state (e.g., depth, max value, path sum)
* Accumulating values or constraints as you traverse

### Passing Max Value From Root to Leaves

```cpp
void dfs(TreeNode* node, int maxSoFar) {
    if (!node) return;

    maxSoFar = max(maxSoFar, node->val);  // Bubble down the max
    if (!node->left && !node->right) {
        cout << "Leaf: " << node->val << ", Max on path: " << maxSoFar << endl;
    }

    dfs(node->left, maxSoFar);
    dfs(node->right, maxSoFar);
}
```

### Visual Flow

Given a tree:

```
         3
        / \
       5   1
      / \ / \
     6  2 0  8
       / \
      7   4
```

* Path: 3 → 5 → 6 → max = 6
* Path: 3 → 5 → 2 → 7 → max = 7
* Path: 3 → 1 → 8 → max = 8

The value (maxSoFar) is passed downward — this is bubble down.

---

## 🧼 Bubble Up

"Bubble Up" refers to collecting information **from leaf nodes up to the root** using return values.

### Use Cases

* Finding lowest common ancestor (LCA)
* Counting nodes in a subtree
* Calculating height, depth, diameter, etc.

### Finding Lowest Common Ancestor (LCA)

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root; // Found both in left and right
    return left ? left : right;
}
```

### Visual Flow

Searching for LCA(7, 4):

* Both are found under node 2 → it returns up to node 5 → returned to root

```
               [3]
              /   \
          [5]       1
         /   \
        6    [2] ← LCA bubbles up
            / \
         [7]  [4]
```

This is bubble up — both results come from below and are returned upwards.
