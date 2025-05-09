function findContentChildren(g, s) {
    g = g.sort((a, b) => a - b);
    s = s.sort((a, b) => a - b);
    let num = 0;
    let i = 0;
    for (let j = 0; j < s.length; j++) {
        if (i < g.length && g[i] <= s[j]) {
            num++;
            i++;
        }
    }
    return num;
}


