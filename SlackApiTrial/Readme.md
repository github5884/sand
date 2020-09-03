# プロジェクト名

SlackApiTrial

# 概要

Slack SDK for Javaを試しに使ってみるプロジェクト

# 実装前の準備

## SDK組み込み手順

- pom.xmlにライブラリ情報を追記

	<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
	  ・・・
	  <dependencies>
	    <dependency>
	      <groupId>com.slack.api</groupId>
	      <artifactId>slack-api-client</artifactId>
	      <version>1.1.3</version>
	    </dependency>
	  </dependencies>
	</project>

## Slackのトークンを取得

開発用ワークスペースのトークンを取得

### Appを作成

- https://api.slack.com/apps
- [Create an App]ボタンを押下
- App名と対象ワークスペースを指定し、[Create App]ボタンを押下

### 認証関連の設定ページにアクセス

- https://api.slack.com/apps/A019X2AQXV3/oauth?
- "Scopes"セクションの"User Token Scopes"にて、[Add an OAuth Scope]ボタンを押下
- Scope "chat:write"を選択

### AppをSlack上にインストール

- Settings ＞ "Install App"を選択
- [Install App to Workspace]ボタンを押下
- 「実行できる内容」として「あなたに代わりメッセージを送信する」が記載されていることを確認
- [許可する]ボタンを押下
- "OAuth Access Token"の表示内容をトークンとして控えておく


# 参照ページ

- 「APIのクライアントセットアップ」
-- https://slack.dev/java-slack-sdk/guides/ja/web-api-client-setup

