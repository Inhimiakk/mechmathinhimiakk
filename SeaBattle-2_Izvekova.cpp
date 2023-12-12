/* File Project_34.cpp
Realization game "Seabattle-2"
Done by Izvekova Renata from Computer-Mathematics(group 1)
Date 08.12.2023 */

#include "iostream"
#include "windows.h"
#include <stdlib.h>
#include "ctime"
#include "cmath"
using namespace std;
//Функція для переведення літери в координату
int prepare(string letter){
    int num ;
    if (letter == "A"||letter  == "a") {num =1;}else{
    if (letter == "B"||letter  == "b") {num =2;}else{
    if (letter == "C"||letter  == "c") {num =3;}else{
    if (letter == "D"||letter  == "d") {num =4;}else{
    if (letter == "E"||letter  == "e") {num =5;}else{
    if (letter == "F"||letter  == "f") {num =6;}else{
    if (letter == "G"||letter  == "g") {num =7;}else{
    if (letter == "H"||letter  == "h") {num =8;}else{
    if (letter == "I"||letter  == "i") {num =9;}else{
    if (letter == "J"||letter  == "j") {num =10;}
    else{num = 100;}}}}}}}}}}
    return num;


}
//Функція для перевірки координати заданої літерою
bool is_letter_normal(int n){
        bool is_true ;
        if (n==100 || n ==0){
            is_true = false;
        }else{is_true= true;}
    return is_true;
}
//Функція для перевірки чи не виходить координата за межі
bool is_number_normal(int n){
    bool is_true;
    if (n>11||n<1||n==0){
        is_true= false;
        return is_true;
    }
    else{is_true= true;
        return is_true;}


}
//Функція для переведення координати в літеру
string number_to_letter(int number){
    string letter;
    if (number== 1){letter = "A";}
    if (number== 2){letter = "B";}
    if (number== 3){letter = "C";}
    if (number== 4){letter = "D";}
    if (number== 5){letter = "E";}
    if (number== 6){letter = "F";}
    if (number== 7){letter = "G";}
    if (number== 8){letter = "H";}
    if (number== 9){letter = "I";}
    if (number== 10){letter = "J";}
    return letter;

}
//Функція для перевірки чи не можна іти/стріляти на задану координату
bool position_is_locked(int num,int let,string Pole[11][11]){
    if(Pole[num][let] =="1"||Pole[num][let] =="<"||Pole[num][let] ==">"){
        return true;
    }else{
        return false;
    }
}

