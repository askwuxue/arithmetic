# 数据结构和算法

## 如何高效，有效的算法

《异类 不一样的启示录》
1. 切碎知识点
2. 刻意练习 不爽
3. 反馈 主动反馈（自己去进行的） 被动反馈（被别人反馈）


_每学完一个知识点就去LeetCode刷对应的题目_

**最好的方式是什么？**
**时间复杂度是多少？空间复杂度是多少**
**寻求大佬的反馈**

## 数据结构
### 栈
1. 访问：时间复杂度O(1)
2. 删除，插入，最差时间复杂度为O(n)

#### `leetCode`

#####  [20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

难度简单2352

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

 

**示例 1：**

```
输入：s = "()"
输出：true
```

**示例 2：**

```
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```
输入：s = "(]"
输出：false
```

**示例 4：**

```
输入：s = "([)]"
输出：false
```

**示例 5：**

```
输入：s = "{[]}"
输出：true
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成



**思路**

​	利用栈的先进先出的特性，先考虑边界条件，栈内元素为奇数个，直接退出。遇到左括号，入栈。遇到右括号，出栈。出栈的元素和右括号进行匹配。匹配失败则退出。



**code**

```ts
/**
 * @param {string} s
 * @return {boolean}
 */
//  TODO 运行时间过长
var isValid = function(s) {
    let arr = [];
    let len = s.length;
    if (len % 2) {
        return false;
    }
        for (let i = 0; i < len; i++) {
            if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
                arr.push(s[i]);
            }            
            else {
                switch(arr.pop()) {
                    case '(': {
                        if(s[i] !== ')') {
                            return false;
                        }
                        break;
                    }
                    case '[': {
                        if(s[i] !== ']') {
                            return false;
                        }
                        break;
                    }
                    case '{': {
                        if(s[i] !== '}') {
                            return false;
                        }
                        break;
                    }
                    default: {
                        return false;
                    }
                }
            }
        }
        return arr.length === 0;
};
```

##### [155. 最小栈](https://leetcode-cn.com/problems/min-stack/)

难度简单885

设计一个支持 `push` ，`pop` ，`top` 操作，并能在常数时间内检索到最小元素的栈。

- `push(x)` —— 将元素 x 推入栈中。
- `pop()` —— 删除栈顶的元素。
- `top()` —— 获取栈顶元素。
- `getMin()` —— 检索栈中的最小元素。

 

**示例:**

```
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

 

**提示：**

- `pop`、`top` 和 `getMin` 操作总是在 **非空栈** 上调用。



**思路**

​	首先栈的功能全部要实现，在普通栈的基础上，访问最小元素的时间复杂度是O(n)。所以要其他的方式来访问栈内最小元素。一般来说，用空间换取时间是一种方式。借助最小栈（`minStack`）来实现，最小栈内始终在栈顶放置最小值。使普通栈（`stack`）和最小栈保持同步。最小栈为空，普通栈`push`，也`push`到最小栈。如果普通栈`push`的值小于最小栈的栈顶值，也`push`到最小栈。如果普通栈`push`的值大于最小栈栈顶值，不`push`到最小栈。



**code**

```js
/**
 * initialize your data structure here.
 */
