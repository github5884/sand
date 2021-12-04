# Google reCAPTHAを試しに使ってみるプロジェクト

## (0) 環境情報
* 公式ドキュメント
  * https://developers.google.com/recaptcha/docs/v3
* 前提条件
  * Googleアカウントを保有していること
* Google reCAPTCHAのバージョン
  * Google reCAPTCHA v3


## (1) Google reCAPTCHAに登録してAPIキーを入手

* Google reCAPTCHA v3のサイト登録ページにアクセス
  * https://www.google.com/recaptcha/admin/create
* サイト登録に必要な項目を選択、入力
  * ラベル
    * 任意のラベル名を入力("reCAPTCHAtrial")
  * reCAPTCHA タイプ
    * 「reCAPTCHA v3」を選択
  * ドメイン
    * サーバのIPアドレスを入力
  * [送信]ボタンを押下
* reCAPTCHAキーが発行される
  * サイトキーを入手
    * クライアントサイドで使用する
  * シークレットキーを入手
    * サーバサイドで使用する

## (2) クライアントサイドにreCAPTCHAを組み込み
* クライアントサイトhtmlにreCAPTCHAコード一式(js)を組み込み

## (3) サーバサイドにreCAPTCHAを組み込み

