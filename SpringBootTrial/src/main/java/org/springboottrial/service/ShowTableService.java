package org.springboottrial.service;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springboottrial.dao.FirstTableDao;
import org.springboottrial.entity.FirstTableEntity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * テーブル内容表示サービスクラス
 */
@Service
public class ShowTableService {
	@Autowired
	private FirstTableDao firstTableDao;
	
	/**
	 * 1stテーブルのデータを取得
	 * @return	1stテーブルのデータ
	 */
	public List<Map<BigDecimal, String>> getFirstTableData() {
		// 1stテーブルの全レコードを取得
		List<FirstTableEntity> entityList = firstTableDao.selectAll();
		
		List<Map<BigDecimal, String>> ret = new ArrayList<>();
		for (FirstTableEntity entity : entityList) {
			Map<BigDecimal, String> tableMap = new HashMap<>();
			// TODO add code to set data from entity into map
		}
		
		return ret;
	}

}
