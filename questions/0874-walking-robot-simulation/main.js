function robotSim(commands, obstacles) {
    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];
    let endX = 0;
    let endY = 0;
    let di = 0;
    let result = 0;
    let obstacleMap = {};

    for (let i = 0; i < obstacles.length; i++) {
        obstacleMap[obstacles[i][0] + '-' + obstacles[i][1]] = true;
    }

    for (let s = 0; s < commands.length; s++) {
        const item = commands[s];
        if (item === -2) {
            di = (di + 3) % 4;
        } else if (item === -1) {
            di = (di + 1) % 4;
        } else {
            for (let z = 1; z <= item; z++) {
                let nextX = endX + dx[di];
                let nextY = endY + dy[di];
                if (obstacleMap[nextX + '-' + nextY]) {
                    break;
                }
                endX = nextX;
                endY = nextY;
                result = Math.max(result, endX * endX + endY * endY);
            }
        }
    }
    return result;
}

console.log(robotSim([4, -1, 3,], []));

