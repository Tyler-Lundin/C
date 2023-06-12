#include <stdio.h>
#include <sqlite3.h>

char green[] = "\033[0;32m";
char yellow[] = "\033[0;33m";
char blue[] = "\033[0;34m";
char red[] = "\033[0;31m";
char reset[] = "\033[0m";


int main () {

  sqlite3 *db; // pointer to sqlite3 database
  printf("%s", green);
  printf("Please Enter your Employee ID: \n%s", reset);
  int id;
  scanf("%d", &id);

  int rc = sqlite3_open("employee.db", &db); // open database

  if (rc) {
    printf("%s", red);
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    printf("%s", reset);
    return(0);
  } else {
    printf("%s", green);
    fprintf(stderr, "Opened database successfully\n");
    printf("%s", reset);
  }

  char *sql = "SELECT * FROM employee WHERE id = ?"; // sql query

  sqlite3_stmt *stmt; // pointer to sqlite3 statement
  
  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); // prepare statement
  
  if (rc != SQLITE_OK) {
    printf("%s", red);
    fprintf(stderr, "Preparation failed: %s\n", sqlite3_errmsg(db));
    printf("%s", reset);
    return(0);
  } else {
    printf("%s", green);
    fprintf(stderr, "Preparation successful\n");
    printf("%s", reset);
  }

  

  return 0;
}
