#include <iostream>
#include <stdlib.h>
using namespace std;

char x[10] = {'0','1','2','3','4','5','6','7','8','9'};
int P = 1;

void DrawTable() {
    system("clear");
    cout<<endl<<"\t"<<x[1]<<" | "<<x[2]<<" | "<<x[3]<<"\n\t__________\n\n"<<"\t"<<x[4]<<" | "<<x[5]<<" | "<<x[6]<<"\n\t__________\n\n"<<"\t"<<x[7]<<" | "<<x[8]<<" | "<<x[9]<<endl<<endl;
}
void markPlayer(int P) {
    int n;
    cout<<"Player \""<<P<<"\" ,your move: ";
    cin>>n;
    while (n <= 0 || n >= 10) {
        cout<<"Wrong move, choose another move: ";
        cin>>n;
    }
    while (x[n] == 'X' || x[n] == 'O') {
        cout<<"You can't move here, choose another place.\nYour move: ";
        cin>>n;
    }

    if (P == 1) {
        x[n] = 'X';
    }
    else if (P == 2){
        x[n] = 'O';
    }
}
int changePlayer() {
    if (P==1) {
        P = 2;
    }
    else if (P == 2) {
        P = 1;
    }
    return P;
}
char checkWiner() {
    char win;
    if (x[1]=='X' && x[2]=='X' && x[3]=='X' || x[4]=='X'&& x[5]=='X'&& x[6]=='X' || x[7]=='X'&& x[8]=='X'&& x[9]=='X' || x[1]=='X'&& x[4]=='X'&& x[7]=='X' || x[2]=='X' && x[5]=='X' && x[8]=='X' || x[3]=='X' && x[6]=='X' && x[9]=='X' || x[1]=='X' && x[5]=='X' && x[9]=='X' || x[3]=='X' && x[5]=='X' && x[7]=='X') {
        win = '1';
    }
    else if (x[1]=='O' && x[2]=='O' && x[3]=='O' || x[4]=='O'&& x[5]=='O'&& x[6]=='O' || x[7]=='O'&& x[8]=='O'&& x[9]=='O' || x[1]=='O'&& x[4]=='O'&& x[7]=='O' || x[2]=='O' && x[5]=='O' && x[8]=='O' || x[3]=='O' && x[6]=='O' && x[9]=='O' || x[1]=='O' && x[5]=='O' && x[9]=='O' || x[3]=='O' && x[5]=='O' && x[7]=='O') {
        win = '2';
    }
    else if (x[1]!='1' && x[2]!='2' && x[3]!='3' && x[4]!='4' && x[5]!='5' && x[6]!='6' && x[7]!='7' && x[8]!='8' && x[9]!='9') {
        win = '0';
    }
    return win;
}

int main() {
    PlayAgain:
    system("clear");
    cout<<"Hi ,this is my \"X_O\" Game, enjoy it!\n";
    DrawTable();
    while (true) {
        markPlayer(P);
        changePlayer();
        DrawTable();
        if (checkWiner() == '1') {
            cout<<"Player 1 is the winner!\n\n";
            break;
        }
        else if (checkWiner() == '2')
        {
            cout<<"Player 2 is the winner!\n\n";
            break;
        }
        else if (checkWiner() == '0') {
            cout<<"No win, No lose!\n\n";
            break;
        }
    }
    char yes_no;
    cout<<"Replay (y/n): ";cin>>yes_no;
    if (yes_no == 'y') {
        x[0] = '0';x[1] = '1';x[2] = '2';x[3] = '3';x[4] = '4';x[5] = '5';x[6] = '6';x[7] = '7';x[8] = '8';x[9] = '9';
        P = 1;
        goto PlayAgain;
    }
    else {
        system("clear");
        cout<<"Thank you!"<<endl;
    }
    

    return 0;
}