var MinStack = function() {
    this.stack = [];
    this.minStack = [];
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    this.stack.push(val);
    if (this.minStack.length === 0 || val <= this.minStack[this.minStack.length - 1]) {
        this.minStack.push(val);
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    let popNumber = this.stack.pop();
    if (popNumber === this.minStack[this.minStack.length - 1]) {
        this.minStack.pop();
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack[this.stack.length - 1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.minStack[this.minStack.length - 1]
};

```







### 队列

1. 先进先出
2. 有顺序的数据结构
3. 线性队列和环形队列，线性队列空间无法进行复用。出队列只是移动了指针，实际数组的空间还是占有的，导致了数组空间的浪费

#### 线性队列的实现
主要思想是头指针和尾指针默认的位置都是-1, 当两个指针重合，队列空。当尾指针走到了队列的最后一个元素位置，队列满
```java
class Queue {

    private int maxSize;
    private int head;
    private int end;
    private int[] arr;

    // 构造函数初始化队列
    public Queue(int ArrmaxSize) {
        maxSize = ArrmaxSize;
        arr = new int[maxSize];
        head = -1;
        end = -1;
    }

    // 判断链表是否满 尾指针等于指向了数组的最后一个元素 队列已满
    public boolean isFull() {
        return end == arr.length - 1;
    }

    // 判断链表是否为空 当头指针等于尾指针 队列已满
    public boolean isEmpty() {
        return end == head;
    }

    // 出队
    public int popQueue() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        // 头部指针后移
        head++;
        return arr[head];
    }

    // 入队
    public void addQueue(int n) {
        if (isFull()) {
            throw new RuntimeException("queue is full");
        }

        // 尾指针后移
        end++;
        arr[end] = n;
    }

}
```

#### 环形队列的实现
环形队列实现的主要思想是，将默认的头指针(front)和尾指针(rear)都初始为0。rear总是指向最后一个元素的后一个位置(该位置是预留的一个约定空间)。
因此，如果队列的maxSize为5，则最大有效数据个数为4.因此，队列空的条件是：(rear + 1) % maxSize == front; 队列满：rear == front
队列的有效数据个数为: (rear - front + maxSize) % maxSize。
```java
class CircleQueue {
    private int maxSize;
    private int head;
    private int end;
    private int[] arr;

    // 构造函数初始化队列
    public CircleQueue(int ArrmaxSize) {
        maxSize = ArrmaxSize;
        arr = new int[maxSize];

        // 环形队列的默认头指针和尾指针都为0
        head = 0;
        end = 0;
    }

    // 判断链表是否满
    public boolean isFull() {
        // return end == arr.length - 1;
        // 始终留一个空的位置做约定 所以maxSize 为3 时 队列长度为2时， 就认为队列已满
        return (end + 1) % maxSize == head;
    }

    // 判断链表是否为空 当头指针等于尾指针 队列已满
    public boolean isEmpty() {
        return end == head;
    }

    // 出队
    public int popQueue() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }

        // 当前的指针指向的是当前的出队元素 因为指针下一步会变 所以此时先暂存当前的队列头数据
        int value;
        value = arr[head];

        head = (head + 1) % maxSize;
        return value;
    }

    // 入队
    public void addQueue(int n) {
        if (isFull()) {
            throw new RuntimeException("queue is full");
        }

        arr[end] = n;
        end = (end + 1) % maxSize;
    }

    // 显示队列
    public void show() {
        for (int i = head; i < head + size(); i++) {
            System.out.println(arr[i]);
        }
    }

    // 获取队列的有效长度
    public int size() {
        return (end + maxSize - head) % maxSize;
    }


}
```

#### `leetCode`

##### [933. 最近的请求次数](https://leetcode-cn.com/problems/number-of-recent-calls/)

难度简单83

写一个 `RecentCounter` 类来计算特定时间范围内最近的请求。

请你实现 `RecentCounter` 类：

- `RecentCounter()` 初始化计数器，请求数为 0 。
- `int ping(int t)` 在时间 `t` 添加一个新请求，其中 `t` 表示以毫秒为单位的某个时间，并返回过去 `3000` 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 `[t-3000, t]` 内发生的请求数。

**保证** 每次对 `ping` 的调用都使用比之前更大的 `t` 值。

 

**示例：**

```
输入：
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
输出：
[null, 1, 2, 3, 3]

