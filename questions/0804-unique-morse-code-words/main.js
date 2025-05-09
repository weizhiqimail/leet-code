const uniqueMorseRepresentations = words => {
    const codes = ['.-', '-...', '-.-.', '-..', '.', '..-.', '--.', '....', '..', '.---', '-.-', '.-..', '--', '-.', '---', '.--.', '--.-', '.-.', '...', '-', '..-', '...-', '.--', '-..-', '-.--', '--..'];
    const set = new Set();
    const aCode = 'a'.charCodeAt(0);
    for (let i = 0; i < words.length; i++) {
        let word = words[i];
        let str = '';
        for (let j = 0; j < word.length; j++) {
            str += codes[word.charCodeAt(j) - aCode];
        }
        set.add(str);
    }
    return set.size;
};
