const preOrder = function(root) {
    const result = [];
    const traversal = node => {
        if (node) {
            result.push(node.val);
            node.children.forEach(child => traversal(child));

        }
    };
    traversal(root);
    return result;
};
