/**
* Auteur: Ethan Rogge, Jean-Nicolas Grégoire et Nassime 
* date: 7 novembre 2022
* Base de données gérant des le profil d'étudiants et permettant 
* d'en ajouter, supprimer, modifier et selectionner.
**/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "query.h"
#include "db.h"

using namespace std;


int main(int argc, char const *argv[]) {

  const char *db_path = argv[1];
  const char *query_path = argv [2];
  database_t db;
  
  db_init(&db);
  db_load(&db, db_path);
  cout<<"Base de données bien chargée"<<endl<<"pour fermer la db entré le mot stop"<<endl;
  
  if (query_path!=NULL){ //si pas de fichier de requete fournie
    vector<string> lines;
    string line;
    string path=query_path;
    ifstream file(path);
    while (getline(file,line)){
      lines.push_back(line);
    }
    for (size_t i=0;i<lines.size();i++){
      char query[50];
      strcpy(query,line.c_str());
      find_query(&db,query);
    }
  }
  
  else{
    char query[50];
    char finish[10]="stop";
    while (strcmp(finish,query)!=0){ //tant que le mots stop n'est pas entré
      cout<<"veuillez entrer votre requetes:"<<endl;
      cin.get(query, 50);
      find_query(&db, query);
    }
  }
  
  db_save(&db, db_path);
  printf("Bye bye!\n");
  return 0;
}