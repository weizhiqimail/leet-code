function maxProfit(prices) {
    let profit = 0;

    for (let i = 1; i < prices.length; i++) {
        const first = prices[i - 1];
        const second = prices[i];
        if (second > first) {
            profit += second - first;
        }
    }
    return profit;
}
