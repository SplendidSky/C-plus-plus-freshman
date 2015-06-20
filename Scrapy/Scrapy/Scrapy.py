#coding:utf-8
import bs4
import urllib2

valid = False

while not valid:
    stockID = raw_input(u"股票代码：")
    try:
        html = urllib2.urlopen('http://stock.quote.stockstar.com/%s.shtml'
                               % stockID).read()
        valid = True
    except urllib2.HTTPError, e:
        valid = False
        print u"股票代码不存在, 请重新输入"
    
soup = bs4.BeautifulSoup(html)
stock_name = soup.title.string
print type(stock_name)
print stock_name
price_tag = soup.findAll('p', id = 'stockclose')
price = ''
for s in price_tag:
    formatstr = '.0123456789'
    print type(s)



print price

#print html
