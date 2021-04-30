#include <stdio.h> //Biblioteca de entrada e saída de dados
#include <string.h> // Biblioteca de texto
#include <stdlib.h> //Biblioteca de conversão, memória, controle de processo, ordenamento e busca, matemática.
#include <locale.h> // Biblioteca de implementar a localização de programas
#include <time.h> //Biblioteca para formatar data
#include <ctype.h>
#define MAX 10
#define TAM 80

struct es {
    char uf[TAM];
};
typedef struct es ESTADO;

struct ci{
    char validar_cidade [TAM];
};
typedef struct ci CIDADE;

typedef struct { //struct data
    int dia[02];
    int mes [TAM];
    int ano[4];
}data;

typedef struct cadastro{
    char nome [TAM]; //variavel do tipo string
    char sexo[MAX];
    data;
    CIDADE;
    ESTADO;
}CADASTRO;


void menu ();
//void validarEstado ();
//void validarCidade();
//void validaNome ();
//void validaSexo ();
//void validaParar();
void cadastro_estado ();
//void cadastro_cidade ();
//void cadastrarpessoas ();
//void listarpessoasporestado ();
//void consultarpessoaspornome ();
//void excluirpessoas ();
//void gerarrelatoriodevacinacao ();


int main (){
    FILE*f;
     setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português

    menu(); //executar função menu
    return 0;
}

void menu(){ //Mostrar o menu inicial para o usuario
    int op_menu;// variavel de escolha do usuario
    system ("cls");//limpar terminal
    FILE *f;//ponteiro do arquivo

    if ((f=fopen("registro_demografico_de_vacinação.bin","ab")) == NULL){//abertura do arquivo
        printf("Arquivo nao pode ser aberto.\n\n");
    }
    fclose(f);//fechamento do arquivo

        do {
            printf ("\n\t Menu de Opções: \n");
            printf ("\t 1) Cadastrar Estado \n");
            printf ("\t 2) Cadastrar Cidade \n");
            printf ("\t 3) Cadastrar Pessoa \n");
            printf ("\t 4) Listar pessoas por Estado \n");
            printf ("\t 5) Listar pessoas por Cidade \n");
            printf ("\t 6) Consultar Pessoa por Nome \n");
            printf ("\t 7) Excluir Pessoa \n");
            printf ("\t 8) Gerar relatório de vacinação \n");
            printf ("\t 9) Encerrar Programa \n");
            printf ("\n\t Digite o número correspondente a opção desejada do Menu de Opções: ");
            scanf ("%d", &op_menu);

            switch (op_menu){
                case 1:
                cadastro_estado ();
                break;

                case 2:

                break;

                case 3:

                break;

                case 4:

                break;

                case 5:

                break;

                case 6:

                break;

                case 7:

                break;

                case 8:

                break;

                case 9:
            system("cls");
            printf("Obrigado por utilizar esta plataforma digital. Ate logo!\n\n\n");
            break;
        default:
            system("cls");
            printf("Opcao invalida!Digite novamente uma opcao\n\n");
        }
    }while (op_menu!=9);
}

//Sintese
//Objetivo: Cadastrar o candidato(a)
//Parametros: struct contendo as variaveis para o cadastro do candidato, arquivo *f
//Retorno: nenhum

void cadastro_estado (){
    FILE *f;
    system("cls");
    ESTADO cadastrar;
    char parar;
    int aux;

    do{
        printf ("\t\t\t\t\t####Cadastrar estado####\n\n");
        printf("\n\t Escreva o nome da UF seguida do estado a ser salvo. (Exemplo: DF - Distrito Federal):");
        fflush (stdin);
        fgets (cadastrar.uf,TAM,stdin);
        //tiraEnter(cadastrar.estado);
        //tiraEnter(cadastrar.estado);
        //validaNome(candidato.nome_candidato);
        f = fopen("eleicaoPrefeito.bin","ab");
        fwrite(&cadastrar,sizeof(ESTADO),1,f);
        system("cls");
        printf("Estado cadastrado com sucesso!\n\n");
        aux=fclose(f);
        printf (cadastrar.uf);
        printf("Deseja cadastrar outro estado? Digite S para sim ou N para nao: ");
        fflush(stdin);
        scanf("%c",&parar);
        parar=toupper(parar);
        validaParar();
    }while (parar!='N');
    if(aux!=0){
        printf("Arquivo aberto\n\n");
    }

}

//Sintese
//Objetivo: validar a letra digitada para definir se deseja parar de cadastrar ou nao
//Parametros: letra digitada para parar ou nao de cadastrar
//Retorno: nenhum

void validaParar(){
    char parar;
    while(parar!='S' && parar!='N')
    {
        printf("Opcao invalida.Digite S para cadastrar mais ou N para nao cadastrar mais : ");
        fflush(stdin);
        scanf("%c",&parar);
        parar=toupper(parar);
    }
}
