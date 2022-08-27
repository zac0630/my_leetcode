# 二叉树思路篇
二叉树题目的递归解法可以分两类思路，第一类是遍历一遍二叉树得出答案，第二类是通过分解问题计算出答案。
如果需要子树的信息，大概率需要用到后序遍历。

总纲
二叉树解题的思维模式分两类：
1、是否可以通过遍历一遍二叉树得到答案？如果可以，用一个 traverse 函数配合外部变量来实现，这叫「遍历」的思维模式。
2、是否可以定义一个递归函数，通过子问题（子树）的答案推导出原问题的答案？如果可以，写出这个递归函数的定义，并充分利用这个函数的返回值，这叫「分解问题」的思维模式。
递归函数第一步定义功能，第二步设置返回值（有些函数需要设置返回值，有些不用）。
利用定义去做左右子树的事，在做当前节点的事。

无论使用哪种思维模式，你都需要思考：
如果单独抽出一个二叉树节点，它需要做什么事情？需要在什么时候（前/中/后序位置）做？其他的节点不用你操心，递归函数会帮你在所有节点上执行相同的操作。

## 刷题顺序
### 104二叉树的最大深度
1.遍历，记录每一个节点的深度，取最大值
2.分解问题，左子树的深度和右子树的深度
### 144二叉树的前序遍历
遍历，在前序位置输入元素
迭代遍历，使用栈，左节点存在就入栈入队列，不存在就出栈找右节点
Morris 遍历(待研究)
### 543二叉树的直径
1.遍历，计算每个节点的直径，取最大值
2.分解问题，同时在后序位置计算最大直径，后序位置是知道左右子树的最大深度的
后序遍历：
1.一旦发现题目和子树有关，那大概率要给函数设置合理的定义和返回值，在后序位置写代码了
2.遇到子树问题，首先想到的是给函数设置返回值，然后在后序位置做文章

### 226翻转二叉树
1.遍历，每个节点交换左右子树
2.递归分解问题，设计递归函数inverTree(root)，将以root为根的这棵二叉树反转，返回二叉树的根节点

### 116填充节点的右指针
1.遍历，一棵二叉树被抽象成一棵三叉树，三叉树上的每个节点就是原先二叉树的两个相邻节点。traverse(Node node1, Node node2)

### 114二叉树展开为链表
1.递归，定义：将以 root 为根的树拉平为链表void flatten(TreeNode root)

# 二叉树构造篇
二叉树的构造问题一般都是使用「分解问题」的思路：构造整棵树 = 根节点 + 构造左子树 + 构造右子树。

## 刷题顺序
### 654构造最大二叉树
1.递归，遍历数组把找到最大值 maxVal，从而把根节点 root 做出来，然后对 maxVal 左边的数组和右边的数组进行递归构建，作为 root 的左右子树

### 105通过前序和中序遍历结果构造二叉树
1.递归，定义函数build(vector<int> &preorder, int preStart, int preEnd,vector<int> &inorder, int inStart, int inEnd)。
问题关键在于如何找到根节点并在中序遍历和前序遍历中划分好左子树和右子树
前序遍历的第一个元素就是根节点，在中序遍历中找到根节点即完成划分，同时得到左子树的长度，通过计算索引，在前序遍历中得到左子树和右子树的起始和结束

### 106通过后序和中序遍历结果构造二叉树
与105类似，也是控制数组起止位置。

### 889通过前序和后续遍历结果构造二叉树
1.首先把前序遍历的第一个元素或者后序遍历的最后一个元素确定为根节点的值
2.然后把前序遍历结果的第二个值作为左子树的根节点（假设前序遍历的第二个元素是左子树的根节点，但实际上左子树有可能是空指针，那么这个元素就应该是右子树的根节点。）
3.在后序遍历结果中寻找左子树根节点的值，从而确定左子树的索引边界，进而确定右子树的索引边界，递归构造左右子树

# 二叉树序列化篇

## 刷题顺序
### 297二叉树的序列化与反序列化
这里的 node 列表包含了空指针的信息，所以只使用 node 列表就可以还原二叉树。

# 二叉树后续篇
前序位置的代码只能从函数参数中获取父节点传递来的数据，而后序位置的代码不仅可以获取参数数据，还可以获取到子树通过函数返回值传递回来的数据。那么换句话说，一旦你发现题目和子树有关，那大概率要给函数设置合理的定义和返回值，在后序位置写代码了。

