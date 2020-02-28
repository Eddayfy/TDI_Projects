#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

char T[10] = {'A','B','C','D','E','F','G','H','I','J'},Ncrushlenght;
int crushlenght;
string crush;

char intTOchar(int x) {
    char ch;
    if (x == 1) {
        ch = '1';
    }
    else if (x == 2) {
        ch = '2';
    }
    else if (x == 3) {
        ch = '3';
    }
    else if (x == 4) {
        ch = '4';
    }
    else if (x == 5) {
        ch = '5';
    }
    else if (x == 6) {
        ch = '6';
    }
    else if (x == 7) {
        ch = '7';
    }
    else if (x == 8) {
        ch = '8';
    }
    else if (x == 9) {
        ch = '9';
    }
    else if (x == 0) {
        ch = '0';
    }
    return ch;
}
void draw() {
    cout<<" ----------- -------- ----------- --------- -------- "<<endl;
    cout<<"|   Fira9   |  Korh  |   Zawaj   |  Tafkir |   7ob  |\n";
    cout<<"|-----------+--------+-----------+---------+--------|"<<endl;
    cout<<"|    "<< T[0] <<"      |    "<< T[1] <<"   |     "<< T[2] <<"     |    "<< T[3] <<"    |    "<< T[4] <<"   |"<<endl;
    cout<<"|-----------+--------+-----------+---------+--------|"<<endl;
    cout<<"|    "<< T[5] <<"      |    "<< T[6] <<"   |     "<< T[7] <<"     |    "<< T[8] <<"    |    "<< T[9] <<"   |"<<endl;
    cout<<" -----------+--------+-----------+---------+-------- "<<endl<<endl;
}
void askUser(int i) {
    rj3:
    cout<<"Ktab ra9m fi blasst "<<T[i]<<": ";
    cin>>T[i];
    for (int c = 0; c < i; c++) {
        if (T[i] == T[c]) {
            cout<<"Fayt lak mdakhl had ra9m, dakhl wahed akher."<<endl;
            goto rj3;
        }
    }
    
    system("clear");
}
void result() {
    system("clear");
    cout<<"Dakhle Smiya dyal Crush: ";
    cin>>crush;
    crushlenght = crush.size();
    Ncrushlenght = intTOchar(crushlenght);

    draw();

    if(Ncrushlenght == T[0] || Ncrushlenght == T[5]) {
        cout<<"Ghadin tfar9o.\n";
    }
    else if(Ncrushlenght == T[1] || Ncrushlenght == T[6]) {
        cout<<"L'crush ma kihamlkch.\n";
    }
    else if(Ncrushlenght == T[2] || Ncrushlenght == T[7]) {
        cout<<"Mabrouk 3likoum, ghadin tzawjo.\n";
    }
    else if(Ncrushlenght == T[3] || Ncrushlenght == T[8]) {
        cout<<"L'crush ki faker fuk.\n";
    }
    else if(Ncrushlenght == T[4] || Ncrushlenght == T[9]) {
        cout<<"L'crush kaybghik.\n";
    }
    else {
        cout<<"yamkn smiya mamktoubach mzyan./n";
        result();
    }
}

int main() {
    system("clear");
    for(int i = 0;i<10;i++) {
        draw();
        askUser(i);
    }
    result();
    return 0;
}

