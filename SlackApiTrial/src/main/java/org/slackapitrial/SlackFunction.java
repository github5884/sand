package org.slackapitrial;

import java.io.IOException;

import com.slack.api.Slack;
import com.slack.api.methods.MethodsClient;
import com.slack.api.methods.SlackApiException;
import com.slack.api.methods.request.chat.ChatPostMessageRequest;
import com.slack.api.methods.response.chat.ChatPostMessageResponse;

/**
 * Slack機能クラス
 */
public class SlackFunction {
	
	public SlackFunction() {
		
	}
	
	/**
	 * メッセージ投稿を試す
	 */
	public void tryPostMessage() {
		// Slackインスタンスを生成
		Slack slack = Slack.getInstance();
		
		// APIトークンを設定
		String userToken = "xoxp-XXXXXXXXXXXXXXXX";
		
		// APIメソッドクライアントを初期化
		MethodsClient methods = slack.methods(userToken);
		
		// APIリクエスト内容を構成
		ChatPostMessageRequest request = ChatPostMessageRequest.builder()
				.channel("work_start_end")
				.text("メッセージを送信する。")
				.build();
		
		// APIレスポンスを受け取る
		ChatPostMessageResponse response = null;
		try {
			response = methods.chatPostMessage(request);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SlackApiException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		if (response != null) {
			if (response.isOk()) {
				System.out.println("送信OK");
			} else {
				System.out.println("送信NG");
				System.out.println(response.toString());
			}
			
			
			
		}
	}
	
}
