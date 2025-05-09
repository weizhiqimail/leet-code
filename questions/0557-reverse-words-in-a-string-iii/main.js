// 时间: 84 ms	内存: 39.7 MB
const reverseWords1 = s => {
    return s.split(' ').map(k => k.split('').reverse('').join('')).join(' ');
};

// 时间: 100 ms 内存: 39.8 MB
const reverseWords2 = s => {
    return s.split('').reverse().join('').split(/\s+/).reverse().join(' ');
};

