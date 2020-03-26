/*

========== funtions List ==========
    ===== Forground color =====
BlackColorfg
RedColorfg
GreenColorfg
YellowColorfg
BlueColorfg
MegentaColorfg
CyanColorfg
WhiteColorfg

    ===== Background color =====
BlackColorbg
RedColorbg
GreenColorbg
YellowColorbg
BlueColorbg
MegentaColorbg
CyanColorbg
WhiteColorbg

    ===== Change Type ====
charTOint
charTOfloat
charTOdouble
stringTOint
stringTOfloat
stringTOdouble
strTOint
strTOfloat
strTOdouble
intTOchar

*/

/*
    ===== Run this Example to use my HeaderFile =====

include<iostream>
include<eddayfy.h>
int main() {
    BlackColorfg("Black");
    cout<<endl;
    RedColorfg("Red");
    cout<<endl;
    GreenColorfg("Green");
    cout<<endl;
    YellowColorfg("Yellow");
    cout<<endl;
    BlueColorfg("Blue");
    cout<<endl;
    MegentaColorfg("Megenta");
    cout<<endl;
    CyanColorfg("Cyan");
    cout<<endl;
    WhiteColorfg("White");
    cout<<endl;

    BlackColorbg("Black");
    cout<<endl;
    RedColorbg("Red");
    cout<<endl;
    GreenColorbg("Green");
    cout<<endl;
    YellowColorbg("Yellow");
    cout<<endl;
    BlueColorbg("Blue");
    cout<<endl;
    MegentaColorbg("Megenta");
    cout<<endl;
    CyanColorbg("Cyan");
    cout<<endl;
    WhiteColorbg("White");
    cout<<endl;

    return 0;
}


*/


#include<iostream>
#include<string.h>
using namespace std;

class Print {
private:
    
public:
    Print() {}
    ~Print() {}
    void BlackColorfg(string str) {
        cout<<"\u001b["<<30<<"m"<<str<<"\u001b[0m";
    }
    void RedColorfg(string str) {
        cout<<"\u001b["<<31<<"m"<<str<<"\u001b[0m";
    }
    void GreenColorfg(string str) {
        cout<<"\u001b["<<32<<"m"<<str<<"\u001b[0m";
    }
    void YellowColorfg(string str) {
        cout<<"\u001b["<<33<<"m"<<str<<"\u001b[0m";
    }
    void BlueColorfg(string str) {
        cout<<"\u001b["<<34<<"m"<<str<<"\u001b[0m";
    }
    void MegentaColorfg(string str) {
        cout<<"\u001b["<<35<<"m"<<str<<"\u001b[0m";
    }
    void CyanColorfg(string str) {
        cout<<"\u001b["<<36<<"m"<<str<<"\u001b[0m";
    }
    void WhiteColorfg(string str) {
        cout<<"\u001b["<<37<<"m"<<str<<"\u001b[0m";
    }

    void BlackColorbg(string str) {
        cout<<"\u001b["<<40<<"m"<<str<<"\u001b[0m";
    }
    void RedColorbg(string str) {
        cout<<"\u001b["<<41<<"m"<<str<<"\u001b[0m";
    }
    void GreenColorbg(string str) {
        cout<<"\u001b["<<42<<"m"<<str<<"\u001b[0m";
    }
    void YellowColorbg(string str) {
        cout<<"\u001b["<<43<<"m"<<str<<"\u001b[0m";
    }
    void BlueColorbg(string str) {
        cout<<"\u001b["<<44<<"m"<<str<<"\u001b[0m";
    }
    void MegentaColorbg(string str) {
        cout<<"\u001b["<<45<<"m"<<str<<"\u001b[0m";
    }
    void CyanColorbg(string str) {
        cout<<"\u001b["<<66<<"m"<<str<<"\u001b[0m";
    }
    void WhiteColorbg(string str) {
        cout<<"\u001b["<<47<<"m"<<str<<"\u001b[0m";
    }

