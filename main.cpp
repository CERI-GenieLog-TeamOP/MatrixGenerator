#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*!

\author Dupuy Nicolas TP04
\file Programme qui genere automatiquement une matrice creuse ou pleine de taille choisie dans un fichier.

*/

//Forme de la matrice dans le fichier:
    //*  LIGNE,COLONNE,VALEUR  *//
    //*  LIGNE,COLONNE,VALEUR  *//
    //*          ...           *//


string readLine(string fichier, int l)
{
    string line;
    ifstream monFichier (fichier.c_str());

    for(int i = 1 ; i <= l ; i++)
    {
        getline(monFichier, line);
    }
    return line;
}

void cGen(int nc, int nl, string fichier, int indice) //Generateur de matrices creuse.
{
    int n(0);

    if(indice < 1 || indice > 9)indice = 5;
    ofstream monFichier (fichier.c_str());

    srand (time(NULL));

    monFichier << nl << ' ' << nc << endl;
    for (int idxL = 0 ; idxL < nl ; idxL++)
    {

        for (int idxC = 0 ; idxC < nc ; idxC++)
        {
            if((rand() % 10) < indice) n = 0;
            else
            {
                n = rand() % 10 + 1;
                monFichier << idxL << " " << idxC << " " << n <<endl;
            }

        }
    }
}


void pGen(int nc, int nl, string fichier) //Generateur de matrices pleine.
{
    ofstream monFichier (fichier.c_str());

    srand (time(NULL));

    for (int idxL = 0 ; idxL < nl ; idxL++)
    {
        for (int idxC = 0 ; idxC < nc ; idxC++)
        {
            monFichier << idxL << " " << idxC << " " << rand() % 10 <<endl;
        }
    }
}

void generateMatrixC()  //Appel au generateur de matrice creuse.
{
    int nc(0), nl(0), indice(0);
    string fichier = "matrice.txt";
    cout<<"Vous avez choisi de generer une matrice creuse."<<endl<<endl;

    cout<<"Veuillez choisir le nombre de colonnes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nc;

    cout<<"Veuillez choisir le nombre de lignes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nl;

    cout<<"Veuillez indiquer le nom du fichier a creer/modifier."<<endl;
    cout<<">"<<endl<<endl;
    cin>>fichier;

    cout<<"Veuillez indiquer un indice (entre 1 et 9) qui creera plus ou moins de zeros. (1 -> 10% de zeros  9 -> 90% de zeros)"<<endl;
    cout<<">"<<endl<<endl;
    cin>>indice;

    cout<<endl<<endl<<"RECAP: Vous avez demande une matrice creuse de "<<nc<<" colonnes et "<<nl<<" lignes que vous souhaitez stocker dans le fichier "<<fichier<<"."<<endl;

    cGen(nc, nl, fichier, indice);

    cout<<endl<<endl<<"Matrice creee avec succes !"<<endl;
}

void generateMatrixP() //Appel au generateur de matrice pleine.
{
    int nc(0), nl(0);
    string fichier = "matrice.txt";
    cout<<"Vous avez choisi de generer une matrice pleine."<<endl<<endl;

    cout<<"Veuillez choisir le nombre de colonnes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nc;

    cout<<"Veuillez choisir le nombre de lignes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nl;

    cout<<"Veuillez indiquer le nom du fichier a creer/modifier."<<endl;
    cout<<">"<<endl<<endl;
    cin>>fichier;

    cout<<"RECAP: Vous avez demande une matrice pleine de "<<nc<<" colonnes et "<<nl<<" lignes que vous souhaitez stocker dans le fichier "<<fichier<<"."<<endl;

    pGen(nc, nl, fichier);

    cout<<"Matrice creee avec succes !"<<endl;
}


int main ()
{
    string type = "creuse";
    cout<<"  ---Bienvenue dans le generateur de Matrices creuses ou pleines--- "<<endl<<endl<<endl;

    cout<<" Souhaitez vous creer une matrice creuse ou pleine? (creuse | pleine)"<<endl;
    cout<<">";
    cin>>type;

    if(type == "creuse")generateMatrixC();
    if(type == "pleine")generateMatrixP();
}
