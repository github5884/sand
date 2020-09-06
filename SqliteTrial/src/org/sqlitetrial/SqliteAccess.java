package org.sqlitetrial;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 * SQLiteアクセスクラス
 */
public class SqliteAccess {
	private Connection connection;
	
	/**
	 * DB接続
	 * @param dbPath	DBファイルパス
	 * @return			true=OK. false=NG
	 */
	public boolean connectDB(String dbPath) {
		connection = null;
		
		try {
			connection = DriverManager.getConnection("jdbc:sqlite:" + dbPath);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		
		return true;
	}
	
	/**
	 * 抽出クエリ実行
	 * @param query			クエリ
	 * @param columns		カラム配列
	 * @return				true=OK, false=NG
	 */
	public String[][] execSelectQuery(String query, String[] columns) {
		// 未接続の場合はクエリを実行しない
		if(connection == null) return null;
		
		List<String[]> retList = new ArrayList<>();
		
		try {
			Statement statement = connection.createStatement();
			statement.setQueryTimeout(30);
			
			// クエリ実行
			ResultSet rs = statement.executeQuery(query);
			
			while (rs.next()) {
				String[] resultLine = new String[columns.length];
				for (int i = 0; i < columns.length; i++) {
					resultLine[i] = rs.getString(columns[i]);
				}
				retList.add(resultLine);
			}
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
		
		String[][] ret = new String[retList.size()][];
		for (int i = 0; i < retList.size(); i++) {
			ret[i] = retList.get(i);
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		SqliteAccess sa = new SqliteAccess();
		
		if (!sa.connectDB("data/sample.sqlite")) {
			System.out.println("DB接続失敗");
			return;
		}
		
		String[][] result = sa.execSelectQuery("select * from info", new String[] {"key", "value"});
		if (result != null) {
			for (String[] resultLine : result) {
				System.out.println(resultLine[0] + "," + resultLine[1]);
			}
		}
		
	}
}
