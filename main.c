#include <stdio.h>
#include <mysql/mysql.h>
#include <mysql/my_global.h>

void main(void)
{
      MYSQL conexao;

      mysql_init(&conexao);
      if ( mysql_real_connect(&conexao, "localhost", "root", "", "teste", 0, NULL, 0) )
      {
            printf("conectado com sucesso!\n");
            mysql_close(&conexao);
       }
       else
       {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }
}
