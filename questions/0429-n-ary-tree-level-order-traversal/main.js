const levelOrder = (root) => {
    const result = [];
    const __levelOrder = (result, node, k) => {
        if (node === null) {
            return;
        }
        if (result[k] === undefined) {
            result[k] = [];
        }
        result[k].push(node.val);
        if (node.children) {
            for (let i = 0; i < node.children.length; i++) {
                __levelOrder(result, node.children[i], k + 1);
            }
        }
    };

    __levelOrder(result, root, 0);
    return result;
};
