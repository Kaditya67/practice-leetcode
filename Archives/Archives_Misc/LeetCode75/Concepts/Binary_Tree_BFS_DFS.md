# 🌳 Binary Tree Traversal - BFS vs DFS

## Depth-First Search (DFS)

### Trick to Remember:
> "Go deep before going wide."

DFS explores **as far as possible** along each branch before **backtracking**.

### DFS Variants:
- **Inorder (LNR)**
- **Preorder (NLR)**
- **Postorder (LRN)**

### DFS Code (Recursive)

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### DFS Code (Iterative using Stack)

```cpp
void dfs(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        cout << node->val << " ";
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}
```

---

## Breadth-First Search (BFS)

### Trick to Remember:
> "Go wide level-by-level using a queue."

### BFS Code (Level Order)

```cpp
void bfs(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

---

## DFS vs BFS Comparison

| Feature        | DFS                              | BFS                             |
|----------------|----------------------------------|----------------------------------|
| Data Structure | Stack (implicit via recursion)   | Queue                           |
| Space (Avg)    | O(h), h = height of tree         | O(n), n = width at bottom level |
| Use Case       | Tree structure, backtracking     | Shortest path, level order info |
| Order          | In/Pre/Post-order                | Level-by-level (Top → Bottom)   |