## 刷题顺序
# 652寻找重复的子树
1.后序遍历，以我为root的子树是什么样子的（序列化铺平），以其他节点为根的子树都是什么样子的（将子树铺平后存储起来，怎么存）。二叉树的前序/中序/后序遍历结果可以描述二叉树的结构（字符串形式铺平），每个节点都把以自己为根的子树的样子存到一个外部的数据结构里即可

# 二叉树与归并排序
## 刷题顺序
# 912排序数组
1.二叉树的后序遍历和归并排序的相似性。归并排序是一个分解问题，过程可以在逻辑上抽象成一棵二叉树后序遍历的顺序。然后，在每个节点的后序位置（左右子节点已经被排好序）的时候执行 merge 函数，合并两个子节点上的子数组。

# 315计算右侧小于当前元素的个数
1.与归并排序关联。在归并排序的后序遍历位置运行的merge函数，左半边和右半边都是升序，使用双指针进行合并时，可以知道右侧小于左半边元素的个数。当前节点归并结束后，升序，与其兄弟节点继续归并。

# 493翻转对
1.与归并排序关联。在每次进行merge函数之前，左半边和右半边都已经是有序。这时可以去根据题目要求的数学大小关系找到合适的元素。归并排序应用有个特点，都是寻找右边比左边怎么怎么样的元素，也就是左边元素要被右边元素多次比较，这样的特点符合归并排序。

# 327 区间和的个数
1.技巧性较强，很难想到。首先是快速计算区间和的方法，使用前缀数组preSum，区间和等于preSum[j]-preSum[i]。其次，就是思考如何找到区间和在[lower, supper]之间的区间和。可以考虑归并，由于在merge之前，右半边还没有合并，在原始位置中还是在右边，因此用右半边的数据和左半边比较。
我们想一下 BST 的操作为什么这么高效？就拿搜索某一个元素来说，BST 能够在对数时间找到该元素的根本原因还是在 BST 的定义里，左子树小右子树大嘛，所以每个节点都可以通过对比自身的值判断去左子树还是右子树搜索目标值，从而避免了全树遍历，达到对数级复杂度。

# 二叉搜索树
1.对于 BST 的每一个节点 node，左子树节点的值都比 node 的值要小，右子树节点的值都比 node 的值大。
2.对于 BST 的每一个节点 node，它的左侧子树和右侧子树都是 BST。

# 230二叉搜索树中第K小的元素
1.二叉搜索树的中序遍历就是升序的，只要在中序位置记录当前是第几个元素，再与k比较就能得到答案。利用「BST 中序遍历就是升序排序结果」这个性质，每次寻找第k小的元素都要中序遍历一次，最坏的时间复杂度是O(N)，N是BST的节点个数。

# 538和1038把二叉搜索树转换为累加树
1.累加树是加比它大的所有元素。二叉搜索树的中序遍历是升序，修改递归位置，可以得到降序顺序，这样再维护一个累加和，加到当前元素就可以了。

# 二叉搜索树（基础操作篇）
BST的基础操作：判断BST的合法性、增、删、查。其中「删」和「判断合法性」略微复杂。

## 98验证二叉搜索树
1.二叉搜索树的遍历框架
```cpp
void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```
不仅要判断root和其左右节点的大小关系，还要满足root的整个左子树都要小于root.val，整个右子树都要大于root.val。问题是，对于某一个节点root，他只能管得了自己的左右子节点，怎么把root的约束传递给左右子树呢？通过使用辅助函数，增加函数参数列表，在参数中携带额外信息，将这种约束传递给子树的所有节点。

## 700二叉搜索树中的搜索
1.利用左小右大，排除一边

## 701二叉搜索树中的插入操作
1.在遍历二叉搜索树的基础上，加上修改的操作，函数需要返回TreeNode类型，并且要对递归调用的返回值进行接收。
```cpp
TreeNode insertIntoBST(TreeNode root, int val) {
    // 找到空位置插入新节点
    if (root == null) return new TreeNode(val);
    // if (root.val == val)
    //     BST 中一般不会插入已存在元素
    if (root.val < val) 
        root.right = insertIntoBST(root.right, val);
    if (root.val > val) 
        root.left = insertIntoBST(root.left, val);
    return root;
}

```

## 450删除二叉搜索树中的节点
1.先遍历寻找，再修改接收。
```cpp
TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;
    if (root.val == key) {
        // 找到啦，进行删除
    } else if (root.val > key) {
        // 去左子树找
        root.left = deleteNode(root.left, key);
    } else if (root.val < key) {
        // 去右子树找
        root.right = deleteNode(root.right, key);
    }
    return root;
}
分三种情况讨论。
```

# 二叉搜索树（构造篇）
如何计算所有有效 BST

