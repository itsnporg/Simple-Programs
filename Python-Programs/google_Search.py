# Google Search
# pip install Google

from googlesearch import search

query = input("Enter your query:\n")

for i in search(query, tld="co.in", num=5, stop=5, pause=2):
    print(i)


# EXplanation

# val: This is the text that you want to search for.

# tld: This refers to the top level domain value like co.in or com which will specify which Google website we want to use.

# lang: This parameter stands for language.

# num: This is used to specify the number of results we want.

# start: This is to specify from where to start the results. We should keep it 0 to begin from the very start.

# stop: The last result to retrieve. Use None to keep searching forever.

# pause: This parameter is used to specify the number of seconds to pause between consecutive HTTP requests because if we hit too many requests, Google can block our IP address.
