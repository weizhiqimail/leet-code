// 异位词，一个单词里字母出现的次数都一样，但是字母的顺序不一样

// 直接排序比较
const isAnagram1 = (s, t) => {
    if (s === t && t === '') {
        return true;
    }
    if (!s || !t || s.length !== t.length) {
        return false;
    }
    return s.split('').sort().join('') === t.split('').sort().join('');
};

// 哈希表记录每个字母出现的次数
const isAnagram2 = (s, t) => {
    if (s === t && t === '') {
        return true;
    }
    if (!s || !t || s.length !== t.length) {
        return false;
    }

    let counter = {};

    for (let i = 0; i < s.length; i++) {
        let alpha = s[i];
        if (counter.hasOwnProperty(alpha)) {
            counter[alpha]++;
        } else {
            counter[alpha] = 1;
        }
    }

    for (let i = 0; i < t.length; i++) {
        if (counter[t[i]]) {
            counter[t[i]]--;
        } else {
            return false;
        }
    }

    for (let key in counter){
        if(counter[key] !== 0) {
            return false;
        }
    }
    return true;
};