解释：
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3
```

 

**提示：**

- `1 <= t <= 109`
- 保证每次对 `ping` 调用所使用的 `t` 值都 **严格递增**
- 至多调用 `ping` 方法 `104` 次



**思路**

利用队列。先将当前的时间放进队列内，然后从队列头依次判断对应的队列元素是否出队。
出队条件，队列中的元素 < (当前t - 3000)



**code**

```JavaScript
var RecentCounter = function() {
    this.arr = [];
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function(t) {
    this.arr.push(t);
    while (this.arr[0] < t - 3000) {
        this.arr.shift();
    }
    return this.arr.length;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```


### 链表 
1. 改善数组的删除和插入操作
2. 查找：时间复杂为O(n)
3. 删除和插入的时间复杂度O(1)

#### `LeetCode`

##### [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

难度简单182

输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 `6` 个节点，从头节点开始，它们的值依次是 `1、2、3、4、5、6`。这个链表的倒数第 `3` 个节点是值为 `4` 的节点。

 

**示例：**

```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```



**code**

```JavaScript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    // 第一个元素
    var cur = head;
    // 链表长度
    var l = 0;
    while (cur !== null) {
        l++;
        cur = cur.next;
    }

    // k, l合法检验 
    if (k < 1 || k > l || l === 0) {
        return null;
    }

    // lastIndex
    var lastIndex = head;
    for (var i = 0; i < l - k; i++) {
        lastIndex = lastIndex.next;
    }
    return lastIndex;
};
```



##### [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

难度简单139

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

**示例 1：**

```
输入：head = [1,3,2]
输出：[2,3,1]
```

**限制：**

```
0 <= 链表长度 <= 10000
```



**思路**

1. 使用JavaScript数组的unshift(),将链表元素依次数组头部加入。时间复杂度使用O(n)
2. 使用递归，将函数依次入栈，从最后一个元素依次push到数组中



**code**

1. JavaScript数组方法
```ts
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
//  已注释代码是先实现链表反转再加入数组中
var reversePrint = function(head) {
    if (head === null) return [];
    // let pre = null;
    // let temp = null;
    let cur = head;
    let num = [];
    while (cur !== null) {
        // temp = cur.next;
        // cur.next = pre;
        // pre = cur;
        // cur = temp;
        // TODO 使用unshift()的时间复杂度时多少，和push()比呢？
        num.unshift(cur.val);
        cur = cur.next;
    }
    return num;
};
```

2. 递归
```ts
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
// TODO 使用递归实现，时间复杂度是多少
var reversePrint = function(head) {
    if (head === null) return [];
    let num = [];
    const vistor = function (head) {
        if (head !== null) {
            vistor(head.next);
            num.push(head.val);
        }
    }
    vistor(head)
    return num;
};
```



##### [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

难度简单567

存在一个按升序排列的链表，给你这个链表的头节点 `head` ，请你删除所有重复的元素，使每个元素 **只出现一次** 。

返回同样按升序排列的结果链表。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```
输入：head = [1,1,2]
输出：[1,2]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```
输入：head = [1,1,2,3,3]
输出：[1,2,3]
```

 

**提示：**

- 链表中节点数目在范围 `[0, 300]` 内
- `-100 <= Node.val <= 100`
- 题目数据保证链表已经按升序排列



**code**

```ts
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if (head === null || head.next === null) return head;
    let cur = head;
    while (cur.next !== null) {
        if (cur.val === cur.next.val) {
            cur.next = cur.next.next;
            continue;
        }
        cur = cur.next;
    }
    return head;
};
```

### 树

#### `leetCode`

##### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

难度简单862

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。

**思路**

可以使用深度优先(DFS)遍历,树的高度等于`max(root.left, root.right) + 1`，根据这个规律可以使用递归，遍历所有节点之后，可以得到树的最大深度。

时间复杂度为O(n)

**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

let maxDepth = function(root) {
    if (root === null) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1
}
```



##### [110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)

难度简单674

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

> 一个二叉树*每个节点* 的左右两个子树的高度差的绝对值不超过 1 。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

**示例 3：**

```
输入：root = []
输出：true
```

 

**提示：**

- 树中的节点数在范围 `[0, 5000]` 内
- `-104 <= Node.val <= 104`



**思路**：

1. 自顶向下的方式递归，如果左子树平衡，右子树平衡，它们的高度差小于等于1。以当前节点为根节点的树平衡。

2. 自底向上的方式，判断左子树和右子树是否平衡。如果左子树和右子树的高度差的绝对值小于等于1，则认为平衡。

   返回最大子树高度。高度差绝对值大于1，则认为不平衡。返回-1.只要其中一棵子树返回-1。则认为整棵树不平衡。

**code**

1. 

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function(root) {
    if (root === null) return true;
    if (isBalanced(root.left) && isBalanced(root.right) && Math.abs(height(root.left) - height(root.right)) <= 1) {
        return true;
    } else {
        return false;
    }
};

let height = function (root) {
    if (root === null) return 0;
    return Math.max(height(root.left), height(root.right)) + 1;
}
```

2. 

   ```js
   /**
    * Definition for a binary tree node.
    * function TreeNode(val, left, right) {
    *     this.val = (val===undefined ? 0 : val)
    *     this.left = (left===undefined ? null : left)
    *     this.right = (right===undefined ? null : right)
    * }
    */
   /**
    * @param {TreeNode} root
    * @return {boolean}
    */
   var isBalanced = function(root) {
       return getDeep(root) !== -1;
   };
   
   let getDeep = function(root) {
       if (root === null) return 0;
       let left = getDeep(root.left);
       let right = getDeep(root.right);
       if (Math.abs(left -right) > 1 || left === -1 || right === -1) {
           return -1;
       }
       return Math.max(left, right) + 1;
   }
   ```
   
   

##### [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

难度简单692

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

**示例 :**
给定二叉树

```
          1
         / \
        2   3
       / \     
      4   5    
```

返回 **3**, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

**注意：**两结点之间的路径长度是以它们之间边的数目表示。



**思路**

​	经过观察，直径的长度为，以该节点出发，经过的左子树节点和右子树节点的和减去1。首先，递归求左子树的高度和右子树的高度。然后不断的更新直径的长度：maxLen = L + R + 1。最终直径的长度为 maxLen - 1。



**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

// maxLen 不能再全局设定值，因为LeetCode每一次会保留全局的值，所以会导致maxLen可能会是上一轮计算的值。
let maxLen;
let depth = function(root) {
    if (root === null) return 0;
    let left = depth(root.left);
    let right = depth(root.right);
    // 更新最大长度。
    maxLen = Math.max(maxLen, left + right + 1);
    // 更新子树的最大高度
    return Math.max(left, right) + 1;
}

var diameterOfBinaryTree = function(root) {
    maxLen = 1;
    depth(root);
    return maxLen - 1;
};
```



##### [617. 合并二叉树](https://leetcode-cn.com/problems/merge-two-binary-trees/)

难度简单

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则**不为** NULL 的节点将直接作为新二叉树的节点。

**示例 1:**

```
输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
```

**注意:** 合并必须从两个树的根节点开始。



**思路**

​	深度优先，如果其中一个树为null，直接返回另一个树。左子树，右子树进行递归。然后结果合并到当前节点上。



**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
// 通过递归合并，先合并当前节点，然后合并左子树和右子树
var mergeTrees = function(root1, root2) {
    if (root1 === null) return root2;
    if (root2 === null) return root1;
    let newRoot = new TreeNode(root1.val + root2.val);
    newRoot.left = mergeTrees(root1.left, root2.left);
    newRoot.right = mergeTrees(root1.right, root2.right);
    return newRoot;
};
```



##### [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

难度简单

**示例：**

输入：

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

输出：

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

**备注:**
这个问题是受到 [Max Howell ](https://twitter.com/mxcl)的 [原问题](https://twitter.com/mxcl/status/608682016205344768) 启发的 ：

> 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。



**思路**

递归，交换左右子树或者左右节点。



**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (root === null) return null;
    let L = invertTree(root.left);
    let R = invertTree(root.right);
    root.left = R;
    root.right = L;
    // return root;
    return root;
};
```



##### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

难度简单

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` ，判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：false
```

**示例 3：**

```
输入：root = [1,2], targetSum = 0
输出：false
```

 

**提示：**

- 树中节点的数目在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`



**思路**

	1. 广度优先，使用两个队列，将节点以及节点值分别放入两个队列。出队时，记录当前出队的值，以及左右节点。将出队的左右节点，以及左右节点和出队节点的值相加后放入队列。可以保证当前的入队的节点的值是确定的。不断的出队入队至队列为空。
	2. 递归实现。从根节点到叶子节点的和为sum,那么当前节点到叶子节点的和为`sum-val`。如果当前节点是叶子节点。那么`val === sum`。



**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    if (root === null) return false;
    let queNode = [root];
    let queVal = [root.val];
    let sum = 0;

    while(queNode.length !== 0) {
        let temp = queNode.shift();
        let curVal = queVal.shift();
        if (temp.left === null && temp.right === null) {
            if (curVal === targetSum) {
                return true;
            }
            // 到这里其实还没有遍历结束.队列不一定为空
            continue;
            // return false;
        }
        if (temp.left !== null) {
            queNode.push(temp.left);
            queVal.push(curVal + temp.left.val);
        }
        if (temp.right !== null) {
            queNode.push(temp.right);
            queVal.push(curVal + temp.right.val);
        }
    }
    return false;
};
```



**code**

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    if (root === null) return false;
    if (root.left === null && root.right === null) {
        return root.val === targetSum;
    }

    return hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
};
```







