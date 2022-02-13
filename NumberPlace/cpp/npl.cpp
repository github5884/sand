/*
 数独解答プログラム
 npl.cpp
 2022.2.11
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/* グローバル変数 */
const int NUMS_BLOCK = 9;	// 問題の縦横マス数
const int NUMS_SQUARE = 3;	// 問題の縦横スクエア数

/**
 * 問題データ出力
 * @param q_data 出力対象データ
 */
void printData(int q_data[][NUMS_BLOCK]) {
	for (int i = 0; i < (NUMS_BLOCK * 2 + 1); i++) {
		cout << "*" << flush;
	}
	cout << endl;
	
	
	// 行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		cout << "|" << flush;
		
		// 列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			if(q_data[r][c] == 0) {
				cout << " |" << flush;
			} else {
				cout << q_data[r][c] << "|" << flush;
			}
		}
		
		//改行
		cout << endl;
	}
}

/**
 * 正解値候補リストセット出力
 * @param q_cand 正解値候補リストセット
 */
void printCandidate(vector<vector<vector<int> > > q_cand) {
	// 行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		cout << "++++++++++" << endl;
		
		// 列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			
			if (q_cand[r][c].size() > 0) {
				cout << (r + 1) << "行/" << (c + 1) << "列 :" << flush;
				// 正解値候補リストを走査
				for (int i = 0; i < q_cand[r][c].size(); i++) {
					// 候補数字を出力
					cout << " " << q_cand[r][c][i] << flush;
				}
				// 改行
				cout << endl;
			}
		}
	}
}

/**
 * 問題CSVファイル読み込み
 * @param q 問題データ格納用配列
 * @return 0=OK, -1=NG
 */
int readCsvFile(int q[][NUMS_BLOCK]) {
	// 問題CSVファイル
	ifstream ifs("./q.csv");
	
	// 行データ読み込み用バッファを準備
	int buf_size = NUMS_BLOCK * 2;
	char q_str[buf_size];
	
	// 問題CSVファイル読み込み失敗時処理
	if (ifs.fail()) {
		return -1;
	}
	
	// 問題CSVファイルを読み込む
	char* token;
	char delim[] = ",";
	int row_offset = 0;
	int col_offset;
	while (ifs.getline(q_str, buf_size)) {
		// cout << q_str << endl;
		
		// col位置を初期化
		col_offset = 0;
		
		// カンマ区切りで分割
		token = strtok(q_str, delim);
		while (token != NULL) {
			// 数値に変換
			int num = atoi(token);
			
			// 問題データ配列に格納
			q[row_offset][col_offset] = num;
//			printf("%d/%d:%d\n", row_offset, col_offset, q[row_offset][col_offset]);
			
			// col位置をインクリメント
			col_offset++;
			
			// NULL処理
			token = strtok(NULL, delim);
		}
		
		// row位置をインクリメント
		row_offset++;
	}
	
	return 0;
}

/**
 * 正解値候補リストセットをリセット
 * @param q 問題データ配列
 * @return 正解値候補リストセット
 */
vector<vector<vector<int> > > resetCandidate(int q[][NUMS_BLOCK]) {
	// 正解値候補リストセットを準備
	vector<vector<vector<int> > > q_cand;
	
	// 問題データの行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		
		// 正解値候補リストセット行を準備
		vector<vector<int> > q_cand_line;
		
		// 問題データの列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			// 正解値候補リストを準備
			vector<int> cand_list;
			
			// 問題データ上数字がまだ無いセルに候補数字を投入
			if (q[r][c] == 0) {
				for (int i = 0; i < NUMS_BLOCK; i++) {
					cand_list.push_back(i + 1);
				}
			}
			
			// 正解値候補リストセット行に正解値候補リストを追加
			q_cand_line.push_back(cand_list);
		}
		
		// 正解値候補リストセットに正解値候補リストセット行を追加
		q_cand.push_back(q_cand_line);
	}
	
	return q_cand;
	
}


/**
 * 候補数字を探索
 * @param q 問題データ配列
 * @param q_cand 正解値候補リストセット
 * @return 探索後正解値候補リストセット
 */
