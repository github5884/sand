package org.springboottrial;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Form送信先画面コントローラクラス
 */
@Controller
public class FormPostDest {
	@RequestMapping(value = "/formpostdest", method = RequestMethod.POST)
	public String formPostDest(@RequestParam String item1, @RequestParam String item2, Model model) {
		// 入力項目1の内容をセット
		model.addAttribute("itemstr1", item1);
		// 入力項目2の内容をセット
		model.addAttribute("itemstr2", item2);
		
		return "formPostDest";
	}	
}
