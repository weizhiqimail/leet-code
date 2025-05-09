const main = require('./main');

describe('测试回文数字', () => {
    test('开始测试', () => {
        const { palindromeNumber1, palindromeNumber2, palindromeNumber3 } = main;
        const fns = [palindromeNumber1, palindromeNumber2, palindromeNumber3];
        fns.forEach(fn => {
            expect(fn(-1)).toEqual(false);
            expect(fn(0)).toEqual(true);
            expect(fn(12)).toEqual(false);
            expect(fn(121)).toEqual(true);
            expect(fn(1111)).toEqual(true);
            expect(fn(11111)).toEqual(true);
        });
    });
});