**code**

1. 

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if (root === null) return null;
    let left = mirrorTree(root.left);
    let right = mirrorTree(root.right);
    let tmp = left;
    root.left = right;
    root.right = tmp;
    return root;
};
```

2. 

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    if (root === null) return null;
    let stack = [root];
    while (stack.length) {
        let node = stack.pop();
        if (node.left !== null) {
            stack.push(node.left);
        }
        if (node.right !== null) {
            stack.push(node.right);
        } 
        let temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
    return root;
};
```













## 第一周刷题

#### [485. 最大连续 1 的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)

难度简单

给定一个二进制数组， 计算其中最大连续 1 的个数。

 

**示例：**

```
输入：[1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
```

 

**提示：**

- 输入的数组只包含 `0` 和 `1` 。
- 输入数组的长度是正整数，且不超过 10,000。

通过次数106,321

提交次数176,785



##### 思路

​	题目比较简单，遍历一次数组，遇到1，计数一次。遇到零计数归零。更新1个数的最大值。

##### code

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let len = nums.length;
    let max = 0;
    let k = 0;
    for (let i = 0; i < len; i++) {
        if (nums[i] === 1) {
            k++;
            max = Math.max(max, k);
            continue;
        }
        k = 0;
    }
    return max;
};
```



#### [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

难度简单1060收藏分享切换为英文接收动态反馈

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**示例:**

```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**说明**:

1. 必须在原数组上操作，不能拷贝额外的数组。
2. 尽量减少操作次数。

通过次数369,449

提交次数579,501



##### 思路

​	利用双指针，左指针指向已经排好序的末尾，右指针指向待排的头部。当右指针对应的数不为0，则交换左右指针指针对应的数。左指针的左边全部是非0数，左指针的右边到右指针的左边区间内全部是0。时间复杂度为O（n）。空间复杂度为O（1）



##### code

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let left = 0;
    let right = 0;
    let len = nums.length;
    while (right < len) {
        if (nums[right]) {
            let temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
        }
        right++;
    }
};
```



#### [645. 错误的集合](https://leetcode-cn.com/problems/set-mismatch/)

难度简单

集合 `s` 包含从 `1` 到 `n` 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 **丢失了一个数字** 并且 **有一个数字重复** 。

给定一个数组 `nums` 代表了集合 `S` 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

 

**示例 1：**

```
输入：nums = [1,2,2,4]
输出：[2,3]
```

**示例 2：**

```
输入：nums = [1,1]
输出：[1,2]
```

 

**提示：**

- `2 <= nums.length <= 104`
- `1 <= nums[i] <= 104`

##### 思路

	1. 排序后，遍历。找重复的数和缺失的数。需要注意的是边界条件。当缺失的数是1，或者是n的时候。需要特别注意。时间复杂度`O（nlog(n)）`
	2. 使用Map。遍历，找出重复的和缺失的。时间复杂度O（n）。空间复杂度为O（n）

##### code

1. 

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    nums.sort((v1 ,v2) => v1 - v2);
    let len = nums.length;
    let rep = 0;
    let miss = 1;
    for (let i = 0; i < len; i++) {
        if (nums[i] === nums[i + 1]) {
           rep = nums[i];
        }
        if (nums[i + 1] - nums[i] > 1) {
            miss = nums[i] + 1;
        }
    }
    let res = [rep, len !== nums[len - 1] ? len : miss];
    return res;
};
```

2. 