## 96不同的二叉搜索树
1.当以root为根时，左边可能的二叉搜索树乘以右边可能的二叉搜索树。添加备忘录，降低时间复杂度。

## 95不同的二叉搜索树 II
1.穷举root节点的所有可能，递归构造出左右子树的所有合法BST，给root节点穷举所有左右子树的组合。

## 215数组中的第K个最大元素
快排框架
```cpp
    void sort(vector<int>& nums, int lo, int hi){
        if(lo > hi) return;
        int pos = partition(nums, lo, hi);
        sort(nums, lo, pos-1);
        sort(nums, pos+1, hi);
        return;
    }
    int partition(vector<int>&nums, int lo, int hi){
        int val = nums[lo];
        //边界维护
        //[lo,i) <= pos (j, hi] > pos
        //当i > j结束循环时，保证区间[lo, hi]都被覆盖
        int i = lo + 1;
        int j = hi;
        while(i <= j){
            while(i < hi && nums[i] <= val) i++;
            while(j > lo && nums[j] > val) j--;
            if(i >= j)  break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }
```
partition函数会将nums[p]排到正确的位置，每次选择左半边或者右半边继续寻找

## 341扁平化嵌套列表迭代器
在递归方法中，我们在遍历时如果遇到一个嵌套的 子list，就立即处理该 子list，直到全部展开；
在迭代方法中，我们不需要全部展开，只需要把 当前list 的所有元素放入 list 中。

由于「栈」的先进后出的特性，我们需要逆序在栈里放入各个元素。

处理流程分为两步：
1. 在构造函数中应该初始化，把当前列表的各个元素（不用摊平）逆序放入栈中。
2. 在 hasNext() 方法中，访问（不弹出）栈顶元素，判断是否为 int：
如果是 int 那么说明有下一个元素，返回 true；然后 next() 就会被调用，把栈顶的 int 弹出；
如果是 list 需要把当前列表的各个元素（不用摊平）逆序放入栈中。
如果栈为空，那么说明原始的嵌套列表已经访问结束了，返回 false。

# GIT原理之最近公共祖先

## 236二叉树的最近公共祖先
分情况。情况1：p和q分别在一个root的左右子树中。情况二：p和q在一条分支上。
算法框架，寻找val1或val2的节点
```cpp
TreeNode* find(TreeNode* root, int val1, int val2){
    if(root == NULL)    return NULL;
    if(root->val == val1 || root->val == val2)  return root;
    TreeNode* left = find(root->left, val1, val2);
    TreeNode* right = find(root->right, val1, val2);
    return left != NULL ? left : right;
}
```

## 1676和1644二叉树的最近公共祖先（会员专享）
1676 若干列表，与236思路一致，使用hash_set来判断元素是否存在
1644 p和q不一定存在于树中，使用额外变量foundP和foundQ在后序位置记录p和q是否出现过。

## 235二叉搜索树的最近公共祖先
利用BST的特性，公共祖先肯定满足min<=root<=max,也就是去BST中寻找满足条件的root。每次只需要去左子树或者右子树中寻找。

## 如何计算完全二叉树的节点数
完全二叉树，每一层都是紧凑靠左排列的。满二叉树，是一种特殊的完全二叉树，每层都是满的，像一个稳定的三角形。
计算一颗普通的二叉树，遍历所有节点
```cpp
int countNodes(TreeNode root) {
    if (root == null) return 0;
    return 1 + countNodes(root.left) + countNodes(root.right);
}

```
计算一颗满二叉树，节点总数就和树的高度呈指数关系
```cpp
int countNodes(TreeNode root) {
    int h = 0;
    // 计算树的高度
    while (root != null) {
        root = root.left;
        h++;
    }
    // 节点总数就是 2^h - 1
    return (int)Math.pow(2, h) - 1;
}
```
计算一颗完全二叉树，关键：一棵完全二叉树的两棵子树，至少有一棵是满二叉树。


# 二叉树专题
## 94二叉树的中序遍历
递归，在中序位置处理。

## 99恢复二叉搜索树
关键：二叉搜索树的中序遍历是升序。
1. 将二叉搜索数的中序遍历存在一个数组中，遍历这个数组，找到不符合升序的两个位置。
2. 二叉搜索树的遍历时，在中序位置判断大小，同时用一个全局变量pre记录上一次节点。

## 100相同的树
递归，两颗树相同，根节点存在且相同，其他情况不相同，满足这个之后，再去递归左右子树。

## 101对称二叉树
递归，root存在，则开始递归。递归函数有两个参数，左子树和右子树。与100题类似，根节点存在且相同，其他情况不相同，满足这个之后，再去递归左右子树。

