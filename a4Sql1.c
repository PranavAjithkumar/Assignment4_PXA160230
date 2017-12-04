#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <string.h>

//using namespace std;

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc,i;
   const char* data = "Callback function called";
   int ctotal, res;

   /* Open database */
   rc = sqlite3_open("/home/010/p/px/pxa160230/mysql/sqlite/test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sqlite3_stmt *statement;    

   char *query = "select * from COMPANY;";

    if ( sqlite3_prepare(db, query, -1, &statement, 0 ) == SQLITE_OK ) 
    {
        ctotal = sqlite3_column_count(statement);
        res = 0;

        while ( 1 )         
        {
            res = sqlite3_step(statement);

            if ( res == SQLITE_ROW ) 
            {
                for ( i = 0; i < ctotal; i++ ) 
                {
                    char * s = (char*)sqlite3_column_text(statement, i);
                    // print or format the output as you want 
                    printf("%s ",s);
                }
                printf("\n");
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)    
            {
                printf("<< done >>\n");
                break;
            }    
        }
    }

   sqlite3_close(db);
   return 0;
}
