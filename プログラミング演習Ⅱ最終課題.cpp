//「宝くじを100回ランダムで買う」をテーマとしたプログラミングを作成する
//クラス”当選番号案内”にメンバ”当選等級”、”当選金額”、”番号”を宣言
//首都太郎くんがランダムで6桁番号を選出して、当たったかどうかを確認する。
//当たったら当選通知「あたり」を出力する。
#include <iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<sstream>
#include<functional>
#include<iterator>
#include<memory>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
random_device engine;
//クラス”当選番号案内”にメンバ”当選等級”、”当選金額”、”番号”を宣言
struct WNG { //クラスWNG(Winning Number Guide)の定義
protected: //保護
    int WC; //メンバWC(Winning Class)の宣言
    int WP; //メンバWP(Winning Price)の宣言
    int WN; //メンバWN(Winning Number)の宣言 int string
public: //呼び出すメンバ関数の宣言
    void setWC(int newWC) { WC = newWC; }
    int getWC() { return WC; }
    void setWP(int newWP) { WP = newWP; }
    int getWP() { return WP; }
    void setWN(int newWN) { WN = newWN; }
    int getWN() { return WN; }
};
vector<string> split(string input, char delimiter) {
    istringstream stream(input);
    string field;
    vector<string>result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}
//ファイルを開いて中身を列ごとに格納
auto storageWNG() {
    ifstream datafile("WNG.csv");
    string line;
    vector <string>strv;
    vector<string>allinfov;
    while (getline(datafile, line)) {
        strv = split(line, ',');
        for (int i = 0; i < strv.size(); ++i) { //strv.size()
            allinfov.emplace_back(strv[i]);
        }
    }
    datafile.close();
    return allinfov;
}
//ランダムで10個の番号を生成
auto randomInt(const int min, const int max, const int num) {
    vector<int> taro_buy_lottery;
    random_device rnd; //乱数生成エンジン
    uniform_int_distribution<int> dist(100, 199);//分布生成器(整数の一様分布)
    //乱数の生成数だけ繰り返す
    for (int i = 0; i < num; i++)
        taro_buy_lottery.push_back(dist(rnd)); //乱数を生成し，Vectorへ格納
    return taro_buy_lottery;
}
//Vectorに格納された数値を表示する関数
void displayNum(vector<int> taro_buy_lottery) {
    //先頭から末尾までループ
    for (auto x : taro_buy_lottery)
        cout << x << ", "; //taro_buy_lotteryの中身を順番に表示
    cout << endl;
}
//vectorから出す
int main() {
    cout << "抽選番号\n";
    vector<int>randNum;
    randNum = randomInt(100, 199, 100); //ランダムで6桁番号を100個出す
    displayNum(randNum);
    cout << "当選番号\n";
    WNG wng;
//    auto infovec = storageWNG();
//    for (int j = 0; j < infovec.size(); ++j) {
//        if (j % 3 == 0) {
//            wng.setWC(stoi(infovec[j]));
//            cout << wng.getWC() << " ";
//        }
//        else
 //           if (j % 3 == 1) {
//                wng.setWP(stoi(infovec[j]));
//                cout << wng.getWP() << " ";
//            }
//        if (j % 3 == 2) {
//            wng.setWN(stoi(infovec[j]));
//            cout << wng.getWN() << " \n" << endl;
//        }
        //ｋ番目のランダムナンバーとl番目の当選番号が一致しているか確認する
 
        for (int k = 0; k < 100; ++k) {
 //           for (int l = 0; k < 7; ++k) {
            if (randNum[k] == wng.getWN()) {
                cout <<"\n"<< "あたり！\n";//一致している
                ;
            }
            else if (randNum[k] != wng.getWN()) {
                cout << "はずれ！";//一致していない
            };
            }
        }
//    }
//}
