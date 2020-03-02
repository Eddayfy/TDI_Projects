#include<iostream>
#include</home/eddayfy/Documents/C++/Snake_Game/conio.h>

using namespace std;

int table_width = 30,table_height = 15,Sheadx = table_width/2,Sheady = table_height/2,Score = 0,fruitx,fruity,Snake_Tail = 0,Snake_Tail_x[100],Snake_Tail_y[100];
char head = '>',c;

void Move_Tail() {
    for (int i = Snake_Tail; i >= 0; i--) {
        Snake_Tail_x[i] = Snake_Tail_x[i-1];
        Snake_Tail_y[i] = Snake_Tail_y[i-1];
    }
    Snake_Tail_x[0] = Sheadx;
    Snake_Tail_y[0] = Sheady;
}
void Generate_Fruit() {
    srand(time(NULL));
    fruitx = rand() % (table_width - 2) + 1;
    fruity = rand() % (table_height - 2) + 1;
}
void Draw() {
    for (int l = 0; l < table_height; l++) {
        for (int c = 0; c < table_width; c++) {
            if (l == 0 || l == table_height-1) cout<<"*";
            else if (c == 0 || c == table_width-1) cout<<"*";
            else if (l == Sheady && c == Sheadx) cout<<head;
            else if (l == fruity && c == fruitx) cout<<"#";
            else {
                bool printed = false;
                for (int z = 0; z < Snake_Tail; z++) {
                    if (Snake_Tail_x[z] == c && Snake_Tail_y[z] == l) {
                        cout<<"o";
                        printed = true;
                        break;
                    }
                }
                if (!printed) cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"Your Score: "<<Score<<endl;
}
void Move() {
    if (_kbhit()) {
        c = getch();
        if (c == '\033') {
            getch();
            switch(getch()) {
            case 'A':
                c = 'w';
                break;
            case 'B':
                c = 's';
                break;
            case 'C':
                c = 'd';
                break;
            case 'D':
                c = 'a';
                break;
            }
        }
    }

    if (c == 'w') {
        Sheady -= 1;
        head = '^';
    }
    else if (c == 'a') {
        Sheadx -= 1;
        head = '<';
    }
    else if (c == 's') {
        Sheady += 1;
        head = 'v';
    }
    else if (c == 'd') {
        Sheadx += 1;
        head = '>';
    }
    else if (c == 'x') {
        exit(0);
    }

    if (Sheadx == fruitx && Sheady == fruity) {
        Score++;
        Snake_Tail++;
        Generate_Fruit();
    }
    Move_Tail();
}
int Check_Lose() {
    if (Sheadx == table_width-1 || Sheadx == 0) return 1;
    else if (Sheady == table_height-1 || Sheady == 0) return 1;
    else {
        for (int i = 1; i < Snake_Tail; i++) {
            if (Sheadx == Snake_Tail_x[i] && Sheady == Snake_Tail_y[i]) return 1;
        }
    }
    return 0;
}

int main() {
    Generate_Fruit();
    while (true) {
        Draw();
        Move();
        if (Check_Lose() == 1) break;
        system("sleep 0.3");
        system("clear");
    }

    return 0;
}
