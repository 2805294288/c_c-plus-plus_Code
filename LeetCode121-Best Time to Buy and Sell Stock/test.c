int maxProfit(int* prices, int pricesSize) {
    int size = pricesSize;
    int maxProfit = 0;
    int Profit = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            Profit = prices[j] - prices[i];
            if (Profit > maxProfit) {
                maxProfit = Profit;
            }
        }
    }
    return maxProfit;
}