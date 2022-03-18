"""get Nikkei xTECH RSS feed

getnxtfeed.py
"""

# coding: utf-8
import json
import time
import requests
import feedparser


# define : RSS url
nikkeiXtechRssUrl = 'https://tech.nikkeibp.co.jp/rss/xtech-it.rdf'

def main():
	"""main method

	"""
	
	# get feed info
	feedInfoList = getFeedInfo(nikkeiXtechRssUrl)
	
	# post to chatwork
	for feedInfo in feedInfoList:
		postMessage(feedInfo)


def getFeedInfo(rssUrl):
	"""get RSS feed

	Args:
		rssUrl (string) : 1st argument

	Returns:
		string: Rss feed

	"""

	# get & parse feed
	resData = feedparser.parse(rssUrl)

	feedInfoList = []

	feedNumber = 0
	for entry in resData.entries:
		print(entry.title, entry.link)
		feedNumber += 1
		feedInfoList.append('[' + str(feedNumber) + '] ' + entry.title + '\n' + entry.link)
	
	return feedInfoList


# post chatwork message
def postMessage(postMsg):
	"""post chatowrk message

	Args:
		postMsg (string) : 1st argument

	"""
	
	# chatwork api parameters
	apiToken = '*************'
	roomId = '********'
	
	# post destination url
	postUrl = 'https://api.chatwork.com/v2/rooms/' + roomId + '/messages'
	
	# post header info
	postHeader = {
		'X-ChatWorkToken' : apiToken
	}
	
	# post data
	postData = {
		'body': postMsg
	}

	# wait 1 second
	time.sleep(1)

	# post message
	httpRes = requests.post(postUrl, headers=postHeader, params=postData)
	
	print(httpRes.content)
	
# entry point
if __name__ == '__main__':
	main()
