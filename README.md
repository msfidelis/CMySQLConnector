# CMySQLConnector
Exemplo simples de conexão entre binários em C/C++ e bancos de dados MySQL e MariaDB

#Testando a Conexão
Edite o arquivo main.c e ajuste as configurações do banco de acordo com seu localhost 

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

e Compile:
 * gcc -o test.c main.c `mysql_config --cflags --libs`
 
 * ./test.c


#Executando a Query no Banco
Altere os Defines para as credencias do seu banco 

* #define HOST "localhost"
* #define USER "root"
* #define PASS "senhadoseubanco"
* #define DB "nomedoseubanco"

Altere a variável/lista 'Query' ajustando para a tabela que quer executar o seçect 
* char query[]="SELECT * FROM teste_users";


#Compilando
 * gcc -o select_mysql.c select.c `mysql_config --cflags --libs`


#Executando 
* ./select_mysql.c
