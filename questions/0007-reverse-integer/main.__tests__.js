const main = require('./main');

describe('测试整数反转', () => {
    test('开始测试', () => {
        const {reverseInteger1, reverseInteger2} = main;
        const fns = [reverseInteger1, reverseInteger2];
        fns.forEach(fn => {
            expect(fn(0)).toEqual(0);
            expect(fn(123)).toEqual(321);
            expect(fn(120)).toEqual(21);
            expect(fn(-(2 ** 31) - 1)).toEqual(0);
            expect(fn(2 ** 31 + 1)).toEqual(0);
        });
    });
});
