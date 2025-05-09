const main = require('./main');

describe('测试盛最多水的容器', () => {
    test('开始测试', () => {
        const { mostWaterAreas1, mostWaterAreas2} = main;
        const fns = [mostWaterAreas1, mostWaterAreas2];
        fns.forEach(fn => {
            expect(fn(-1)).toEqual(false);
        });
    });
});
