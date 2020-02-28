#include<iostream>  // ; : ) 0 \ 
#include<string>

using namespace std;

struct Birth {int day,month,year;};
struct Stagier {char First_Name[15],Last_Name[15],Class[10],Code[10];Birth Birth_Day;};

int Nbr_Stgrs = 0;

Stagier *T = NULL;

void Uppload() {
    FILE *index;
    index = fopen("Stagiers.txt","r");
    if (index != NULL) {
        string temp;
        char c;
        c = getc(index);
        while (c != EOF) {
            if (c == '\n') Nbr_Stgrs++;
            temp += c;
            c = getc(index);
        }
        fclose(index);

        struct Births {string day,month,year;};
        struct Stagiers {string First_Name,Last_Name,Class,Code;Births Birth_Day;};
        int p;
        Stagiers *t = NULL;
        t = new Stagiers[Nbr_Stgrs];

        for (int i = 0; i < Nbr_Stgrs;i++) {
            p = temp.find("/");
            t[i].First_Name = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("/");
            t[i].Last_Name = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("/");
            t[i].Class = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("/");
            t[i].Code = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("/");
            t[i].Birth_Day.day = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("/");
            t[i].Birth_Day.month = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);
            p = temp.find("\n");
            t[i].Birth_Day.year = temp.substr(0,p);
            temp = temp.substr(p+1,temp.size()-p);

            for(int x = 0;x<t[i].First_Name.size();x++) T[i].First_Name[x] = t[i].First_Name[x];
            for(int x = 0;x<t[i].Last_Name.size();x++) T[i].Last_Name[x] = t[i].Last_Name[x];
            for(int x = 0;x<t[i].Class.size();x++) T[i].Class[x] = t[i].Class[x];
            for(int x = 0;x<t[i].Code.size();x++) T[i].Code[x] = t[i].Code[x];
            char tempday[2] = "",tempmonth[2] = "",tempyear[4] = "";
            for(int x = 0;x<t[i].Birth_Day.day.size();x++) tempday[x] = t[i].Birth_Day.day[x];
            T[i].Birth_Day.day = atoi(tempday);
            for(int x = 0;x<t[i].Birth_Day.month.size();x++) tempmonth[x] = t[i].Birth_Day.month[x];
            T[i].Birth_Day.month = atoi(tempmonth);
            for(int x = 0;x<t[i].Birth_Day.year.size();x++) tempyear[x] = t[i].Birth_Day.year[x];
            T[i].Birth_Day.year = atoi(tempyear);
        }
        delete [] t;
        t = NULL;
    }
}

void Show() {
    system("clear");
    for (int i = 0; i < Nbr_Stgrs; i++){
        cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
        cout<<"First Name     : "<<T[i].First_Name<<endl;
        cout<<"Last Name      : "<<T[i].Last_Name<<endl;
        cout<<"Class          : "<<T[i].Class<<endl;
        cout<<"Code           : "<<T[i].Code<<endl;
        cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
    }
    char x;cin>>x;
}

void Add() {
    int nbr_stgrs_ajt;

    system("clear");
    cout<<"How many \"Stagier\" you will add it: ";
    cin>>nbr_stgrs_ajt;
    for (int i = Nbr_Stgrs; i < nbr_stgrs_ajt + Nbr_Stgrs; i++){
        system("clear");
        cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
        cout<<"Enter the First Name: ";
        cin>>T[i].First_Name;
        cout<<"Enter the Last Name : ";
        cin>>T[i].Last_Name;
        cout<<"Enter the Class     : ";
        cin>>T[i].Class;
        cout<<"Enter the Code      : ";
        cin>>T[i].Code;
        cout<<"Enter The Birth Day (dd mm yyyy): ";
        cin>>T[i].Birth_Day.day>>T[i].Birth_Day.month>>T[i].Birth_Day.year;
    }
    Nbr_Stgrs = Nbr_Stgrs + nbr_stgrs_ajt;
}

