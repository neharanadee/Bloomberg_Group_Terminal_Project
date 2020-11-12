from collections import defaultdict
from collections import deque
from heapq import *


class Exchange_Node:
    def __init__(self, price, time_stamp):
        self.price = price
        self.time_stamp = time_stamp

    def __str__(self):
        result = "Price {} with timestamp {}".format(self.price, self.time_stamp)
        return result

    def __lt__(self, other):
        if self.time_stamp > other.time_stamp:
            return -1
        elif self.time_stamp < other.time_stamp:
            return 1
        else:
            return 0


class Foreign_Exchange:

    def __init__(self):
        #updates stored in a max_heap - according to the time_stamp
        self.currency_pair_updates = defaultdict(list)
        self.all_currencies = set()


    def add_foreign_exchange_value( self, from_currency, to_currency, price, time_stamp):
        node = Exchange_Node(price, time_stamp)
        curr = (from_currency, to_currency)
        heappush(self.currency_pair_updates[curr], node)

        #keeping a set of all currency exhanges we have so far
        self.all_currencies.add(from_currency)
        self.all_currencies.add(to_currency)

    def display_top_10_recent_prices(self):
        top_10_min_heap = []
        for curr_pair in self.currency_pair_updates:
            avail_updates = self.currency_pair_updates[curr_pair]
            largest_n = nsmallest(min(10, len(avail_updates)), avail_updates )
            for elem in largest_n:
                heappush(top_10_min_heap, (elem.time_stamp, curr_pair, elem))
                if len(top_10_min_heap) > 10:
                    heappop(top_10_min_heap)

        #printing the result
        for elem in top_10_min_heap:
            time_stamp, exchange, node = elem
            print("From currency {} to currency {} at {} seconds with price {}".format(exchange[0], exchange[1], time_stamp, node.price))


    def display_top_most_recent_prices_for_currency_pair(self, from_currency, to_currency, n_prices):
        relevant_prices = self.currency_pair_updates[(from_currency, to_currency)]
        top_recent_prices = nsmallest(n_prices, relevant_prices )
        for node in top_recent_prices:
            print("From currency {} to currency {} at {} seconds with price {}".format(from_currency, to_currency, node.time_stamp, node.price))


    def display_best_price_to_buy_currency(self, from_currency, to_currency):
        self.all_currencies.remove(to_currency)
        def recursive_best_price_search(value, from_currency, seen):
            #best price from direct conversion
            best_price = self.convert_currency(value, from_currency, to_currency)
            seen.add(from_currency)
            for currency in self.all_currencies:
                if currency not in seen:
                    curr_value = self.convert_currency(value, from_currency, currency)
                    best_price = max(best_price, recursive_best_price_search(curr_value, currency, seen))
            seen.remove(from_currency)
            return best_price
        print(recursive_best_price_search(1, from_currency, set()))

    def convert_currency(self, value, from_currency, to_currency):
        exchange_rate = self.get_latest_price_for_pair(from_currency, to_currency)
        return value * exchange_rate

    def get_latest_price_for_pair(self, from_currency, to_currency):
        relevant_prices = self.currency_pair_updates[(from_currency, to_currency)]
        best_price = -float('inf')
        if relevant_prices:
            best_price = relevant_prices[0].price
        return best_price

# TESTING CODE

fx = Foreign_Exchange()

# Three currencies so far
fx.add_foreign_exchange_value("SGD", "INR", 50, 120)
fx.add_foreign_exchange_value("INR", "SGD", 0.2, 160)
fx.add_foreign_exchange_value("SGD", "USD", .7, 100)
fx.add_foreign_exchange_value("USD", "SGD", 1.2, 40)
fx.add_foreign_exchange_value("Pound", "SGD", 1.7, 10)
fx.add_foreign_exchange_value("SGD", "Pound", .5, 300)
fx.add_foreign_exchange_value("Pound", "INR", 100, 20)
fx.add_foreign_exchange_value("INR", "Pound", .01, 11)
fx.add_foreign_exchange_value("Pound", "USD", 1.32, 500)
fx.add_foreign_exchange_value("USD", "Pound", .75, 1)

print("Top 10 recent prices".upper())
fx.display_top_10_recent_prices()
print("Top n recent prices for given exchange".upper())
fx.display_top_most_recent_prices_for_currency_pair("SGD", "INR", 2)
print("Best price to buy currency from the given currency pairs".upper())
# resulting is SGD -> USD -> Pound -> INR
fx.display_best_price_to_buy_currency("SGD", "INR")





