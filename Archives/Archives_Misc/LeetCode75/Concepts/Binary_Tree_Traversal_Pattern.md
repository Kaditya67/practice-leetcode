# 🌳 Binary Tree Views and Traversals 

---

## Level Order Traversal (BFS)

### Idea:
Traverse the tree level by level using a queue.

### Algorithm:
- Use a queue.
- Push root and process each level left to right.

### Code:

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}
```

---

## Left View of Binary Tree

### Idea:
Pick the **first node** from each level during BFS.

### Code:

```cpp
vector<int> leftView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) result.push_back(node->val); // First node of level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}
```

---

## Right View of Binary Tree

### Idea:
Pick the **last node** from each level during BFS.

### Code:

```cpp
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) result.push_back(node->val); // Last node of level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}
```

---

## Leaf Nodes of Binary Tree

### Idea:
Use DFS to collect nodes where both left and right are `nullptr`.

### Code:

```cpp
void getLeafNodes(TreeNode* root, vector<int>& leaves) {
    if (!root) return;

    if (!root->left && !root->right) {
        leaves.push_back(root->val);
    }

    getLeafNodes(root->left, leaves);
    getLeafNodes(root->right, leaves);
}

vector<int> leafNodes(TreeNode* root) {
    vector<int> leaves;
    getLeafNodes(root, leaves);
    return leaves;
}
```

---

## Zigzag Level Order Traversal

### Idea:
Alternate between left-to-right and right-to-left every level.

### Tips:
- Use `deque` for efficient front and back insertion.
- Use a boolean flag to toggle direction.

### Code:

```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        deque<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();

            if (leftToRight)
                level.push_back(node->val);
            else
                level.push_front(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(vector<int>(level.begin(), level.end()));
        leftToRight = !leftToRight;
    }

    return result;
}
```

---

## Summary Table

| Feature         | Strategy         | Data Structure | Notes                          |
|-----------------|------------------|----------------|--------------------------------|
| Level Order     | BFS              | Queue          | Left to right level-wise       |
| Left View       | BFS (first node) | Queue          | First node at each level       |
| Right View      | BFS (last node)  | Queue          | Last node at each level        |
| Leaf Nodes      | DFS              | Recursion      | Nodes with no children         |
| Zigzag          | BFS + Deque      | Queue + Deque  | Alternate direction per level  |

---

## Tips

- Level Order → Queue
- Zigzag → Queue + Deque
- Left/Right View → Focus on 1st/last node per level
- Leaf Nodes → Base case in DFS