const main = require('./main');

describe('测试两数之和', () => {
    test('开始测试', () => {
        const {twoSum1, twoSum2} = main;
        const fns = [twoSum1, twoSum2];
        fns.forEach(fn => {
            expect(fn([0, 1, 2, 3, 6], 5)).toEqual([2, 3]);
            expect(fn([0, 1, 2, 3, 6], 10)).toEqual([]);
            expect(fn([], 10)).toEqual([]);
        });
    });
});
