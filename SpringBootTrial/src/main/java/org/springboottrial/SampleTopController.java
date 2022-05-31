package org.springboottrial;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

/**
 * サンプルTOP画面のコントローラクラス
 */
@Controller
public class SampleTopController {
	@RequestMapping(value = "/sampletop", method = RequestMethod.GET)
	public String sampleTop(Model model) {
		// "message"属性にて、画面に追加する文字列を指定
		model.addAttribute("message", new String("controllerから渡す文字列"));
		return "index";
	}
}