vector<vector<vector<int> > > expoloreCandidate(int q[][NUMS_BLOCK], vector<vector<vector<int> > > q_cand) {
	// 問題データの行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		
		// 問題データの列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			
			// 問題データ上数字が存在しないセルに対して処理
			if (q[r][c] == 0) {
				
				// 水平方向に探索
				for (int i = 0; i < NUMS_BLOCK; i++) {
					
					// 同一セルはスルー
					if (i == c) {
						continue;
					}
					
					// 探索先セルに数字が存在する場合
					if (q[r][i] > 0) {
						// 正解値候補リストから当該数字を除去
						for(int j = 0; j < q_cand[r][c].size(); j++) {
							if (q[r][i] == q_cand[r][c][j]) {
								q_cand[r][c].erase(q_cand[r][c].begin() + j);
								break;
							}
						}
					}
				}
				
				// 垂直方向に探索
				for (int i = 0; i < NUMS_BLOCK; i++) {
					
					// 同一セルはスルー
					if (i == r) {
						continue;
					}
					
					// 探索先セルに数字が存在する場合
					if (q[i][c] > 0) {
						// 正解値候補リストから当該数字を除去
						for(int j = 0; j < q_cand[r][c].size(); j++) {
							if (q[i][c] == q_cand[r][c][j]) {
								q_cand[r][c].erase(q_cand[r][c].begin() + j);
								break;
							}
						}
					}
				}
				
				// 所属スクエア内で探索
				int sq_raw_index = r / NUMS_SQUARE;		// スクエア行インデックス
				int sq_column_index = c / NUMS_SQUARE;	// スクエア列インデックス
				
				// スクエア行ごとに処理
				for (int sq_r = (sq_raw_index * NUMS_SQUARE); sq_r < ((sq_raw_index+ 1) * NUMS_SQUARE); sq_r++) {
					
					// スクエア列ごとに処理
					for (int sq_c = (sq_column_index * NUMS_SQUARE); sq_c < ((sq_column_index + 1) * NUMS_SQUARE); sq_c++) {
						
						// 同一セルはスルー
						if ((r == sq_r) && (c == sq_c)) {
							continue;
						}
						
						// 探索先セルに数字が存在する場合
						if (q[sq_r][sq_c] > 0) {
							// 正解値候補リストから当該数字を除去
							for(int i = 0; i < q_cand[r][c].size(); i++) {
								if (q[sq_r][sq_c] == q_cand[r][c][i]) {
									q_cand[r][c].erase(q_cand[r][c].begin() + i);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return q_cand;
}

/**
 * 単一候補数字を正解値として確定
 * @param q 問題データ配列
 * @param q_cand 正解値候補リストセット
 * @return 確定処理後正解値候補リストセット
 */
vector<vector<vector<int> > > confirmSingleCandidate(int q[][NUMS_BLOCK], vector<vector<vector<int> > > q_cand) {
	// 問題データの行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		
		// 問題データの列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			
			// 単一候補の場合
			if (q_cand[r][c].size() == 1) {
				// 正解値として確定
				q[r][c] = q_cand[r][c][0];
				
				// 正解値候補リストから候補数字を除去
				q_cand[r][c].erase(q_cand[r][c].begin());
			}
		}
	}
	
	return q_cand;
}

/**
 * 単独候補数字を正解値として確定
 * @param q 問題データ配列
 * @param q_cand 正解値候補リストセット
 * @return 確定処理後正解値候補リストセット
 */
vector<vector<vector<int> > > confirmOnlyoneCandidate(int q[][NUMS_BLOCK], vector<vector<vector<int> > > q_cand) {
	// 問題データの行ごとに処理
	for (int r = 0; r < NUMS_BLOCK; r++) {
		
		// 問題データの列ごとに処理
		for (int c = 0; c < NUMS_BLOCK; c++) {
			
			// 候補数字ごとに処理
			for (int i = 0; i < q_cand[r][c].size(); i++) {
				int target_count;
				
				// 処理対象番号
				int target_num = q_cand[r][c][i];
				
				// 水平方向に候補出現数をカウント
				target_count = 0;
				for (int j = 0; j < NUMS_BLOCK; j++) {
					
					// 同一セルはスルー
					if (j == c) {
						continue;
					}
					
					// 対象番号が候補リストに含まれていればカウントアップ
					auto find_result = find(q_cand[r][j].begin(), q_cand[r][j].end(), target_num);
					if (find_result != q_cand[r][j].end()) {
						target_count++;
						break;
					}
				}

				// 単独候補であれば正解値として確定
				if (target_count == 0) {
					q[r][c] = target_num;
					break;
				}

				// 垂直方向に候補出現数をカウント
				target_count = 0;
				for (int j = 0; j < NUMS_BLOCK; j++) {
					
					// 同一セルはスルー
					if (j == r) {
						continue;
					}
					
					// 対象番号が候補リストに含まれていればカウントアップ
					auto find_result = find(q_cand[j][c].begin(), q_cand[j][c].end(), target_num);
					if (find_result != q_cand[j][c].end()) {
						target_count++;
						break;
					}
				}
				
				// 単独候補であれば正解値として確定
				if (target_count == 0) {
					q[r][c] = target_num;
					break;
				}
				
				// 所属スクエア内で候補出現数をカウント
				target_count = 0;
				int sq_raw_index = r / NUMS_SQUARE;		// スクエア行インデックス
				int sq_column_index = c / NUMS_SQUARE;	// スクエア列インデックス
				
				// スクエア行ごとに処理
				for (int sq_r = (sq_raw_index * NUMS_SQUARE); sq_r < ((sq_raw_index+ 1) * NUMS_SQUARE); sq_r++) {
					
					// スクエア列ごとに処理
					for (int sq_c = (sq_column_index * NUMS_SQUARE); sq_c < ((sq_column_index + 1) * NUMS_SQUARE); sq_c++) {
						
						// 同一セルはスルー
						if ((r == sq_r) && (c == sq_c)) {
							continue;
						}
						
						// 対象番号が候補リストに含まれていればカウントアップ
						auto find_result = find(q_cand[sq_r][sq_c].begin(), q_cand[sq_r][sq_c].end(), target_num);
						if (find_result != q_cand[sq_r][sq_c].end()) {
							target_count++;
							break;
						}
					}
					
					// 候補が既に存在する場合、次のスクエア行へ。
					if (target_count > 0) {
						break;
					}
				}
				
				// 単独候補であれば正解値として確定
				if (target_count == 0) {
					q[r][c] = target_num;
					break;
				}
				
			}
		}
	}
	
	return q_cand;
}


/**
 * エントリポイント
 */
int main() {
	int res;
	
	cout << "start Number Place Program" << endl;
	
	// 問題データ配列を準備
	int q[NUMS_BLOCK][NUMS_BLOCK];
	
	// 問題CSVファイル読み込み
	res = readCsvFile(q);
	if (res < 0) {
		// 異常終了
		cerr << "問題CSVファイルを読み込めませんでした。" << endl;
		return -1;
	}
	
	// 問題データ配列の内容を出力
	cout << "===== 解答開始前 =====" << endl;
	printData(q);
	
	// 正解値候補リストセットをリセット
	vector<vector<vector<int> > > q_cand;
	q_cand = resetCandidate(q);
	
	// 解答開始
	int end_flag = 0;
	string next_act;
	int roop_count = 0;
	while(end_flag == 0) {
		// 候補数字を探索
		q_cand = expoloreCandidate(q, q_cand);
		
		// 単一候補数字を正解値として確定
		q_cand = confirmSingleCandidate(q, q_cand);
		
		// 正解値候補リストセットをリセット
		q_cand = resetCandidate(q);
				
		// 候補数字を探索
		q_cand = expoloreCandidate(q, q_cand);
		
		// 単独候補数字を正解値として確定
		q_cand = confirmOnlyoneCandidate(q, q_cand);
		
		// 正解値候補リストセットをリセット
		q_cand = resetCandidate(q);
		
		// ループ回数をカウントアップ
		roop_count++;
		
		cout << "===== 探索・確定後 [" << roop_count << "]周目 =====" << endl;
		// 問題データを出力
		printData(q);
		cout << "========================" << endl;
		
		// 再探索するかユーザに確認
		cout << "下記いずれかのキーを押下してください。" << endl;
		cout << "　(1) 引き続き処理を続ける場合 ： [Enter]キー" << endl;
		cout << "　(2) 処理を終了する場合　　　 ： [Ctrl] + [C}キー" << endl;
		getline(cin, next_act);
	}
	
	return 0;

}
