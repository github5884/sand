# プロジェクト名

SlackApiTrial

# 概要

Slack SDK for Javaを試しに使ってみるプロジェクト


# SDK組み込み手順

## pom.xmlにライブラリ情報を追記

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

# 実装



# 参照ページ

- 「APIのクライアントセットアップ」
-- https://slack.dev/java-slack-sdk/guides/ja/web-api-client-setup

- Simple Slack APIを使ってSlackへHello World!
-- https://javazuki.com/articles/simple-slack-api-helloworld.html