void Search() {
    int choice,nbr_rchrch,indice;
    string Rchrch_choix;

    system("clear");
    Menu:
    cout<<"1 - Search with the First Name."<<endl;
    cout<<"2 - Search with the Last Name."<<endl;
    cout<<"3 - Search with the Class."<<endl;
    cout<<"4 - Search with the Code."<<endl;
    cout<<"5 - Search with the Year of Birth."<<endl;
    cout<<"Your choice: ";
    cin>>choice;

    system("clear");

    if (choice == 1) {
        cout<<"Enter the First Name: ";
        cin>>Rchrch_choix;
        for (int i = 0; i < Nbr_Stgrs; i++){
            if (Rchrch_choix == T[i].First_Name) {
                cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
                cout<<"First Name     : "<<T[i].First_Name<<endl;
                cout<<"Last Name      : "<<T[i].Last_Name<<endl;
                cout<<"Class          : "<<T[i].Class<<endl;
                cout<<"Code           : "<<T[i].Code<<endl;
                cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
            }
        }
    }
    else if (choice == 2) {
        cout<<"Enter the Last Name: ";
        cin>>Rchrch_choix;
        for (int i = 0; i < Nbr_Stgrs; i++){
            if (Rchrch_choix == T[i].Last_Name) {
                cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
                cout<<"First Name     : "<<T[i].First_Name<<endl;
                cout<<"Last Name      : "<<T[i].Last_Name<<endl;
                cout<<"Class          : "<<T[i].Class<<endl;
                cout<<"Code           : "<<T[i].Code<<endl;
                cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
            }
        }
    }
    else if (choice == 3) {
        cout<<"Enter the Class: ";
        cin>>Rchrch_choix;
        for (int i = 0; i < Nbr_Stgrs; i++){
            if (Rchrch_choix == T[i].Class) {
                cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
                cout<<"First Name     : "<<T[i].First_Name<<endl;
                cout<<"Last Name      : "<<T[i].Last_Name<<endl;
                cout<<"Class          : "<<T[i].Class<<endl;
                cout<<"Code           : "<<T[i].Code<<endl;
                cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
            }
        }
    }
    else if (choice == 4) {
        cout<<"Enter the Code: ";
        cin>>Rchrch_choix;
        for (int i = 0; i < Nbr_Stgrs; i++){
            if (Rchrch_choix == T[i].Code) {
                cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
                cout<<"First Name     : "<<T[i].First_Name<<endl;
                cout<<"Last Name      : "<<T[i].Last_Name<<endl;
                cout<<"Class          : "<<T[i].Class<<endl;
                cout<<"Code           : "<<T[i].Code<<endl;
                cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
            }
        }
    }
    else if (choice == 5) {
        cout<<"Enter the Year of Birth: ";
        cin>>nbr_rchrch;
        for (int i = 0; i < Nbr_Stgrs; i++){
            if (nbr_rchrch == T[i].Birth_Day.year) {
                cout<<"===== Stagier N: "<<i+1<<" ====="<<endl;
                cout<<"First Name     : "<<T[i].First_Name<<endl;
                cout<<"Last Name      : "<<T[i].Last_Name<<endl;
                cout<<"Class          : "<<T[i].Class<<endl;
                cout<<"Code           : "<<T[i].Code<<endl;
                cout<<"Birth Day      : "<<T[i].Birth_Day.day<<"-"<<T[i].Birth_Day.month<<"-"<<T[i].Birth_Day.year<<endl<<endl;
            }
        }
    }
    else {
        cout<<"Invalide choice."<<endl;
        goto Menu;
    }
    char x;cin>>x;
}

