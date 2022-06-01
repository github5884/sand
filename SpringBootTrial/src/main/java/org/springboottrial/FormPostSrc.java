package org.springboottrial;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

/**
 * Form送信元画面コントローラクラス
 */
@Controller
public class FormPostSrc {
	@RequestMapping(value = "/formpostsrc", method = RequestMethod.GET)
	public String formPostSrc(Model model) {
		return "formPostSrc";
	}
}