```js
   /**
    * @param {number[]} nums
    * @return {number[]}
    */
   var findErrorNums = function(nums) {
       let len = nums.length;
       let map = new Map();
       let rep;
       let miss;
       for (let i = 0; i < len; i++) {
           if (map.has(nums[i])) {
               map.set(nums[i], 2);
               rep = nums[i];
           } else {
               map.set(nums[i], 1);
           }
       }
       for (let i = 1; i <= len; i++) {
           if (!map.has(i)) {
               miss = i;
               break;
           }
       }
       let res = [rep, miss];
       return res;
   };
```

   

#### [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

难度中等2458收藏分享切换为英文接收动态反馈

给你 `n` 个非负整数 `a1，a2，...，a``n`，每个数代表坐标中的一个点 `(i, ai)` 。在坐标内画 `n` 条垂直线，垂直线 `i` 的两个端点分别为 `(i, ai)` 和 `(i, 0)` 。找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

**说明：**你不能倾斜容器。

 

**示例 1：**

![img](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

```
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

**示例 2：**

```
输入：height = [1,1]
输出：1
```

**示例 3：**

```
输入：height = [4,3,2,1,4]
输出：16
```

**示例 4：**

```
输入：height = [1,2,1]
输出：2
```

 

**提示：**

- `n = height.length`
- `2 <= n <= 3 * 104`
- `0 <= height[i] <= 3 * 104`



##### code

1. ​	

   ```js
   /**
    * @param {number[]} height
    * @return {number}
    */
   var maxArea = function(height) {
       let left = 0;
       let right = height.length - 1;
       let maxArea = (right - left) * Math.min(height[right], height[left]);
       while (left < right) {
           if (height[left] < height[right]) {
               left++;
           } else {
               right--;
           }
           let temp = (right - left) * Math.min(height[right], height[left]);
           maxArea = Math.max(maxArea, temp);
       }
       return maxArea;
   };
   ```



#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

难度中等

给你一个包含 `n` 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？请你找出所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

 

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

**示例 2：**

```
输入：nums = []
输出：[]
```

**示例 3：**

```
输入：nums = [0]
输出：[]
```

 

**提示：**

- `0 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`



##### code

1.  先排序，固定一个数，剩下的两个数按照两数之和的解法求解。

   ```js
   /**
    * @param {number[]} nums
    * @return {number[][]}
    * [-4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4]
    * [-1,0,1,2,-1,-4]
    * [-4, -1, -1, 0, 1, 2]
    * [[-1,-1,2],[-1,0,1]]
    * 
    */
   var threeSum = function(nums) {
       let len = nums.length;
       if (nums === null || len < 3) return [];
       nums.sort((v1, v2) => v1 -v2);
       let res = [];
       for (let i = 0; i < len; i++) {
           if (i > 0 && nums[i - 1] === nums[i]) {
               continue;
           }
           let last = len -  1;
           let target = -nums[i];
           for (let first = i + 1; first < len - 1; first++) {
               if (first > i + 1 && nums[first - 1] === nums[first]) {
                   continue;
               }
               while (first < last && nums[first] + nums[last] > target) {
                   last--;
               }
               if (last === first) {
                   break;
               }
               if (nums[first] + nums[last] === target) {
                   let arr = [-target, nums[first], nums[last]];
                   res.push(arr);
               }
           }
       }
       return res;
   };
   ```



#### [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)

难度简单1645收藏分享切换为英文接收动态反馈

假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**注意：**给定 *n* 是一个正整数。

**示例 1：**

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

**示例 2：**

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```



##### code

1. ​	

   ```js
   /**
    * @param {number} n
    * @return {number}
    */
   var climbStairs = function(n) {
       let [p, q, r] = [0, 0, 1];
       for (let i = 1; i <= n; i++) {
           p = q;
           q = r;
           r = p + q;
       }
       return r;
   };
   ```



#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

难度简单1704

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**

```
输入：head = []
输出：[]
```

 

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

 

**进阶：**链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？



##### code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if (head === null || head.next === null) return head;
    let pre = null;
    let curr = head;
    while(curr !== null) {
        let temp = curr.next;
        curr.next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
};
```



#### [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

难度中等916收藏分享切换为英文接收动态反馈

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

```
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

**示例 2：**

```
输入：head = []
输出：[]
```

**示例 3：**

```
输入：head = [1]
输出：[1]
```

 

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`

 

**进阶：**你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）



##### code

1. 迭代

   ```js
   /**
    * Definition for singly-linked list.
    * function ListNode(val, next) {
    *     this.val = (val===undefined ? 0 : val)
    *     this.next = (next===undefined ? null : next)
    * }
    */
   /**
    * @param {ListNode} head
    * @return {ListNode}
    */
   var swapPairs = function(head) {
       let dummyHead = new ListNode(0);
       dummyHead.next = head;
       let temp = dummyHead;
       while (temp.next !== null && temp.next.next) {
           let node1 = temp.next;
           let node2 = temp.next.next;
           temp.next = node2;
           node1.next = node2.next;
           node2.next = node1;
           temp = node1;
       }
       return dummyHead.next;
   };
   ```

2. 递归

   ```js
   /**
    * Definition for singly-linked list.
    * function ListNode(val, next) {
    *     this.val = (val===undefined ? 0 : val)
    *     this.next = (next===undefined ? null : next)
    * }
    */
   /**
    * @param {ListNode} head
    * @return {ListNode}
    */
   var swapPairs = function(head) {
       if (head === null || head.next === null) return head;
       let newHead = head.next;
       head.next = swapPairs(newHead.next);
       newHead.next = head;
       return newHead;
   };
   ```

   

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

难度简单1064收藏分享切换为英文接收动态反馈

给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 `true` 。 否则，返回 `false` 。

 

**进阶：**

你能用 *O(1)*（即，常量）内存解决此问题吗？

 

**示例 1：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)

```
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)

