const canPlaceFlowers = (flowers, n) => {

    /*
  * 1. 遍历  flowers
  * 2. 从一个元素开始，先判断第一个元素是否已经种花，如果没有，查看次一个元素是否种花，如果没有，那么说明第一个元素可以种花
  * 3. 如果第一个元素种花，那么直接使用拿次一个元素与下一个元素判断，把自己种了的花做次数记录
  *
  * [1, 0, 0, 0, 0, 0, 1]
  * index = 0; false
  * index = 1;
  * */

    let number = 0;
    flowers.forEach((flower, index) => {
        if (index === 0 && flowers[index] === 0 && flowers[index + 1] === 0) {
            console.log('---- number1', index);
            number++;
            flowers[index] = 1;
        } else if (flowers[index - 1] === 0) {
            if (index === flowers.length) {
                console.log('---- number2', index);
                number++;
                flowers[index] = 1;
            } else if (flowers[index + 1] === 0 && flowers[index] === 0) {
                console.log('---- number3', index);
                number++;
                flowers[index] = 1;
            }
        }
    });
    console.log(flowers, number, n);
    return number === n;
};


// console.log(canPlaceFlowers([1, 0, 0, 0, 0, 0, 1], 2));
// console.log(canPlaceFlowers([0, 0, 1, 0, 1], 1));
console.log(canPlaceFlowers([0, 0, 1, 0, 1, 0, 0], 2));
