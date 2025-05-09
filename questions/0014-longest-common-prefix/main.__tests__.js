const main = require('./main');

describe('测试最长公共前缀', () => {
    test('开始测试', () => {
        const { longestCommonPrefix1 } = main;
        const fns = [longestCommonPrefix1];
        fns.forEach(fn => {
            expect(fn(['flower','flow','flight'])).toEqual('fl');
            expect(fn(['dog','racecar','car'])).toEqual('');
        });
    });
});
