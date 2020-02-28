#include<iostream>
#include<conio.h>

using namespace std;

int table_width = 30,table_height = 15,Sheadx = table_width/2,Sheady = table_height/2,Score = -1,fruitx,fruity,Snake_Tail = 0,Snake_Tail_x[30],Snake_Tail_y[30];
char head = '>',c;

void Shift_Right(int arr[], int size) {
    for (int i = size - 2; i >= 0; i--) {
        arr[i+1] = arr[i];
    }   
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
        if (c == 120) {
            c = 'x';
        }
        else if (c == '\033') {
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
    else if (c == 'p') {
        system("read");
    }
    else if (c == 'x') {
        exit(0);
    } 

    Shift_Right(Snake_Tail_x,30);
    Shift_Right(Snake_Tail_y,30);
    Snake_Tail_x[0] = Sheadx;
    Snake_Tail_y[0] = Sheady;

    if (Sheadx == fruitx && Sheady == fruity) {
        Score++;
        Snake_Tail++;
        Generate_Fruit();
    }
}
void Check_Lose() {
    if (Sheadx == table_width-1 || Sheadx == 0) exit(0);
    else if (Sheady == table_height-1 || Sheady == 0) exit(0);
}

int main() {
    Generate_Fruit();
    while (true) {
        Draw();
        Move();
        Check_Lose();
        system("sleep 0.3");
        system("clear");
    }

    return 0;
}
