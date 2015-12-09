
#include <stdio.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS ""
#define DB "teste"

int main(void)
{
   MYSQL conexao;
   MYSQL_RES *resp;
   MYSQL_ROW linhas;
   MYSQL_FIELD *campos;
   char query[]="SELECT * FROM dotp_users";
   int conta;

   mysql_init(&conexao);
   if (mysql_real_connect(&conexao,HOST,USER,PASS,DB,0,NULL,0))
   {
      printf("Conectado com Sucesso!\n");
      if (mysql_query(&conexao,query))
         printf("Erro: %s\n",mysql_error(&conexao));
      else
      {
         resp = mysql_store_result(&conexao);
        if (resp)
        {

           campos = mysql_fetch_fields(resp);
           for (conta=0;conta<mysql_num_fields(resp);conta++) {
              printf("%s",(campos[conta]).name);
              if (mysql_num_fields(resp)>1)
                  printf("\t");
              }

              printf("\n");

              while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                    printf("%s\t",linhas[conta]);
                 printf("\n");
              }
          }
          mysql_free_result(resp);
        }
        mysql_close(&conexao);
   }
   else
   {
      printf("Conexao Falhou\n");
      if (mysql_errno(&conexao))
         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
   }

   return 0;
}
