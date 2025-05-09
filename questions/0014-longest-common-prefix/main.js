/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

/**
 * @param {Array<string>} strList
 * @return {string}
 */
function longestCommonPrefix1(strList) {
    strList.sort();
    let result = strList[0];
    for (let i = 0; i < strList.length; i++) {
        let j;
        for (j = 0; j < result.length && j < strList[i].length; j++) {
            if (result[j] !== strList[i][j]) {
                break;
            }
        }
        result = result.substring(0, j);
        if (result === '') {
            return result;
        }
    }
    return result;
}

module.exports = {
    longestCommonPrefix1,
};