//Функція для перевірки співпадіння координат
bool equal_or_no(int num,int let,int pos[2]){
    int massive[2];
    massive[0]=num;
    massive[1]=let;
    if (pos[0]== massive[0] && pos[1]==massive[1]){
        return false;
    }
    else{return true;}
}
int main(){
    srand(time (0));
    string Pole_1[11][11];
    string Pole_2[11][11];
    string Pole_1_zapiska[11][11];
    string Pole_2_zapiska[11][11];
    int pozition_p_1[2];
    int pozition_p_2[2];

    Pole_1[0][0] = "  ";
    Pole_1[0][1] = "A";Pole_1[1][0] = "1 ";
    Pole_1[0][2] = "B";Pole_1[2][0] = "2 ";
    Pole_1[0][3] = "C";Pole_1[3][0] = "3 ";
    Pole_1[0][4] = "D";Pole_1[4][0] = "4 ";
    Pole_1[0][5] = "E";Pole_1[5][0] = "5 ";
    Pole_1[0][6] = "F";Pole_1[6][0] = "6 ";
    Pole_1[0][7] = "G";Pole_1[7][0] = "7 ";
    Pole_1[0][8] = "H";Pole_1[8][0] = "8 ";
    Pole_1[0][9] = "I";Pole_1[9][0] = "9 ";
    Pole_1[0][10] = "J";Pole_1[10][0] = "10";

    Pole_2[0][0] = "  ";
    Pole_2[0][1] = "A";Pole_2[1][0] = "1 ";
    Pole_2[0][2] = "B";Pole_2[2][0] = "2 ";
    Pole_2[0][3] = "C";Pole_2[3][0] = "3 ";
    Pole_2[0][4] = "D";Pole_2[4][0] = "4 ";
    Pole_2[0][5] = "E";Pole_2[5][0] = "5 ";
    Pole_2[0][6] = "F";Pole_2[6][0] = "6 ";
    Pole_2[0][7] = "G";Pole_2[7][0] = "7 ";
    Pole_2[0][8] = "H";Pole_2[8][0] = "8 ";
    Pole_2[0][9] = "I";Pole_2[9][0] = "9 ";
    Pole_2[0][10] = "J";Pole_2[10][0] = "10";

    Pole_1_zapiska[0][0] = "  ";
    Pole_1_zapiska[0][1] = "A";Pole_1_zapiska[1][0] = "1 ";
    Pole_1_zapiska[0][2] = "B";Pole_1_zapiska[2][0] = "2 ";
    Pole_1_zapiska[0][3] = "C";Pole_1_zapiska[3][0] = "3 ";
    Pole_1_zapiska[0][4] = "D";Pole_1_zapiska[4][0] = "4 ";
    Pole_1_zapiska[0][5] = "E";Pole_1_zapiska[5][0] = "5 ";
    Pole_1_zapiska[0][6] = "F";Pole_1_zapiska[6][0] = "6 ";
    Pole_1_zapiska[0][7] = "G";Pole_1_zapiska[7][0] = "7 ";
    Pole_1_zapiska[0][8] = "H";Pole_1_zapiska[8][0] = "8 ";
    Pole_1_zapiska[0][9] = "I";Pole_1_zapiska[9][0] = "9 ";
    Pole_1_zapiska[0][10] = "J";Pole_1_zapiska[10][0] = "10";

    Pole_2_zapiska[0][0] = "  ";
    Pole_2_zapiska[0][1] = "A";Pole_2_zapiska[1][0] = "1 ";
    Pole_2_zapiska[0][2] = "B";Pole_2_zapiska[2][0] = "2 ";
    Pole_2_zapiska[0][3] = "C";Pole_2_zapiska[3][0] = "3 ";
    Pole_2_zapiska[0][4] = "D";Pole_2_zapiska[4][0] = "4 ";
    Pole_2_zapiska[0][5] = "E";Pole_2_zapiska[5][0] = "5 ";
    Pole_2_zapiska[0][6] = "F";Pole_2_zapiska[6][0] = "6 ";
    Pole_2_zapiska[0][7] = "G";Pole_2_zapiska[7][0] = "7 ";
    Pole_2_zapiska[0][8] = "H";Pole_2_zapiska[8][0] = "8 ";
    Pole_2_zapiska[0][9] = "I";Pole_2_zapiska[9][0] = "9 ";
    Pole_2_zapiska[0][10] = "J";Pole_2_zapiska[10][0] = "10";


    for (int i = 1 ; i < 11 ; i++){
        for (int j = 1;j<11;j++){
            Pole_1[i][j] = "O";
            Pole_2[i][j] = "O";
            Pole_1_zapiska[i][j] = "0";
            Pole_2_zapiska[i][j] = "0";
        }
    }
    cout<<"choose type of game:"<<endl;
    cout<<"-->Playing with player ---> enter '1'"<<endl;
    cout<<"-->Playing with computer ---> enter '2'"<<endl;
    cout<<"-->Playing with smart computer with using(Manhattan distance) ---> enter '3'";
    int comp_or_player;
    cin>>comp_or_player;
    //ПОЧАТОК ГРИ
    //ПОЧАТОК ГРИ
    //ПОЧАТОК ГРИ
    //ПОЧАТОК ГРИ
    //ПОЧАТОК ГРИ
    if(comp_or_player ==1){
        //Гравець номер 1 обирає де поставити свій корабель на полі
        int letter_coordinate_0_p_1 ;
        string position_0_p_1 ;
        //Перевірка на коректність введеної букви на полі
        while (true) {
            cout<<"Player_1 input the letter position of your ship A-J:"<<endl;
            cin >> position_0_p_1;
            letter_coordinate_0_p_1 = prepare(position_0_p_1);
            if (is_letter_normal(letter_coordinate_0_p_1)){
                break;
            }
        }
        int number_position_0_p_1;
        //Перевірка на коректність введеної координати
        while (true) {
            cout<<"Player_1 input the number position of your ship 1-10:"<<endl;
            cin >> number_position_0_p_1;
            if (is_number_normal(number_position_0_p_1)){
                break;
            }
        }
        //Розміщуємо на полі корабль першого гравця
        Pole_1[number_position_0_p_1][letter_coordinate_0_p_1] = ">";
        pozition_p_1[0] = number_position_0_p_1;
        pozition_p_1[1]=letter_coordinate_0_p_1;
        //Гравець номер 2 обирає де поставити свій корабель на полі
        string position_0_p_2;
        int letter_coordinate_0_p_2 ;
        while (true) {
            cout<<"Player_2 input the letter position of your ship A-J:"<<endl;
            cin >> position_0_p_2;
            letter_coordinate_0_p_2 = prepare(position_0_p_2);
            if (is_letter_normal(letter_coordinate_0_p_2)){
                break;
            }
        }
        int number_position_0_p_2;
        while (true) {
            cout<<"Player_2 input the number position of your ship 1-10:"<<endl;
            cin >> number_position_0_p_2;
            if (is_number_normal(number_position_0_p_2)){
                break;
            }
        }
        Pole_2[number_position_0_p_2][letter_coordinate_0_p_2] = "<";
        pozition_p_2[0]=number_position_0_p_2;
        pozition_p_2[1]=letter_coordinate_0_p_2;

        cout<<endl;
        cout<<"pole of 1 payer"<<endl;
        for (int i = 0;i<11;i++){
            for(int j = 0;j<11;j++){
                cout<<Pole_1[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<"pole of 2 payer"<<endl;
        cout<<endl;
        for (int i = 0;i<11;i++){
            for(int j = 0;j<11;j++){
                cout<<Pole_2[i][j]<<"  ";
            }
            cout<<endl;
        }
        //GAME START
        //GAME START
        //GAME START
        cout<<"THE GAME STARTS"<<endl;
        while (true){
            //Подивитись нотатки чи вистрелити, що обере гравець номер 1 ?
            int hit_or_look_p_1;
            cout<<"Player_1 u wanna to:"<<endl;
            cout<<"--> Hit -->enter '1'"<<endl;
            cout<<"--> Look Notates -->enter '2'"<<endl;
            cout<<"--> Look Your Pole -->enter '3'"<<endl;
            cin>>hit_or_look_p_1;
            if (hit_or_look_p_1==2){
                cout<<"NOTATES OF PLAYER_1"<<endl;
                for (int i = 0 ;i < 11 ;i ++){
                    for (int j = 0 ; j < 11;j++){
                        cout<<Pole_1_zapiska[i][j]<<"  ";
                    }
                    cout<<endl;
                }
            }else{if(hit_or_look_p_1==3){
                    cout<<"POLE OF PLAYER_1"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_1[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
                }}
            //Постріл гравця номер 1
            string letter_p_1;
            int letter_hit_position_p_1;
            cout<<"Player_1 Hit"<<endl;
            bool Player_1_WINS ;

            while(true) {
                while (true) {
                    cout << "Player_1 input the letter position of enemy ship A-J:" << endl;
                    cin >> letter_p_1;
                    letter_hit_position_p_1 = prepare(letter_p_1);
                    if (is_letter_normal(letter_hit_position_p_1)) {
                        break;
                    }
                }
                int number_hit_position_p_1;
                while (true) {
                    cout << "Player_1 input the number position of enemy ship 1-10:" << endl;
                    cin >> number_hit_position_p_1;
                    if (is_number_normal(number_hit_position_p_1)) {
                        break;
                    }
                }
                if (number_hit_position_p_1 == pozition_p_2[0] && letter_hit_position_p_1 == pozition_p_2[1]) {
                    cout << number_hit_position_p_1 << "me" << endl;
                    cout << pozition_p_2[0] << "enemy" << endl;
                    cout << "Player 1 WINS!!!"<<endl;
                    Player_1_WINS = true;
                    break;
                    return 0;
                    exit(0);
                } else {
                    if (position_is_locked(number_hit_position_p_1, letter_hit_position_p_1, Pole_2)) {
                        cout <<"Position is HITED or u are on this position"<<endl;
                        cout<<"Choose another one"<<endl;
                    } else {
                        Pole_2[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                        Pole_1_zapiska[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                        cout << "Player_2 was in radius " << (abs((pozition_p_2[0]-pozition_p_1[0]) )+abs((pozition_p_2[1]-pozition_p_1[1])))<< endl;
                        break;
                    }
                }
            }if (Player_1_WINS){
                break;
                return 0;
            }
            int move_or_look_p_2;
            cout<<"Player_2 u wanna to:"<<endl;
            cout<<"--> Move -->enter '1'"<<endl;
            cout<<"--> Look Notates -->enter '2'"<<endl;
            cout<<"--> Look Your Pole -->enter '3'"<<endl;
            cin>>move_or_look_p_2;
            if (move_or_look_p_2==2){
                cout<<"NOTATES OF PLAYER_2"<<endl;
                for (int i = 0 ;i < 11 ;i ++){
                    for (int j = 0 ; j < 11;j++){
                        cout<<Pole_2_zapiska[i][j]<<"  ";
                    }
                    cout<<endl;
                }
            }else{if(move_or_look_p_2==3){
                    cout<<"POLE OF PLAYER_2"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_2[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
            }}
            //Гравець 2 міняє свою позицію
            string letter_move_p_2;
            int letter_move_position_p_2;
            int number_move_position_p_2;
            cout<<"Player_2 MOVE"<<endl;
            while (true) {
                while (true) {
                    cout << "Player_2 input the letter position to move your ship:" << endl;
                    cin >> letter_move_p_2;
                    letter_move_position_p_2 = prepare(letter_move_p_2);
                    if (is_letter_normal(letter_move_position_p_2)&& (letter_move_position_p_2==pozition_p_2[1]+1||
                    letter_move_position_p_2==pozition_p_2[1]-1 ||letter_move_position_p_2==pozition_p_2[1])) {
                        break;
                    }else{
                        cout<<"ITS TO FAR From U "<<endl;
                    }
                }
                while (true) {
                    cout << "Player_2 input the number of position to move your ship 1-10:" << endl;
                    cin >> number_move_position_p_2;
                    if (is_number_normal(number_move_position_p_2)&&(number_move_position_p_2 == pozition_p_2[0]+1||
                    number_move_position_p_2 == pozition_p_2[0]-1||number_move_position_p_2 == pozition_p_2[0])) {
                        break;
                    }else{
                        cout<<"ITS TO FAR From U or u are on this position"<<endl;
                }
                }
                if (position_is_locked(number_move_position_p_2,letter_move_position_p_2,Pole_2)){
                    cout<<"Position is HITED or u or your enemy are on this position"<<endl;
                    cout<<"ENTER NEW COOrdinates to move"<<endl;
                }else{
                    Pole_2[pozition_p_2[0]][pozition_p_2[1]]="0";
                    Pole_2[number_move_position_p_2][letter_move_position_p_2]="<";
                    pozition_p_2[0]=number_move_position_p_2;
                    pozition_p_2[1]=letter_move_position_p_2;
                    break;
                }}
            //Гравець номер 2 обирає подивитись нотатки чи стріляти
            int hit_or_look_p_2;
            cout<<"Player_2 u wanna to:"<<endl;
            cout<<"--> HIT -->enter '1'"<<endl;
            cout<<"--> Look Notates -->enter '2'"<<endl;
            cout<<"--> Look Your Pole -->enter '3'"<<endl;
            cin>>hit_or_look_p_2;
            if (hit_or_look_p_2==2){
                cout<<"NOTATES OF PLAYER_2"<<endl;
                for (int i = 0 ;i < 11 ;i ++){
                    for (int j = 0 ; j < 11;j++){
                        cout<<Pole_2_zapiska[i][j]<<"  ";
                    }
                    cout<<endl;
                }
            }else{if(hit_or_look_p_2==3){
                    cout<<"POLE OF PLAYER_2"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_2[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
                }}
            //Гравець номер 2 обирає куди стріляти
            string letter_p_2;
            int letter_hit_position_p_2;
            cout<<"Player_2 HITS!"<<endl;
            bool Player_2_wins;
            while (true) {
                while (true) {
                    cout << "Player_2 input the letter position of enemy ship A-J:" << endl;
                    cin >> letter_p_2;
                    letter_hit_position_p_2 = prepare(letter_p_2);
                    if (is_letter_normal(letter_hit_position_p_2)) {
                        break;

                    }
                }
                int number_hit_position_p_2;
                while (true) {
                    cout << "Player_2 input the number position of enemy ship 1-10:" << endl;
                    cin >> number_hit_position_p_2;
                    if (is_number_normal(number_hit_position_p_2)) {
                        break;
                    }
                }
                //Гравець 2 стріляє
                if (number_hit_position_p_2 == pozition_p_1[0] && letter_hit_position_p_2 == pozition_p_1[1]) {
                    cout << "Player 2 WINS!!!"<<endl;
                    Player_2_wins = true;
                    return 0;
                    break;
                    break;
                    exit(0);
                } else {if(position_is_locked(number_hit_position_p_2,letter_hit_position_p_2,Pole_1)){
                    cout<<"Position is HITED or u are on this position"<<endl;
                }else{
                    Pole_1[number_hit_position_p_2][letter_hit_position_p_2] = "1";
                    Pole_2_zapiska[number_hit_position_p_2][letter_hit_position_p_2] = "1";
                    cout << "Player_1 was in radius " <<(abs((pozition_p_2[0]-pozition_p_1[0]) )+abs((pozition_p_2[1]-pozition_p_1[1]))) << endl;
                        break;
                }}
            }
            if (Player_2_wins){
                break;
                return 0;
            }
            //Гравець 1 думає міняти позицію чи дивитись нотатки
            int move_or_look_p_1;
            cout<<"Player_1 u wanna to:"<<endl;
            cout<<"--> Move -->enter '1'"<<endl;
            cout<<"--> Look Notates -->enter '2'"<<endl;
            cout<<"--> Look Your Pole -->enter '3'"<<endl;
            cin>>move_or_look_p_1;
            if (move_or_look_p_1==2){
                cout<<"NOTATES OF PLAYER_1"<<endl;
                for (int i = 0 ;i < 11 ;i ++){
                    for (int j = 0 ; j < 11;j++){
                        cout<<Pole_1_zapiska[i][j]<<"  ";
                    }
                    cout<<endl;
                }
            }else{if(move_or_look_p_1==3){
                    cout<<"POLE OF PLAYER_1"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_1[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
                }}
            //Гравець 1 міняє свою позицію
            string letter_move_p_1;
            int letter_move_position_p_1;
            int number_move_position_p_1;
            cout<<"Player_1 MOVE"<<endl;
            while (true){
                while (true) {
                    cout << "Player_1 input the letter position to move your ship:" << endl;
                    cin >> letter_move_p_1;
                    letter_move_position_p_1 = prepare(letter_move_p_1);
                    if (is_letter_normal(letter_move_position_p_1)&& (letter_move_position_p_1==pozition_p_1[1]+1||letter_move_position_p_1==pozition_p_1[1]-1||letter_move_position_p_1==pozition_p_1[1])) {
                        break;
                    }else{
                        cout<<"ITS TO FAR From U "<<endl;
                    }
                }
                while (true) {
                    cout << "Player_1 input the number of position to move your ship 1-10:" << endl;
                    cin >> number_move_position_p_1;
                    if (is_number_normal(number_move_position_p_1)&&(number_move_position_p_1 == pozition_p_1[0]+1||number_move_position_p_1 == pozition_p_1[0]-1||number_move_position_p_1 == pozition_p_1[0])) {
                        break;
                    }else{
                        cout<<"ITS TOO FAR From U or u are on this position"<<endl;
                    }
            }
                if (position_is_locked(number_move_position_p_1,letter_move_position_p_1,Pole_1)){
                    cout<<"Position is HITED or u or your enemy are on this position"<<endl;
                    cout<<"ENTER NEW COOrdinates to move"<<endl;
                }else{
                    Pole_1[pozition_p_1[0]][pozition_p_1[1]]="0";
                    Pole_1[number_move_position_p_1][letter_move_position_p_1]=">";
                    pozition_p_1[0]=number_move_position_p_1;
                    pozition_p_1[1]=letter_move_position_p_1;
                    break;
                }
        }
    }
    }
    else{if(comp_or_player==2){
            //Гравець обирає де розташувати свій корабль
            int letter_coordinate_0_p_1 ;
            string position_0_p_1 ;
            //Перевірка на коректність введенної букви на полі
            while (true) {
                cout<<"Player_1 input the letter position of your ship A-J:"<<endl;
                cin >> position_0_p_1;
                letter_coordinate_0_p_1 = prepare(position_0_p_1);
                if (is_letter_normal(letter_coordinate_0_p_1)){
                    break;
                }
            }
            int number_position_0_p_1;
            //Перевірка на коректність введенної координати
            while (true) {
                cout<<"Player_1 input the number position of your ship 1-10:"<<endl;
                cin >> number_position_0_p_1;
                if (is_number_normal(number_position_0_p_1)){
                    break;
                }
            }
            //Розташовуємо корабль гравця
            Pole_1[number_position_0_p_1][letter_coordinate_0_p_1] = ">";
            pozition_p_1[0] = number_position_0_p_1;
            pozition_p_1[1]=letter_coordinate_0_p_1;
            //Комп'ютер рандомно встановлює позицію свого корабля
            int number_pos_0_comp= (rand()%10)+1;
            int let_pos_o_comp = (rand()%10)+1;
            Pole_2[number_pos_0_comp][let_pos_o_comp] = "<";
            pozition_p_2[0] = number_pos_0_comp;
            pozition_p_2[1]=let_pos_o_comp;
//            cout<<number_to_letter(number_pos_0_comp)<<let_pos_o_comp<<"<-- Position of Computer"<<endl;
            cout<<"pole of 1 payer"<<endl;
            for (int i = 0;i<11;i++){
                for(int j = 0;j<11;j++){
                    cout<<Pole_1[i][j]<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<"pole of 2 payer"<<endl;
            cout<<endl;
            for (int i = 0;i<11;i++){
                for(int j = 0;j<11;j++){
                    cout<<Pole_2[i][j]<<"  ";
                }
                cout<<endl;
            }
            while(true){
                int hit_or_look_p_1;
                cout<<"Player_1 u wanna to:"<<endl;
                cout<<"--> Hit -->enter '1'"<<endl;
                cout<<"--> Look Notates -->enter '2'"<<endl;
                cout<<"--> Look Your Pole -->enter '3'"<<endl;
                cin>>hit_or_look_p_1;
                if (hit_or_look_p_1==2){
                    cout<<"NOTATES OF PLAYER_1"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_1_zapiska[i][j]<<"  ";
                        }
                        cout<<endl;
                    }
                }else{if(hit_or_look_p_1==3){
                        cout<<"POLE OF PLAYER_1"<<endl;
                        for (int i = 0 ;i < 11 ;i ++){
                            for (int j = 0 ; j < 11;j++){
                                cout<<Pole_1[i][j]<<"  ";
                            }
                            cout<<endl;
                        }
                    }}
                //Гравець стріляє
                string letter_p_1;
                int letter_hit_position_p_1;
                cout<<"Player_1 Hit"<<endl;
                bool Player_Wins = false;
                while (true) {
                    while (true) {
                        cout << "Player_1 input the letter position of enemy ship A-J:" << endl;
                        cin >> letter_p_1;
                        letter_hit_position_p_1 = prepare(letter_p_1);
                        if (is_letter_normal(letter_hit_position_p_1)) {
                            break;
                        }
                    }
                    int number_hit_position_p_1;

                    while (true) {
                        cout << "Player_1 input the number position of enemy ship 1-10:" << endl;
                        cin >> number_hit_position_p_1;
                        if (is_number_normal(number_hit_position_p_1)) {
                            break;
                        }
                    }
                    if (number_hit_position_p_1 == pozition_p_2[0] && letter_hit_position_p_1 == pozition_p_2[1]) {
                        cout << "Player 1 WINS!!!";
                        Player_Wins= true;
                        return 0;
                        break;
                        break;
                        exit(0);
                    } else {
                        if(position_is_locked(number_hit_position_p_1,letter_hit_position_p_1,Pole_2)){
                        cout<<"Position is HITED or u are on this position"<<endl;
                    }else{
                        Pole_2[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                        Pole_1_zapiska[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                        Pole_1_zapiska[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                        cout << "Player_2 was in radius " << (abs((pozition_p_2[0]-pozition_p_1[0]) )+abs((pozition_p_2[1]-pozition_p_1[1])))<< endl;
                        break;
                    }}
                    break;
                }
                if(Player_Wins){
                    break;
                    return 0;
                }
                //Комп'ютер змінює свою позицію
                while (true){
                    int num_move_coord_comp;
                    while (true){
                    num_move_coord_comp = rand()%10+1;
                    if (is_number_normal(num_move_coord_comp)&&(num_move_coord_comp == pozition_p_2[0]+1||num_move_coord_comp == pozition_p_2[0]-1||num_move_coord_comp == pozition_p_2[0])){
                        break;
                    }}
                    int let_move_coord_comp;
                    while (true) {
                        let_move_coord_comp = rand() % 10 + 1;
                        if (is_letter_normal(let_move_coord_comp)&& (let_move_coord_comp==pozition_p_2[1]+1||let_move_coord_comp==pozition_p_2[1]-1||let_move_coord_comp==pozition_p_2[1])){
                            break;
                        }
                    }
                    if (position_is_locked(num_move_coord_comp,let_move_coord_comp,Pole_2)){
                        continue;
                    }else{
                        Pole_2[pozition_p_2[0]][pozition_p_2[1]]="0";
                        Pole_2[num_move_coord_comp][let_move_coord_comp]="<";
                        pozition_p_2[0]=num_move_coord_comp;
                        pozition_p_2[1]=let_move_coord_comp;
                        break;}}
                //Комп'ютер стріляє
                cout<<"Computer HITS!!! ON"<<endl;
                bool Computer_Wins = false ;
                while(true){
                    int num_hit_coord_comp = rand()%10+1;
                    int let_hit_coord_comp = rand()%10+1;
                    if (not position_is_locked(num_hit_coord_comp,let_hit_coord_comp,Pole_1)){
                        cout<<number_to_letter(let_hit_coord_comp)<<num_hit_coord_comp<<endl;

                        if (Pole_1[num_hit_coord_comp][let_hit_coord_comp] ==">"){
                            cout<<"Computer WINS!!!!"<<endl;
                            Computer_Wins= true;
                            return 0;
                            break;
                        }else{
                        Pole_1[num_hit_coord_comp][let_hit_coord_comp] = "1";
                        Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                        Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                        break;
                    }}
                }
                if (Computer_Wins){
                    break;
                    return 0;
                }
                //Гравець змінює свою позицію
                int move_or_look_p_1;
                cout<<"Player_1 u wanna to:"<<endl;
                cout<<"--> Move -->enter '1'"<<endl;
                cout<<"--> Look Notates -->enter '2'"<<endl;
                cout<<"--> Look Your Pole -->enter '3'"<<endl;
                cin>>move_or_look_p_1;
                if (move_or_look_p_1==2){
                    cout<<"NOTATES OF PLAYER_1"<<endl;
                    for (int i = 0 ;i < 11 ;i ++){
                        for (int j = 0 ; j < 11;j++){
                            cout<<Pole_1_zapiska[i][j]<<"  ";
                        }
                        cout<<endl;
                    }}
                string letter_move_p_1;
                int letter_move_position_p_1;
                int number_move_position_p_1;
                cout<<"Player_1 MOVE"<<endl;
                while (true){
                    while (true) {
                        cout << "Player_1 input the letter position to move your ship:" << endl;
                        cin >> letter_move_p_1;
                        letter_move_position_p_1 = prepare(letter_move_p_1);
                        if (is_letter_normal(letter_move_position_p_1)&& (letter_move_position_p_1==pozition_p_1[1]+1||letter_move_position_p_1==pozition_p_1[1]-1||letter_move_position_p_1==pozition_p_1[1])) {
                            break;
                        }else{
                            cout<<"ITS TO FAR From U "<<endl;
                        }
                    }
                    while (true) {
                        cout << "Player_1 input the number of position to move your ship 1-10:" << endl;
                        cin >> number_move_position_p_1;
                        if (is_number_normal(number_move_position_p_1)&&(number_move_position_p_1 == pozition_p_1[0]+1||number_move_position_p_1 == pozition_p_1[0]-1||number_move_position_p_1 == pozition_p_1[0])) {
                            break;
                        }else{
                            cout<<"ITS TOO FAR From U or u are on this position"<<endl;
                        }
                    }
                    if (position_is_locked(number_move_position_p_1,letter_move_position_p_1,Pole_1)){
                        cout<<"Position is HITED or u or your enemy are on this position"<<endl;
                        cout<<"ENTER NEW COOrdinates to move"<<endl;
                    }else{
                        Pole_1[pozition_p_1[0]][pozition_p_1[1]]="0";
                        Pole_1[number_move_position_p_1][letter_move_position_p_1]=">";
                        pozition_p_1[0]=number_move_position_p_1;
                        pozition_p_1[1]=letter_move_position_p_1;
                        break;
                    }
                }
            }
    }
        else{ if (comp_or_player==3){
            while(true) {
                int player_prev_pos[2];
                player_prev_pos[0] = 0;
                player_prev_pos[1] = 0;
                int radius =0;
                while (true) {
                    int letter_coordinate_0_p_1;
                    string position_0_p_1;
                    //Перевірка на коректність введенної букви на полі
                    while (true) {
                        cout << "Player_1 input the letter position of your ship A-J:" << endl;
                        cin >> position_0_p_1;
                        letter_coordinate_0_p_1 = prepare(position_0_p_1);
                        if (is_letter_normal(letter_coordinate_0_p_1)) {
                            break;
                        }
                    }
                    int number_position_0_p_1;
                    //Перевірка на коректність введенної координати
                    while (true) {
                        cout << "Player_1 input the number position of your ship 1-10:" << endl;
                        cin >> number_position_0_p_1;
                        if (is_number_normal(number_position_0_p_1)) {
                            break;
                        }
                    }
                    //Росташовуємл корабль гравця
                    Pole_1[number_position_0_p_1][letter_coordinate_0_p_1] = ">";
                    pozition_p_1[0] = number_position_0_p_1;
                    pozition_p_1[1] = letter_coordinate_0_p_1;
                    //Комп'ютер рандомно встановлює позицію свого корабля
                    int number_pos_0_comp = (rand() % 10) + 1;
                    int let_pos_o_comp = (rand() % 10) + 1;

                    Pole_2[number_pos_0_comp][let_pos_o_comp] = "<";
                    pozition_p_2[0] = number_pos_0_comp;
                    pozition_p_2[1] = let_pos_o_comp;
                    if (pozition_p_1[0] == pozition_p_2[0] && pozition_p_1[1] == pozition_p_2[1]) {
//                        cout<<number_to_letter(number_pos_0_comp)<<let_pos_o_comp<<"<-- Position of Computer"<<endl;
                        cout<<"pole of 1 payer"<<endl;
                        for (int i = 0;i<11;i++){
                            for(int j = 0;j<11;j++){
                                cout<<Pole_1[i][j]<<"  ";
                            }
                            cout<<endl;
                        }
                        cout<<endl;
                        cout<<"pole of 2 payer"<<endl;
                        cout<<endl;
                        for (int i = 0;i<11;i++){
                            for(int j = 0;j<11;j++){
                                cout<<Pole_2[i][j]<<"  ";
                            }
                            cout<<endl;
                        }
                    } else {
                        break;
                    }
                }
                while (true) {
                    int hit_or_look_p_1;
                    cout << "Player_1 u wanna to:" << endl;
                    cout << "--> Hit -->enter '1'" << endl;
                    cout << "--> Look Notates -->enter '2'" << endl;
                    cout << "--> Look Your Pole -->enter '3'" << endl;
                    cin >> hit_or_look_p_1;
                    if (hit_or_look_p_1 == 2) {
                        cout << "NOTATES OF PLAYER_1" << endl;
                        for (int i = 0; i < 11; i++) {
                            for (int j = 0; j < 11; j++) {
                                cout << Pole_1_zapiska[i][j] << "  ";
                            }
                            cout << endl;
                        }
                    } else {
                        if (hit_or_look_p_1 == 3) {
                            cout << "POLE OF PLAYER_1" << endl;
                            for (int i = 0; i < 11; i++) {
                                for (int j = 0; j < 11; j++) {
                                    cout << Pole_1[i][j] << "  ";
                                }
                                cout << endl;
                            }
                        }
                    }
                    //Гравець стріляє
                    string letter_p_1;
                    int letter_hit_position_p_1;
                    cout << "Player_1 Hit" << endl;
                    bool Player_Wins = false;
                    while (true) {
                        while (true) {
                            cout << "Player_1 input the letter position of enemy ship A-J:" << endl;
                            cin >> letter_p_1;
                            letter_hit_position_p_1 = prepare(letter_p_1);
                            if (is_letter_normal(letter_hit_position_p_1)) {
                                break;
                            }
                        }
                        int number_hit_position_p_1;

                        while (true) {
                            cout << "Player_1 input the number position of enemy ship 1-10:" << endl;
                            cin >> number_hit_position_p_1;
                            if (is_number_normal(number_hit_position_p_1)) {
                                break;
                            }
                        }
                        if (number_hit_position_p_1 == pozition_p_2[0] && letter_hit_position_p_1 == pozition_p_2[1]) {
                            cout << "Player 1 WINS!!!";
                            Player_Wins = true;
                            return 0;
                            break;
                            break;
                            exit(0);
                        } else {
                            if (position_is_locked(number_hit_position_p_1, letter_hit_position_p_1, Pole_2)) {
                                cout << "Position is HITED or u are on this position" << endl;
                            } else {
                                Pole_2[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                                Pole_1_zapiska[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                                Pole_1_zapiska[number_hit_position_p_1][letter_hit_position_p_1] = "1";
                                cout << "Player_2 was in radius " << (abs((pozition_p_2[0]-pozition_p_1[0]) )+abs((pozition_p_2[1]-pozition_p_1[1]))) << endl;
                                break;
                            }
                            break;
                        }
                    }
                    if (Player_Wins) {
                        break;
                        return 0;
                    }
                    //Комп'ютер змінює своє розташування
                    while (true) {
                        int num_move_coord_comp;
                        while (true) {
                            num_move_coord_comp = rand() % 10 + 1;
                            if (is_number_normal(num_move_coord_comp) &&
                                (num_move_coord_comp == pozition_p_2[0] + 1 ||
                                 num_move_coord_comp == pozition_p_2[0] - 1 ||
                                 num_move_coord_comp == pozition_p_2[0])) {
                                break;
                            }
                        }
                        int let_move_coord_comp;
                        while (true) {
                            let_move_coord_comp = rand() % 10 + 1;
                            if (is_letter_normal(let_move_coord_comp) &&
                                (let_move_coord_comp == pozition_p_2[1] + 1 ||
                                 let_move_coord_comp == pozition_p_2[1] - 1 ||
                                 let_move_coord_comp == pozition_p_2[1])) {
                                break;
                            }
                        }
                        if (not position_is_locked(num_move_coord_comp, let_move_coord_comp, Pole_2)) {
                            continue;
                        } else {

                            Pole_2[pozition_p_2[0]][pozition_p_2[1]] = "0";
                            Pole_2[num_move_coord_comp][let_move_coord_comp] = "<";
                            pozition_p_2[0] = num_move_coord_comp;
                            pozition_p_2[1] = let_move_coord_comp;
                            break;
                        }
                    }
                    cout << "Computer HITS!!!" << endl;
                    bool Computer_Wins = false;
                    while (true) {
                        if (radius==0) {
                            cout<<"Random HIT"<<endl;
                            int num_hit_coord_comp = rand() % 10 + 1;
                            int let_hit_coord_comp = rand() % 10 + 1;
                            if (not position_is_locked(num_hit_coord_comp, let_hit_coord_comp, Pole_1)) {
                                cout << number_to_letter(let_hit_coord_comp) << num_hit_coord_comp << endl;

                                if (Pole_1[num_hit_coord_comp][let_hit_coord_comp] == ">") {
                                    cout << num_hit_coord_comp << "  " << let_hit_coord_comp << endl;
                                    cout << "Computer WINS!!!!" << endl;
                                    Computer_Wins = true;
                                    return 0;
                                    break;
                                } else {
                                    Pole_1[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                    Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                    Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                    radius = (abs((pozition_p_2[0]-pozition_p_1[0]) )+abs((pozition_p_2[1]-pozition_p_1[1])));
                                    break;
                                }
                            }
                        } else {
                            int length_rows;
                            int **maybe_pos_of_player= new int *[length_rows];
                            int iter = 0;
                            cout<<"Analiz or distance"<<endl;
                            for (int i = 1; i < 11; i++) {
                                for (int j = 1; j < 11; j++) {
                                    int num_pos = i;
                                    int let_pos = j;
                                    int formula =(abs((pozition_p_2[0]-num_pos) )+abs((pozition_p_2[1]-let_pos)));
                                    if (formula==radius){
                                        cout<<number_to_letter(j)<<i<<endl;
                                        maybe_pos_of_player[iter]=new int [2];
                                        maybe_pos_of_player[iter][0]=i;
                                        maybe_pos_of_player[iter][1]=j;
                                        iter +=1;

                                    }
                                }
                            }

                            while (true) {
                                int point_to_hit[2];
                                int a =rand() % (sizeof maybe_pos_of_player);
                                point_to_hit[0] = maybe_pos_of_player[a][0];
                                point_to_hit[1] = maybe_pos_of_player[a][1];
                                int num_hit_coord_comp;
                                int let_hit_coord_comp;
                                num_hit_coord_comp = point_to_hit[0];
                                let_hit_coord_comp = point_to_hit[1];
                                cout<<"we here"<<endl;
                                if (not position_is_locked(num_hit_coord_comp, let_hit_coord_comp, Pole_1)) {
                                    cout << number_to_letter(let_hit_coord_comp) << num_hit_coord_comp << endl;
                                    if (Pole_1[num_hit_coord_comp][let_hit_coord_comp] == ">") {
                                        cout << num_hit_coord_comp << "  " << let_hit_coord_comp << endl;
                                        cout << "Computer WINS!!!!" << endl;
                                        Computer_Wins = true;
                                        delete [] maybe_pos_of_player;
                                        return 0;
                                        break;
                                    } else {
                                        Pole_1[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                        Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                        Pole_2_zapiska[num_hit_coord_comp][let_hit_coord_comp] = "1";
                                        cout<<number_to_letter(let_hit_coord_comp)<<num_hit_coord_comp<<"<-- Computer Hited"<<endl;
                                        player_prev_pos[0] = pozition_p_1[0];
                                        player_prev_pos[1] = pozition_p_1[1];
                                        delete [] maybe_pos_of_player;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }

                    if (Computer_Wins) {
                        break;
                        return 0;
                    }
                    //Гравець змінює свою позицію
                    int move_or_look_p_1;
                    cout << "Player_1 u wanna to:" << endl;
                    cout << "--> Move -->enter '1'" << endl;
                    cout << "--> Look Notates -->enter '2'" << endl;
                    cout << "--> Look Your Pole -->enter '3'" << endl;
                    cin >> move_or_look_p_1;
                    if (move_or_look_p_1 == 2) {
                        cout << "NOTATES OF PLAYER_1" << endl;
                        for (int i = 0; i < 11; i++) {
                            for (int j = 0; j < 11; j++) {
                                cout << Pole_1_zapiska[i][j] << "  ";
                            }
                            cout << endl;
                        }
                    }else {
                        if (hit_or_look_p_1 == 3) {
                            cout << "POLE OF PLAYER_1" << endl;
                            for (int i = 0; i < 11; i++) {
                                for (int j = 0; j < 11; j++) {
                                    cout << Pole_1[i][j] << "  ";
                                }
                                cout << endl;
                            }
                        }
                    }
                    string letter_move_p_1;
                    int letter_move_position_p_1;
                    int number_move_position_p_1;
                    cout << "Player_1 MOVE" << endl;
                    while (true) {
                        while (true) {
                            cout << "Player_1 input the letter position to move your ship:" << endl;
                            cin >> letter_move_p_1;
                            letter_move_position_p_1 = prepare(letter_move_p_1);
                            if (is_letter_normal(letter_move_position_p_1) &&
                                (letter_move_position_p_1 == pozition_p_1[1] + 1 ||
                                 letter_move_position_p_1 == pozition_p_1[1] - 1 ||
                                 letter_move_position_p_1 == pozition_p_1[1])) {
                                break;
                            } else {
                                cout << "ITS TO FAR From U " << endl;
                            }
                        }
                        while (true) {
                            cout << "Player_1 input the number of position to move your ship 1-10:" << endl;
                            cin >> number_move_position_p_1;
                            if (is_number_normal(number_move_position_p_1) &&
                                (number_move_position_p_1 == pozition_p_1[0] + 1 ||
                                 number_move_position_p_1 == pozition_p_1[0] - 1 ||
                                 number_move_position_p_1 == pozition_p_1[0])) {
                                break;
                            } else {
                                cout << "ITS TOO FAR From U or u are on this position" << endl;
                            }
                        }
                        if (position_is_locked(number_move_position_p_1, letter_move_position_p_1, Pole_1)) {
                            cout << "Position is HITED or u or your enemy are on this position" << endl;
                            cout << "ENTER NEW COOrdinates to move" << endl;
                        } else {
                            Pole_1[pozition_p_1[0]][pozition_p_1[1]] = "0";
                            Pole_1[number_move_position_p_1][letter_move_position_p_1] = ">";
                            pozition_p_1[0] = number_move_position_p_1;
                            pozition_p_1[1] = letter_move_position_p_1;
                            break;
                        }
                    }

                }
            }
            }}}
    return 0;

}