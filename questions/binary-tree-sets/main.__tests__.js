const main = require('./main');
const {BinaryTree} = require('../base/binaryTree');

describe('测试二叉树的集合', () => {
    function initBinaryTree(initArray = []) {
        const binaryTree = new BinaryTree();
        initArray.forEach(value => binaryTree.insert(value));
        return binaryTree;
    }

    const binaryTree = initBinaryTree([50, 40, 80, 20, 90, 95, 45, 60]);

    const {
        preOrderTraversal1,
        preOrderTraversal2,
        inOrderTraversal1,
        postOrderTraversal1,
        leverOrderTraversal1,
        binaryTreeMaxValue,
        binaryTreeMinValue,
        binaryTreeMaxDepth1,
        binaryTreeMaxDepth2,
        binaryTreeMinDepth1,
        binaryTreeMinDepth2,
    } = main;

    test('开始测试先序遍历', () => {
        const fns = [preOrderTraversal1, preOrderTraversal2];
        fns.forEach(fn => {
            expect(fn()).toEqual([]);
            expect(fn(binaryTree.root)).toEqual([50, 40, 20, 45, 80, 60, 90, 95]);
        });
    });

    test('开始测试中序遍历', () => {
        const fns = [inOrderTraversal1];
        fns.forEach(fn => {
            expect(fn()).toEqual([]);
            expect(fn(binaryTree.root)).toEqual([20, 40, 45, 50, 60, 80, 90, 95]);
        });
    });

    test('开始测试后序遍历', () => {
        const fns = [postOrderTraversal1];
        fns.forEach(fn => {
            expect(fn()).toEqual([]);
            expect(fn(binaryTree.root)).toEqual([20, 45, 40, 60, 95, 90, 80, 50]);
        });
    });

    test('开始测试二叉树最大值', () => {
        const fns = [binaryTreeMaxValue];
        fns.forEach(fn => {
            expect(fn()).toEqual(null);
            expect(fn(binaryTree.root)).toEqual(95);
        });
    });

    test('开始测试二叉树最小值', () => {
        const fns = [binaryTreeMinValue];
        fns.forEach(fn => {
            expect(fn()).toEqual(null);
            expect(fn(binaryTree.root)).toEqual(20);
        });
    });

    test('开始测试二叉树最大深度', () => {
        const fns = [binaryTreeMaxDepth1];
        fns.forEach(fn => {
            expect(fn()).toEqual(0);
            expect(fn(binaryTree.root)).toEqual(4);
        });
    });

    test('开始测试二叉树最小深度', () => {
        const fns = [binaryTreeMinDepth1];
        fns.forEach(fn => {
            expect(fn()).toEqual(0);
            expect(fn(binaryTree.root)).toEqual(3);
        });
    });

});
