package org.slackapitrial;

public class SlackApiTrial {
	
	public void tryPostMsg() {
		SlackFunction slack = new SlackFunction();
		slack.tryPostMessage();
	}
	
	
	
	
	public static void main(String[] args) {
		new SlackApiTrial().tryPostMsg();
	}
}
