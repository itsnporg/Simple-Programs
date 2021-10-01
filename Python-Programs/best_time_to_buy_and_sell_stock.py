def maxProfit(prices: List[int]) -> int:
    if len(prices) == 0:
        return 0
    else:
        low = 99999  # represent minimum price so far
        profitmax = 0
        for price in prices:
            if price > low:
                if price - low > profitmax:
                    profitmax = price - low
            elif price < low:
                low = price

        return profitmax
