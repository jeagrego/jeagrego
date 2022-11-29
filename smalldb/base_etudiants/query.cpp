#include "query.h"
#include "student.h"
#include "db.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

void query_result_init(query_result_t* result, const char* query) {
  struct timespec now;
  clock_gettime(CLOCK_REALTIME, &now);
  result->start_ns = now.tv_nsec + 1e9 * now.tv_sec;
  result->status = QUERY_SUCCESS;
  // Votre code ici
}
void find_query(database_t *db, char query[50]){
   switch(query[0]){
      case 's':{
         char* field=strtok(query," ");
         field=strtok(NULL,"=");
         char* value=strtok(NULL,"");
         query_select(db,field,value);}
      case 'u':{
         char* filter=strtok(query," ");
         filter=strtok(NULL,"=");
         char* value=strtok(NULL," ");
         char* update_field=strtok(NULL," ");
         update_field=strtok(NULL,"=");
         char* update_value=strtok(NULL,"");
         query_update(db,filter,value,update_field,update_value);}
      case 'i':{
         char* id=strtok(query," ");
         id=strtok(NULL," ");
         char* fname=strtok(NULL," ");
         char* lname=strtok(NULL," ");
         char* section=strtok(NULL," ");
         char* birthdate=strtok(NULL,"");
         query_insert(db,id,fname,lname,section,birthdate);}
      case 'd':{
         char* field=strtok(query," ");
         field=strtok(NULL,"=");
         char* value=strtok(NULL,"");
         query_delete(db,field,value);
      }   
   }
}


bool find_student(database_t *db, size_t i, char* field, char* value){
  switch (field[0]){
     case 'i':
        if (db->data[i].id==(unsigned int)std::stoi(value)){
           return true;
        }
        else {return false;}
     case 'l':
        if (strcmp(db->data[i].lname,value)==0){
           return true;
        }
        else {return false;}
     case 'f':
        if (strcmp(db->data[i].fname,value)==0){
           return true;
        }
        else {return false;}
     case 's':
        if (strcmp(db->data[i].section,value)==0){
           return true;
        }
        else {return false;}   
  }
  return false;
}

std::vector<student_t*>  query_select(database_t *db,char* field, char* value){
  std::vector<student_t*> good_student;
  size_t i;
  for (i=0;i<((db->lsize)-1);i++){
     if (find_student(db,i,field,value)){
        student_to_str(&(db->data[i]));
        good_student.push_back(&(db->data[i]));
     }
  }
  return good_student;
}


void query_delete(database_t *db,char* field, char* value){
  size_t i;
  for (i=0;i<db->lsize;i++){
     if (find_student(db,i,field,value)){
        db->lsize=db->lsize-1;
        for (size_t l=i;l<db->lsize;l++){
           db->data[l]=db->data[l+1];
        }  
     }
  }
}

void query_insert(databasale_t *db,char* id,char* fname,char* lname, char* section, char* birthdate){
  size_t i;
  bool is_in;
  for (i=0;i<db->lsize;i++){
     if (db->data[i].id==(unsigned)std::stoi(id)){
          is_in=true;
     }
     else{ is_in=false;
     }
  }
  if (!is_in){
     db_extend(db);
     student_t new_std;
     new_std.id=std::stoi(id);
     strcpy(new_std.fname,fname);
     strcpy(new_std.lname,lname);
     strcpy(new_std.section,section);
     char* day=strtok(birthdate,"/");
     char* month=strtok(NULL,"/");
     char* year=strtok(NULL,"");
     new_std.birthdate.tm_mday=std::stoi(day);
     new_std.birthdate.tm_mon=std::stoi(month);
     new_std.birthdate.tm_year=std::stoi(year);
     db->data[db->lsize]=new_std;
     db->lsize++;
  }
}


void query_update(database_t *db,char* filter,char* value,char* update_field,char* update_value){
  for (size_t i=0; i<=db->lsize;i++){
     if (find_student(db,i,filter,value)){
        switch(update_field[0]){
          case 'i':
             db->data[i].id=std::stoi(value);
          case 'l':
             strcpy(db->data[i].lname,update_value);
          case 'f':
             strcpy(db->data[i].fname,update_value);
          case 's':
             strcpy(db->data[i].section,update_value);
          case 'b':
             char* day=strtok(update_value,"/");
             char* month=strtok(NULL,"/");
             char* year=strtok(NULL,"");
             db->data[i].birthdate.tm_mday=std::stoi(day);
             db->data[i].birthdate.tm_mon=std::stoi(month);
             db->data[i].birthdate.tm_year=std::stoi(year);
        }
     }
  }
}