    int charTOint(char chr) {
        switch (chr) {
            case '0':
                return 0;
                break;
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            case '7':
                return 7;
                break;
            case '8':
                return 8;
                break;
            case '9':
                return 9;
                break;
            default:
                return -1;
                break;
        }
    }
    float charTOfloat(char chr) {
        switch (chr) {
            case '0':
                return 0;
                break;
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            case '7':
                return 7;
                break;
            case '8':
                return 8;
                break;
            case '9':
                return 9;
                break;
            default:
                return -1;
                break;
        }
    }
    double charTOdouble(char chr) {
        switch (chr) {
            case '0':
                return 0;
                break;
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            case '4':
                return 4;
                break;
            case '5':
                return 5;
                break;
            case '6':
                return 6;
                break;
            case '7':
                return 7;
                break;
            case '8':
                return 8;
                break;
            case '9':
                return 9;
                break;
                    default:
                return -1;
                break;
        }
    }
    int stringTOint(string str) {
        int temp = 1,nbr;

        for(int i = 1 ; i < str.size() ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < str.size() ; i++) {
            nbr = nbr + charTOint(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    float stringTOfloat(string str) {
        float temp = 1,nbr;

        for(int i = 1 ; i < str.size() ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < str.size() ; i++) {
            nbr = nbr + charTOfloat(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    double stringTOdouble(string str) {
        double temp = 1,nbr;

        for(int i = 1 ; i < str.size() ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < str.size() ; i++) {
            nbr = nbr + charTOdouble(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    int strTOint(char str[]) {
        int temp = 1,nbr;

        for(int i = 1 ; i < strlen(str) ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < strlen(str) ; i++) {
            nbr = nbr + charTOint(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    float strTOfloat(char str[]) {
        float temp = 1,nbr;

        for(int i = 1 ; i < strlen(str) ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < strlen(str) ; i++) {
            nbr = nbr + charTOfloat(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    double strTOdouble(char str[]) {
        double temp = 1,nbr;

        for(int i = 1 ; i < strlen(str) ; i++) {
            temp = temp * 10;
        }
        for(int i = 0 ; i < strlen(str) ; i++) {
            nbr = nbr + charTOdouble(str[i])*temp;
            temp = temp/10;
        }
        return nbr;
    }
    char intTOchar(int INT) {
        switch (INT) {
            case 0:
                return '0';
                break;
            case 1:
                return '1';
                break;
            case 2:
                return '2';
                break;
            case 3:
                return '3';
                break;
            case 4:
                return '4';
                break;
            case 5:
                return '5';
                break;
            case 6:
                return '6';
                break;
            case 7:
                return '7';
                break;
            case 8:
                return '8';
                break;
            case 9:
                return '9';
                break;
            default:
                return -1;
                break;
        }
    }

}P;

#define BlackColorfg P.BlackColorfg
#define RedColorfg P.RedColorfg
#define GreenColorfg P.GreenColorfg
#define YellowColorfg P.YellowColorfg
#define BlueColorfg P.BlueColorfg
#define MegentaColorfg P.MegentaColorfg
#define CyanColorfg P.CyanColorfg
#define WhiteColorfg P.WhiteColorfg

#define BlackColorbg P.BlackColorbg
#define RedColorbg P.RedColorbg
#define GreenColorbg P.GreenColorbg
#define YellowColorbg P.YellowColorbg
#define BlueColorbg P.BlueColorbg
#define MegentaColorbg P.MegentaColorbg
#define CyanColorbg P.CyanColorbg
#define WhiteColorbg P.WhiteColorbg


#define charTOint P.charTOint
#define charTOfloat P.charTOfloat
#define charTOdouble P.charTOdouble
#define stringTOint P.stringTOint
#define stringTOfloat P.stringTOfloat
#define stringTOdouble P.stringTOdouble
#define strTOint P.strTOint
#define strTOfloat P.strTOfloat
#define strTOdouble P.strTOdouble
#define intTOchar P.intTOchar