void Edit() {
    string Rchrch_choix;
    int indice = -1;
    system("clear");
    Edit:
    cout<<"Enter the Code of the \"Stagier\" for Edit it: ";
    cin>>Rchrch_choix;
    for (int i = 0; i < Nbr_Stgrs; i++){
        if (Rchrch_choix == T[i].Code) {
            indice = i;
            break;
        }
    }
    if (indice != -1) {
        system("clear");
        cout<<"===== Stagier ====="<<endl;
        cout<<"First Name     : "<<T[indice].First_Name<<endl;
        cout<<"Last Name      : "<<T[indice].Last_Name<<endl;
        cout<<"Class          : "<<T[indice].Class<<endl;
        cout<<"Code           : "<<T[indice].Code<<endl;
        cout<<"Birth Day      : "<<T[indice].Birth_Day.day<<"-"<<T[indice].Birth_Day.month<<"-"<<T[indice].Birth_Day.year<<endl<<endl;

        cout<<"Enter the New First Name: ";
        cin>>T[indice].First_Name;
        cout<<"Enter the New Last Name: ";
        cin>>T[indice].Last_Name;
        cout<<"Enter the New Class: ";
        cin>>T[indice].Class;
        cout<<"Enter the New Code: ";
        cin>>T[indice].Code;
        cout<<"Enter The New Birth Day (dd mm yyyy): ";
        cin>>T[indice].Birth_Day.day>>T[indice].Birth_Day.month>>T[indice].Birth_Day.year;
    }
    else {
        system("clear");
        cout<<"There is no one with this Code."<<endl;
        cout<<"Please Enter a correct Code."<<endl;
        goto Edit;
    }
    char x;cin>>x;
}

void Trier() {
    bool check = false;
    Stagier temp;
    while (check == false) {
        check = true;
        for (int i = 0; i < Nbr_Stgrs-1; i++) {
            if (T[i].Birth_Day.year > T[i+1].Birth_Day.year) {
                temp = T[i];
                T[i] = T[i+1];
                T[i+1] = temp;
                check = false;
            }
        }
    }
    
}

void Save() {
    system("clear");
    string temp_year;

    FILE *index;
    index = fopen("Stagiers.txt","w");
    for (int i = 0; i < Nbr_Stgrs; i++) {
        fputs(T[i].First_Name,index);
        fputs("/",index);
        fputs(T[i].Last_Name,index);
        fputs("/",index);
        fputs(T[i].Class,index);
        fputs("/",index);
        fputs(T[i].Code,index);
        fputs("/",index);
        temp_year = to_string(T[i].Birth_Day.day) + "/" + to_string(T[i].Birth_Day.month) + "/" + to_string(T[i].Birth_Day.year);
        for (int i = 0; i < temp_year.size(); i++) putc(temp_year[i],index);
        fputs("\n",index);
    }
    fclose(index);
    system("pause");
    system("sleep 2");
    
}

int main() {
    T = new Stagier[50];
    int choice;

    Uppload();

    MENU:
    system("clear");
    cout<<"1 - Show all the stagiers."<<endl;
    cout<<"2 - Add a new stagier."<<endl;
    cout<<"3 - Search for a stagier."<<endl;
    cout<<"4 - Edit a stagier."<<endl;
    cout<<"5 - Save the stagiers."<<endl;
    cout<<"6 - Exit."<<endl;
    cout<<"Your choice: ";
    cin>>choice;
    if (choice == 1) {
        Show();
        goto MENU;
    }
    else if (choice == 2) {
        Add();
        Trier();
        goto MENU;
    }
    else if (choice == 3) {
        Search();
        goto MENU;
    }
    else if (choice == 4) {
        Edit();
        Trier();
        goto MENU;
    }
    else if (choice == 5) {
        Trier();
        Save();
        goto MENU;
    }
    else if (choice == 6) {
        system("clear");
        cout<<"Thank you!"<<endl;
    }
    else {
        system("clear");
        cout<<"Invalid choice."<<endl;
        system("sleep 1");
        goto MENU;
    }

    return 0;
}
