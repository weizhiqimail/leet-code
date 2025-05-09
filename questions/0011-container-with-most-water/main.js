/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

// 双重暴力循环，枚举出所有的可能性，把最大的结果返回
/**
 * @param {Array<number>} heightList
 * @return {number}
 */
function mostWaterAreas1(heightList) {
    let max = 0;
    for (let i = 0; i < heightList.length - 1; i++) {
        for (let j = i + 1; j < heightList.length; j++) {
            let area = (j - i) * Math.min(heightList[i], heightList[j]);
            max = Math.max(max, area);
        }
    }
    return max;
}

// 左右边界，同时向中间收敛
/**
 * @param {Array<number>} heightList
 * @return {number}
 */
function mostWaterAreas2(heightList) {
    let max = 0;
    for (let i = 0, j = heightList.length - 1; i < j;) {
        let minHeight = heightList[i] < heightList[j] ? heightList[i++] : heightList[j--];
        let area = (j - i + 1) * minHeight;
        max = Math.max(max, area);
    }
    return max;
}

module.exports = {
    mostWaterAreas1,
    mostWaterAreas2,
};
