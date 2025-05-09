// 时间：80 ms  内存：36.7 MB
const hasGroupsSizeX1 = function (deck) {
    function gcd(num1, num2) {
        return num2 === 0 ? num1 : gcd(num2, num1 % num2);
    }

    let timeMap = new Map();
    deck.forEach(num => {
        timeMap.set(num, timeMap.has(num) ? timeMap.get(num) + 1 : 1);
    });
    let timeArray = [...timeMap.values()];
    let g = timeArray[0];

    timeArray.forEach(time => {
        g = gcd(g, time);
    });

    return g >= 2;
};
