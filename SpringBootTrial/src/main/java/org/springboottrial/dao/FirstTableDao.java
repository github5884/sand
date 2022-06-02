package org.springboottrial.dao;

import java.util.List;

import org.seasar.doma.Dao;
import org.seasar.doma.Delete;
import org.seasar.doma.Insert;
import org.seasar.doma.Select;
import org.seasar.doma.Update;
import org.seasar.doma.boot.ConfigAutowireable;
import org.springboottrial.entity.FirstTableEntity;

/**
 * 1stテーブルDAOインターフェース
 */
@Dao
@ConfigAutowireable
public interface FirstTableDao {
	
	/**
	 * insert実行
	 * @param entity	1stテーブルエンティティ
	 * @return	実行結果件数
	 */
	@Insert
	int insert(FirstTableEntity entity);
	
	/**
	 * update実行
	 * @param entity	1stテーブルエンティティ
	 * @return	実行結果件数
	 */
	@Update
	int update(FirstTableEntity entity);
	
	/**
	 * delete実行
	 * @param entity	1stテーブルエンティティ
	 * @return	実行結果件数
	 */
	@Delete
	int delete(FirstTableEntity entity);
	
	/**
	 * レコード全件取得
	 * @return	1stテーブルエンティティリスト
	 */
	@Select
	List<FirstTableEntity> selectAll();	
}
