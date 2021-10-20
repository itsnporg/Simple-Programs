try:
    import requests
    from bs4 import BeautifulSoup
except Exception as e:
    print("Some modules are Missing {}".format(e))


class Request(object):

    def __init__(self):
        self.url = 'http://www.laughfactory.com/jokes/latest-jokes'
        self.headers = {
    'Accept-Encoding': 'gzip, deflate, sdch',
    'Accept-Language': 'en-US,en;q=0.8',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
    'Referer': 'http://www.wikipedia.org/',
    'Connection': 'keep-alive',}

    @property
    def get(self):
        try:
            r =requests.get(self.url, self.headers)
            return r.text
        except Exception as e:
            print("Failed to Make Response ")


class Stack(object):
    def __init__(self):
        self.data = []


class Scrapper(object):

    def __init__(self):
        self.request = Request()
        self.stack = Stack()

    def getJokes(self):

        soup = BeautifulSoup(self.request.get, 'html.parser')
        div = soup.find('div',class_="jokes-sec")

        for x in div.findAll('div', class_="joke-text"):
            self.stack.data.append(x.text.strip())

        return self.stack.data


class Jokes(object):

    def __init__(self):
        self.scrapper= Scrapper()

    def getJokes(self):
        data = self.scrapper.getJokes()
        return data


if __name__ == "__main__":
    jokes = Jokes()
    data ​= jokes.getJokes()

    for i,x in enumerate(data):
        print(i,"\t", x)