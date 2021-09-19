# coding: utf-8
import json
import requests

def main():
	postMessage("メッセージを送信します。\nここから2行目です。")


def postMessage(postMsg):
	
	# chatwork api parameters
	apiToken = '*****************'
	roomId = '*********'
	
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

	httpRes = requests.post(postUrl, headers=postHeader, params=postData)
	
	print(httpRes.content)
	

if __name__ == '__main__':
	main()