## 102二叉树的层序遍历
1. 迭代，while循环遍历从上到下，for循环遍历从左到右，使用queue。
2. 递归，遍历当前层的列表，加入res，同时将各节点孩子节点存入nextLevelNodes，继续递归。分别在前序位置和后续位置添加结果，可以得到自顶向下和自底向上的层序遍历结果。

## 103二叉树的锯齿形层序遍历
迭代，设置一个符号位标记方向，表示的是插入最终结果res的方向

## 107二叉树二叉树的层序遍历II
递归，利用后序位置是倒着输出的特性

## 108将有序数组转换为二叉搜索树
递归，有序数组的中间是根节点，利用[lo,hi]控制递归边界。二叉树的构造问题，构造根节点，然后构建左右子树。构造或删除节点是需要接收递归的结果的。

## 110平衡二叉树
递归，判断当前节点左右子树是否符合差值小于等于1，不符合返回false，符合继续去递归左右子树

## 111二叉树的最小深度
层序遍历，每个节点都往前走一步，当某个节点是叶子节点后，就可以返回最小深度。

## 112路径总和
1. 遍历，借助外部变量来记录是否找到符合的路径，记录遍历过程中的路径和。前序位置加，判断，后序位置减。
2. 分解，定义：输入一个根节点，返回该根节点到叶子节点是否存在一条和为 targetSum 的路径。判断是否到叶子节点，是的话判断是否符合路径，不是的话，将路径和减去当前节点值，再去左右子树递归。

## 113路径总和 II
1. 遍历，维护到当前节点的路径列表，符合目标路径就加入res。

## 117填充每个节点的下一个右侧节点指针 II
1. 层次遍历。利用层次遍历的特点，能够遍历到每一层的节点，在pop的时候设置next指针，如果是当前层的最后一个节点，则指向NULL。

## 112路径总和
1. 分解问题，定义：返回单边路径最长。在后序位置可以得到左右子树的单边最长，利用外部变量记录路径总和最大的值。

## 129求根节点到叶节点数字之和
1. 遍历，维护一个路径列表，前序位置插入root，后序位置删除root。当遍历到叶子节点时，累加路径和。
技巧，在前序位置判断是否是叶子节点。
```cpp
void traverse(TreeNode* root){
    if(root == NULL){
        return;
    }
    //在前序位置判断当前节点是否是叶子节点！！！技巧
    if(root->left == root->right){
        //这里做叶子节点的事
    }
    traverse(root->left);
    traverse(root->right;
}
```

## 145二叉树的后序遍历
1. 分解问题，定义：输入一个节点，返回以该节点为根的二叉树的后序遍历结果。
```cpp
public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<Integer> res = new LinkedList<>();
    if (root == null) {
        return res;
    }
    // 后序遍历结果特点：先是左子树，接着是右子树，最后是根节点的值
    res.addAll(postorderTraversal(root.left));
    res.addAll(postorderTraversal(root.right));
    res.add(root.val);
    return res;
}
```

## 173二叉搜索树迭代器
利用栈，模拟二叉搜索树的递归。

## 199二叉树的右视图
1. 层次遍历，可以改变插入左右节点的顺序，变为从右往左遍历
2. 深度遍历DFS，从右子树开始遍历，然后再是左子树，同时记录当前节点的高度，如果高度小于res.size()，说这时这层的第一个节点。
```cpp
void traverse(TreeNode root) {
    if (root == null) {
        return;
    }
    // 前序遍历位置
    depth++;
    if (res.size() < depth) {
        // 这一层还没有记录值
        // 说明 root 就是右侧视图的第一个节点
        res.add(root.val);
    }
    // 注意，这里反过来，先遍历右子树再遍历左子树
    // 这样首先遍历的一定是右侧节点
    traverse(root.right);
    traverse(root.left);
    // 后序遍历位置
    depth--;
}
```

## 257二叉树的所有路径
1. 遍历，使用外部遍历记录当前路径，提交失败。使用参数path记录当前路径，在root不为空时进行是否是叶子节点的判断。

## 198 213 337打家劫舍问题
1. 198常规的动态规划问题。思路1：自顶向下递归法。优化：设置备忘录。思路二，自底向上，单重循环就能解决。优化：降低空间复杂度，状态转移只和dp[i]的最近的两个状态相关。
2. 213加入房屋连成环的条件。将题目拆分成三种情况。首位房间不能同时被抢，要么都不被抢，要么第一间房被抢，最后一间不被抢。要门最后一间被抢，第一间不被抢。
3. 337与二叉树相结合。