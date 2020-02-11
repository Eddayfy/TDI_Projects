#include<iostream>
#include<stdlib.h>
using namespace std;

//hna saybt stucture
struct stagiaire { char nom[10];char prenom[10];char code[10];char age[5];};

//hado jouj variablat ghadi nhtajhoum
int choix,nmbr_stg=0;

//hna declarite pointeur hit ghadi nhtajo bach nssayb tableau (declaration dyal tableau ghadi tl9aha f'main)
stagiaire *T = NULL;

//foction dyal ajoute
void Ajouter() {
    int ajouter_nmbr;
    char tempchar[5];
    system("clear");
    cout<<"Donner le nomber de stagiers pour ajouter: ";
    cin>>ajouter_nmbr;
    for (int i = nmbr_stg; i < nmbr_stg + ajouter_nmbr; i++) {
        system("clear");
        cout<<"===== Le stagiaire n: "<<i+1<<" ====="<<endl;
        cout<<"Entrer le code:    ";
        cin>>T[i].code;
        cout<<"Entrer le nom:     ";
        cin>>T[i].nom;
        cout<<"Entrer le prenom:  ";
        cin>>T[i].prenom;
        cout<<"Entrer l'age:      ";
        cin>>T[i].age;
    }
    nmbr_stg = nmbr_stg + ajouter_nmbr;
    system("clear");
    cout<<"Tous les stagiers a etais ajouter"<<endl;
    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//fonction dyal inserer
void Inserer() {
    char tempchar[5];
    int indice;
    system("clear");
    stagiaire *D = NULL;
    D = new stagiaire[50];
    for(int i=0;i<nmbr_stg;i++) {
        D[i] = T[i];
    }
    delete [] T;
    T = NULL;
    T = new stagiaire[50];
    cout<<"Entrer l'indice de stagier pour inserer le: ";
    cin>>indice;
    for(int i = 0;i<indice;i++) {
        T[i] = D[i];
    }
    cout<<"Entrer le code:    ";
    cin>>T[indice].code;
    cout<<"Entrer le nom:     ";
    cin>>T[indice].nom;
    cout<<"Entrer le prenom:  ";
    cin>>T[indice].prenom;
    cout<<"Entrer l'age:      ";
    cin>>T[indice].age;
    nmbr_stg = nmbr_stg + 1;
    for (int i = indice; i < nmbr_stg; i++) {
        T[i+1] = D[i];
    }
    delete [] D;
    D = NULL;
    system("clear");
    cout<<"Le stagier a etais inserer."<<endl;
    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//foction dyal afficher
void Afficher() {
    char tempchar[5];
    system("clear");
    for(int i = 0;i < nmbr_stg;i++) {
        cout<<"===== Le stagiaire n: "<<i+1<<" ====="<<endl;
        cout<<"Le code:    "<<T[i].code<<endl;
        cout<<"Le nom:     "<<T[i].nom<<endl;
        cout<<"Le prenom:  "<<T[i].prenom<<endl;
        cout<<"L'age:      "<<T[i].age<<endl;
    }

    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}
void Rechercher() {
    char tempchar[5];
    string code_rechercher;
    int temp_nbr = -1;
    system("clear");
    cout<<"Donner le code de perssone a rechercher: ";
    cin>>code_rechercher;
    system("clear");
    for (int i = 0; i < nmbr_stg; i++) {
        if (code_rechercher == T[i].code) {
            temp_nbr = i;
            break;
        }
    }

    cout<<"===== Le stagiaire avec le code: "<<code_rechercher<<" ====="<<endl;
    if(temp_nbr == -1) {
        cout<<"est n'exist pas dans la list."<<endl;
    }
    else {
        cout<<"son nom:     "<<T[temp_nbr].nom<<endl;
        cout<<"son prenom:  "<<T[temp_nbr].prenom<<endl;
        cout<<"son age:     "<<T[temp_nbr].age<<endl;
    }

    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//foction dyal modifier
void Modifier() {
    char tempchar[5];
    int temp_nbr;
    system("clear");
    for(int i = 0;i < nmbr_stg;i++) {
        cout<<"Le stagier N ["<<i+1<<"] "<<"  son code: "<<T[i].code<<"  son nom: "<<T[i].nom<<"  son prenom: "<<T[i].prenom<<"  L'age: "<<T[i].age<<endl;
    }
    cout<<"\nDonner le N de stagier pour modifier: ";
    cin>>temp_nbr;
    system("clear");
    cout<<"===== Le stagiaire n: "<<temp_nbr<<" ====="<<endl;
    cout<<"Le code:    "<<T[temp_nbr-1].code<<endl;
    cout<<"Le nom:     "<<T[temp_nbr-1].nom<<endl;
    cout<<"Le prenom:  "<<T[temp_nbr-1].prenom<<endl;
    cout<<"L'age:      "<<T[temp_nbr-1].age<<endl<<endl;

    cout<<"Entrer Noveau code:    ";
    cin>>T[temp_nbr-1].code;
    cout<<"Entrer Noveau nom:     ";
    cin>>T[temp_nbr-1].nom;
    cout<<"Entrer Noveau prenom:  ";
    cin>>T[temp_nbr-1].prenom;
    cout<<"Entrer Noveau age:     ";
    cin>>T[temp_nbr-1].age;

    system("clear");
    cout<<"Le stagier est modifier."<<endl;

    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//foction dyal supprimer
void Supprimer() {
    char tempchar[5];
    int indice;
    stagiaire *D = NULL;
    D = new stagiaire[50];
    for(int i=0;i<nmbr_stg;i++) {
        D[i] = T[i];
    }
    delete [] T;
    T = NULL;
    T = new stagiaire[50];

    system("clear");
    cout<<"Donner l'indice de stagier pour sppremer: ";
    cin>>indice;
    
    for(int i = 0;i<indice;i++) {
        T[i] = D[i];
    }
    for (int i = indice; i < nmbr_stg; i++) {
        T[i] = D[i+1];
    }

    nmbr_stg = nmbr_stg - 1;

    delete [] D;
    D = NULL;

    system("clear");
    cout<<"Le stagier a etais suppremer."<<endl;

    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//foction dyal sauvgarder f'fichier
void Sauvgarder() {
    char tempchar[5];
    system("clear");
    FILE *index;
    index = fopen("fichier.txt","w");
    for (int i = 0; i < nmbr_stg; i++) {
        fputs(T[i].code,index);
        fputs("/",index);
        fputs(T[i].nom,index);
        fputs("/",index);
        fputs(T[i].prenom,index);
        fputs("/",index);
        fputs(T[i].age,index);
        fputs("\n",index);
    }
    fclose(index);

    cout<<"\nTaper un caractère et 'Entrer' pour continue: ";
    cin>>tempchar;
}

//hada howa main
int main() {
    T = new stagiaire[50];
    do {
        system("clear");
        menu:
        cout<<" [1] Ajouter un stagiaire."<<endl;
        cout<<" [2] Inserer un stagiaire."<<endl;
        cout<<" [3] Afficher les stagiaires."<<endl;
        cout<<" [4] Rechercher dans les stagiers."<<endl;
        cout<<" [5] Modifier un stagiare."<<endl;
        cout<<" [6] Supprimer un stagiaire."<<endl;
        cout<<" [7] Sauvgarder les stagiaires."<<endl;
        cout<<" [8] Quitter."<<endl;
        cout<<"Votre choix: ";
        cin>>choix;

        if (choix == 1) {
            Ajouter();
        }
        else if (choix == 2) {
            Inserer();
        }
        else if (choix == 3) {
            Afficher();
        }
        else if (choix == 4) {
            Rechercher();
        }
        else if (choix == 5) {
            Modifier();
        }
        else if (choix == 6) {
            Supprimer();
        }
        else if (choix == 7) {
            Sauvgarder();
        }
        else if (choix == 8) {
            system("clear");
            cout<<"Thank you.\n";
        }
        else {
            system("clear");
            cout<<"invalide choix."<<endl;
            goto menu;
        }
        

    }while (choix != 8);


    return 0;
}
