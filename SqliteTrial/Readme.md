# プロジェクト名

SqliteTrial

# 概要

SQLiteアクセスを試しに行ってみるプロジェクト

# 実装前の準備

## ライブラリ組み込み手順

- pom.xmlにライブラリ情報を追記

~~~
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
  ・・・
  <dependencies>
    <dependency>
      <groupId>org.xerial</groupId>
      <artifactId>sqlite-jdbc</artifactId>
      <version>3.31.1</version>
    </dependency>
  </dependencies>
</project>
~~~


