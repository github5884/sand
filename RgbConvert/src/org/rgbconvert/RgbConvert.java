package org.rgbconvert;

public class RgbConvert {
    // decimal-hex対応リスト
    private final String[] HEXLIST = new String[] {
            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
            , "a", "b", "c", "d", "e", "f"
    };


    /**
     * 変換処理
     * @param input     入力内容
     */
    public void convert(String[] input) {

        String output = "";

        try {
            if (input.length == 1) {        // 16進数→10進数
                String hexCode = input[0];
                // #を取り除く
                hexCode.replaceAll("#","");

                // RGB各値を変換
                int[] rgbNums = new int[3];
                for (int i = 0; i < 3; i++) {
                    int offset = i * 2;
                    rgbNums[i] = hex2decimal(hexCode.substring(offset, offset + 1)) * 10
                                    + hex2decimal(hexCode.substring(offset + 1, offset + 2));
                }

                for (int rgbNum : rgbNums) {
                    if (!output.equals("")) output = output + " ";
                    output = output + String.valueOf(rgbNum);
                }

            } else if (input.length == 3) {     // 10進数→16進数
                output = "#";
                for (int i = 0; i < input.length; i++) {
                    output = output + decimal2hex(Integer.parseInt(input[i]));
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
            return;
        }


        System.out.println(output);

    }


    /**
     * 16進数→10進数に変換
     * @param org       変換対象値＠String
     * @return          変換後数値＠int
     */
    private int hex2decimal(String org) {
        int ret = -1;
        for (int i = 0 ; i < HEXLIST.length; i++) {
            if (org.toLowerCase().equals(HEXLIST[i])) {
                ret = i;
                break;
            }
        }

        return ret;
    }


    /**
     * 10進数→16進数に変換
     * @param org       変換対象値＠int
     * @return          変換後数値＠String
     */
    private String decimal2hex(int org) {
        return HEXLIST[org / 16] + HEXLIST[org % 16];
    }



    /**
     * エントリポイント
     * @param args  コマンドライン引数
     */
    public static void main(String[] args) {
        // 引数チェック
        if (args.length < 1) {
            System.out.println("ERROR : invalid arguments." + BR
                            + "argument = decimal color code(ex. [255 255 255]) or hex color code(ex. [FFFFFF])");
            return;
        }

        // 変換処理
        new RgbConvert().convert(args);
    }

    private static final String BR = System.getProperty("line.separator");
}