```
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```

 

**提示：**

- 链表中节点的数目范围是 `[0, 104]`
- `-105 <= Node.val <= 105`
- `pos` 为 `-1` 或者链表中的一个 **有效索引** 。



##### code

1. Set

   ```js
   /**
    * Definition for singly-linked list.
    * function ListNode(val) {
    *     this.val = val;
    *     this.next = null;
    * }
    */
   
   /**
    * @param {ListNode} head
    * @return {boolean}
    */
   var hasCycle = function(head) {
       let set = new Set();
       while (head !== null) {
           if (set.has(head)) {
               return true;
           }
           set.add(head);
           head = head.next;
       }
       return false;
   };
   ```

2. 快慢指针法

   





141

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    // if (head === null && head.next === null) return false;
    // let temp = head;
    let set = new Set();
    while(head !== null) {
        if (set.has(head)) {
            return true;
        }
        set.add(head);
        head = head.next;
    }
    return false;
};
```





21

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
};
```



2.

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let prevHead = new ListNode(-1);
    let prev = prevHead;
    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        prev = prev.next;
    }

    prev.next = l1 === null ? l2 : l1;

    return prevHead.next;
};
```



88

```js
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    nums1.splice(m, nums1.length, ...nums2);
    nums1.sort((v1, v2) => v1 - v2);
};
```

2.



```js
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let p1 = 0; 
    let p2 = 0;
    let newArr = new Array(m + n).fill(0);
    let cur;
    while (p1 < m || p2 < n) {
        if (p1 === m) {
            cur = nums2[p2++];
        } else if (p2 === n) {
            cur = nums1[p1++];
        } else if (nums1[p1] < nums2[p2]) {
            cur = nums1[p1++];
        } else {
            cur = nums2[p2++];
        }
        newArr[p1 + p2 - 1] = cur;
    }
    let len = newArr.length;
    for (let i = 0; i < len; i++) {
        nums1[i] = newArr[i];
    }
};
```





189

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    let len = nums.length;
    let newArr = new Array(len).fill(0);
    for (let i = 0; i < len; i++) {
        newArr[(k + i) % len] = nums[i];
    }

    for (let i = 0 ; i < len; i++) {
        nums[i] = newArr[i];
    }
   
};
```



26

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    // let len = nums.length;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === nums[i + 1]) {
            nums.splice(i, 1);
            i--;
        }
    }
    return nums.length;
};
```



2.

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let len = nums.length;
    if (len === 0) return 0;
    let fast = 1;
    let slow = 1;

    while (fast < len) {
        if (nums[fast] !== nums[fast - 1]) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
};
```

