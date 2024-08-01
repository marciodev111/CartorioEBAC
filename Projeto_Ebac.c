#include <stdio.h> //Biblioteca de comunicação com usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h>//Biblioteca responsavel por cuidar das string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
    //inicio criaçã de variáveis /string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis /string
    
    printf("Digite o cpf a ser cadastrao:");
    scanf("%s",cpf);//%s refere a string
    
    strcpy(arquivo,cpf);//Responsavel por copiar valores das string
    
    FILE *file;// Cria o arquivo
    file = fopen(arquivo, "w");// Cria na pasta "W" significa escrever
    fprintf(file,cpf);//Salva o valor da variavel
    fclose(file);//Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadrastrado:");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadrastrado:");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    fclose(file);
    
    system("pause");
    
    
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    char cpf[40];
    char conteudo[100];
    
    printf("Digite o cpf a ser consultado:");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("arquivo não localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file)!= NULL)
    {
        printf("\nEssas são as informações do usuário:");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado");
    scanf("%s",cpf);
    
    remove (cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf(" O usuário não se encontra no sistema!.\n");
        system("pause");
        
    }
}


int main()
{
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco==1;)
    {
        
        system("cls");
       
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
        printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("Opção: "); //Fim do menu
        
        scanf("%d" , &opcao); //armazenando a escolha do usuário
        
        system("cls");// responsavel por limpar a tela
        
        
        switch(opcao)// Inicio da seleção
        {
            case 1:
                registro();//chamada de funções
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            default :
                printf("Essa opção não está disponivel!\n");
                system("pause");
                break;
        }//fim da seleção
        
               
               
    }
        
    
}

    



 
