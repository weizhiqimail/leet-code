const main = require('./main');

describe('测试罗马数字转整数', () => {
    test('开始测试', () => {
        const { romanToInteger1 } = main;
        const fns = [romanToInteger1];
        fns.forEach(fn => {
            expect(fn('III')).toEqual(3);
            expect(fn('IV')).toEqual(4);
            expect(fn('IX')).toEqual(9);
            expect(fn('LVIII')).toEqual(58);
            expect(fn('MCMXCIV')).toEqual(1994);
        });
    });
});
