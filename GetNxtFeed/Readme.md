# プロジェクト名
GetNxtGeed

# 概要
日経クロステックの記事見出し一覧を取得しChatworkに投稿する

# 実行確認環境
- OS  

      CentOS Linux release 7.5.1804 (Core)  

- Python  

      Python 3.6.8  

# 実行前の準備

## 必要なPythonライブラリをインストール

### feedparser
- pipでインストール  

      $ pip install feedparser  

### Requests
- pipでインストール  

      $ pip install requests  

## ChatworkのAPIトークンを取得
- Chatworkにログイン  
- 「サービス連携/API」画面を開く。  
Chatwork画面右上の自アカウントを選択し、表示されたメニューにて「サービス連携」を選択する。  
- 「API Token」画面を開く  
「サービス連携/API」画面左側メニューのAPI->API Tokenを選択  
- Chatworkアカウントのパスワードを入力し、APIトークンを発行  

## Chatworkの投稿先のルームIDを取得
- ルームIDはブラウザ版Chatworkで当該ルームにアクセスした際のURLで分かる  
(この場合[012345678]がルームIDになる)  

    例： https://www.chatwork.com/#!rid012345678    

## 取得したChatworkのAPIトークンとルームIDをソースコード上に設定
- 変数"apiToken"と"roomId"にそれぞれ設定  

      def postMessage(postMsg):  
          
 	        // chatwork api parameters  
 	        apiToken = '*************'  
 	        roomId = '********'  
  
  
# プログラム実行方法
- pythonコマンドで実行(引数不要)  
 
      $ python3 getnxtfeed.py
