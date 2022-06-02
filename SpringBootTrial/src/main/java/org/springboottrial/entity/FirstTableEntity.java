package org.springboottrial.entity;

import java.math.BigDecimal;

import org.seasar.doma.Column;
import org.seasar.doma.Entity;

import lombok.Getter;
import lombok.Setter;

/**
 * 1stテーブルエンティティクラス
 */
@Getter
@Setter
@Entity
public class FirstTableEntity {
	/** レコードID */
	@Column(name = "recordid")
	private BigDecimal recordid;
	
	/** レコードテキスト */
	@Column(name = "recordtext")
	private String recordtext;
}
