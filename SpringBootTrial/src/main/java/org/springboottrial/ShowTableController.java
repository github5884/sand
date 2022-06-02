package org.springboottrial;

import org.springboottrial.service.ShowTableService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

/**
 * テーブル内容表示画面コントローラクラス
 */
@Controller
public class ShowTableController {
	
	@Autowired
	ShowTableService showTableService;
	
	@RequestMapping(value = "/showtable", method = RequestMethod.GET)
	public String showTable	(Model model) {
		return "showtable";
	}
}
