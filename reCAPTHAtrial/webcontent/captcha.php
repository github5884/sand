<?php
 $secretKey =  'シークレットキーを指定';
 $captchaResponse = $_POST['g-recaptcha-response'];
 
 // APIリクエスト
 $verifyResponse = file_get_contents("https://www.google.com/recaptcha/api/siteverify?secret={$secretKey}&response={$captchaResponse}");
 
 // APIレスポンス確認
 $responseData = json_decode($verifyResponse);
 if ($responseData->success) {
  echo 'authentication success.'; // 成功（ロボットではない）
 } else {
  echo 'authentication failed.'; // 失敗
 }
?>
