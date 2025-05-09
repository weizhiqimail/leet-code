/*
* 二叉树遍历集合
**/

/**
 * 前序遍历二叉树·根左右 递归遍历
 * {@link https://leetcode-cn.com/problems/binary-tree-preorder-traversal}
 * @param {object} root
 * @return {Array<number>}
 **/
function preOrderTraversal1(root) {
    if (!root) {
        return [];
    }
    const res = [];
    __preOrderTraversal(root, res);
    return res;

    function __preOrderTraversal(node, result) {
        if (node) {
            result.push(node.val);
            __preOrderTraversal(node.left, result);
            __preOrderTraversal(node.right, result);
        }
    }
}


/**
 * 前序遍历二叉树·根左右 迭代遍历，使用栈模拟递归
 * {@link https://leetcode-cn.com/problems/binary-tree-preorder-traversal}
 * @param {object} root
 * @return {Array<number>}
 **/
function preOrderTraversal2(root) {
    const result = [];
    const stack = [];

    if (root) {
        stack.push(root);
    }

    while (stack.length) {
        const node = stack.pop();
        result.push(node.val);
        if (node.right) {
            stack.push(node.right);
        }
        if (node.left) {
            stack.push(node.left);
        }
    }
    return result;
}


/**
 * 中序遍历二叉树·左根右 递归遍历
 * {@link https://leetcode-cn.com/problems/binary-tree-inorder-traversal}
 * @param {object} root
 * @return {Array<number>}
 **/
function inOrderTraversal1(root) {
    if (!root) {
        return [];
    }
    const res = [];
    __inOrderTraversal(root, res);
    return res;

    function __inOrderTraversal(node, result) {
        if (node) {
            __inOrderTraversal(node.left, result);
            result.push(node.val);
            __inOrderTraversal(node.right, result);
        }
    }
}


/**
 * 后序遍历二叉树·左右根 递归遍历
 * {@link https://leetcode-cn.com/problems/binary-tree-postorder-traversal}
 * @param {object} root
 * @return {Array<number>}
 **/
function postOrderTraversal1(root) {
    if (!root) {
        return [];
    }
    const res = [];
    __postOrderTraversal(root, res);
    return res;

    function __postOrderTraversal(node, result) {
        if (node) {
            __postOrderTraversal(node.left, result);
            __postOrderTraversal(node.right, result);
            result.push(node.val);
        }
    }
}


/**
 * 层序遍历二叉树 广度优先遍历 {@link https://leetcode-cn.com/problems/binary-tree-level-order-traversal/}
 * @param {object} root
 * @return {Array<Array<number>>}
 **/
function leverOrderTraversal1(root) {
}


/**
 * 二叉树最大值
 * @param {object} root
 **/
function binaryTreeMaxValue(root) {
    if (!root) {
        return null;
    }
    while (root.right) {
        root = root.right;
    }
    return root.val;
}


/**
 * 二叉树最小值
 * @param {object} root
 **/
function binaryTreeMinValue(root) {
    if (!root) {
        return null;
    }
    while (root.left) {
        root = root.left;
    }
    return root.val;
}


/**
 * 二叉树最大深度 深度优先 {@link https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/}
 * @param {object} root
 * @return {number}
 **/
function binaryTreeMaxDepth1(root) {
    if (!root) {
        return 0;
    }
    let leftHeight = binaryTreeMaxDepth1(root.left);
    let rightHeight = binaryTreeMaxDepth1(root.right);
    return Math.max(leftHeight, rightHeight) + 1;
}


/**
 * 二叉树最大深度 广度优先，在层序遍历时记录深度 {@link https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/}
 * @param {object} root
 * @return {number}
 **/
function binaryTreeMaxDepth2(root) {
    if (!root) {
        return 0;
    }
}


/**
 * 二叉树最小深度 深度优先 {@link https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/}
 * @param {object} root
 * @return {number}
 **/
function binaryTreeMinDepth1(root) {
    if (!root) {
        return 0;
    }
    if (root.left === null && root.right === null) {
        return 1;
    }

    let minDepth = Number.MAX_SAFE_INTEGER;
    if (root.left) {
        minDepth = Math.min(binaryTreeMinDepth1(root.left), minDepth);
    }
    if (root.right) {
        minDepth = Math.min(binaryTreeMinDepth1(root.right), minDepth);
    }
    return minDepth + 1;
}


/**
 * 二叉树最小深度 广度优先 {@link https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/}
 * @param {object} root
 * @return {number}
 **/
function binaryTreeMinDepth2(root) {
    if (!root) {
        return 0;
    }
}



// 反转二叉树
/**
 * @param {object} root
 **/
function binaryTreeInvert(root) {

}


// 二叉树的右视图
/**
 * @param {object} root
 **/
function binaryTreeRightSideView(root) {

}


// 二叉树的坡度
/**
 * @param {object} root
 **/
function binaryTreeTilt(root) {

}


module.exports = {
    // 先序遍历
    preOrderTraversal1,
    preOrderTraversal2,
    // 中序遍历
    inOrderTraversal1,
    // 后序遍历
    postOrderTraversal1,
    // 层序遍历
    leverOrderTraversal1,
    // 二叉树最大值
    binaryTreeMaxValue,
    // 二叉树最小值
    binaryTreeMinValue,
    // 二叉树的最大深度
    binaryTreeMaxDepth1,
    binaryTreeMaxDepth2,
    // 二叉树的最小深度
    binaryTreeMinDepth1,
    binaryTreeMinDepth2,
};
