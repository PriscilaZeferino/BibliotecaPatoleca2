#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "dados.h"

void MostrarMenu()
{
     printf("\n");
     printf("MENU---------------------------------\n");
     printf("0. Sair------------------------------\n");
     printf("1. Listar Clientes-------------------\n");
     printf("2. Cadastrar clientes----------------\n");
     printf("3. Pesquisar cliente pelo nome-------\n");
     printf("4. Excluir cliente pelo codigo-------\n");
     printf("5. Listar livros --------------------\n");
     printf("6. Cadastrar livro ------------------\n");
     printf("7. Pesquisar livro pelo nome---------\n");
     printf("8. Excluir livros pelo codigo--------\n");
     printf("9. Listar livros locados-------------\n");
     printf("10.Locar livro-----------------------\n");
     printf("11.Devolver livro pelo codigo--------\n");
     printf("\n");
}

void ListarClientes()
{
        system("cls");
        printf("===================LISTA DE CLIENTES===========================\n");
        printf("CODIGO---------NOME-------------PHONE--------------CPF---------\n");
    
    
        int tamanhoChars = RecuperarTamanhoChars();
        int maxIndiceClientes = RecuperarMaxIndiceClientes();
        for(int i = 0; i < maxIndiceClientes; ++i)
        {
            char name[tamanhoChars];
            char cpf[tamanhoChars];
            char phone[tamanhoChars];
            
            ObterDadosCliente(i, name, phone, cpf);
            
            if(strcmp(name, "") != 0 && strcmp(phone, "") != 0 && strcmp(cpf, "") != 0)
            {
                printf("  %d :        %s        %s            %s", i, name, phone, cpf);
                printf("\n");
            }
        }
}

void ListarLivros()
{
        system("cls");
        printf("===================LISTA DE LIVROS===============================\n");
        printf("CODIGO---------TITULO-------------AUTOR--------------ANO---------\n");

        int tamanhoChars = RecuperarTamanhoChars();
        int maxIndiceLivros = RecuperarMaxIndiceLivros();
        for(int i = 0; i < maxIndiceLivros; ++i)
        {
            char titulo[tamanhoChars];
            char autor[tamanhoChars];
            char ano[tamanhoChars];

            ObterDadosLivros(i, titulo, autor, ano);

            if(strcmp(titulo, "") != 0 && strcmp(autor, "") != 0 && strcmp(ano, "") != 0)
            {
                printf("  %d :        %s        %s            %s", i, titulo, autor, ano);
                printf("\n");
            }
        }
}

void ListarLivrosLocados()
{
         printf("===================LISTA DE LIVROS LOCADOS=======================\n");
         printf("CODIGO---------TITULO-------------ANO--------------AUTOR---------\n");

        int locado = -1;
        int tamanhoChars = RecuperarTamanhoChars();
        int maxIndiceLivros = RecuperarMaxIndiceLivros();
        for(int i = 0; i < maxIndiceLivros; ++i)
        {
            char titulo[tamanhoChars];
            char autor[tamanhoChars];
            char ano[tamanhoChars];

            locado = ObterDadosLivrosLocados(i, titulo, autor, ano);

            if(locado == 0)
            {
                printf("  %d :        %s        %s            %s", i, titulo, autor, ano);
                printf("\n");
            }
        }

}

void AlocadoOuNaoAlocadoMensagensClientes (int cliente)
{
    if(cliente != 0)
    {
        printf("Não foi possivel alocar memória para clientes!\n");
    }
    else
    {
        printf("Foi possivel alocar memoria para clientes \n");
        limparArraysClientes();
    }
}

void AlocadoOuNaoAlocadoMensagensLivros (int livro)
{
    if(livro != 0)
    {
        printf("Não foi possivel alocar memória para livros! \n");
    }
    else
    {
        printf("Foi possivel alocar memoria para livros \n");
        limparArraysLivros();
    }
}

void CadastrarCliente()
{
    int tamanhoChars = RecuperarTamanhoChars();
    char name[tamanhoChars];
    char phone[tamanhoChars];
    char cpf[tamanhoChars];

    
    int maxIndiceClientes = RecuperarMaxIndiceClientes();
    int ocupadoCliente = RecuperarOcupadoClientes();
    if(ocupadoCliente < maxIndiceClientes)
    {
        printf("Informe o nome do cliente: \n");
        fflush(stdin);
        scanf("%[^\n]", name);

        printf("Informe o telefone do cliente: \n");
        fflush(stdin);
        scanf("%[^\n]", phone);

        printf("Informe o cpf do cliente: \n");
        fflush(stdin);
        scanf("%[^\n]", cpf);

        for(int i = 0; i < maxIndiceClientes; i++)
        {
            int resultadoCadastro = CadastrarNovoCliente(i, name, phone, cpf);
            if(resultadoCadastro == 0)
            {
                int cliente = RealocarMemoriaClientes();
                AlocadoOuNaoAlocadoMensagensClientes(cliente);
                break;
            }
        }
    }
    else
    {
        printf("Todas as posicoes ja estao ocupadas");
    }

}


void CadastrarLivro()
{
    int tamanhoChars = RecuperarTamanhoChars();
    char titulo[tamanhoChars];
    char autor[tamanhoChars];
    char ano[tamanhoChars];
    
    int maxIndiceLivros = RecuperarMaxIndiceLivros();
    int ocupadoLivro = RecuperarOcupadoLivros();
    if(ocupadoLivro < maxIndiceLivros)
    {
        printf("Informe o titulo do livro: \n");
        fflush(stdin);
        scanf("%[^\n]", titulo);

        printf("Informe o autor do livro: \n");
        fflush(stdin);
        scanf("%[^\n]", autor);

        printf("Informe o ano do livro: \n");
        fflush(stdin);
        scanf("%[^\n]", ano);

        for(int i = 0; i < maxIndiceLivros; i++)
        {
            int resultadoCadastro = CadastrarNovoLivro( i, titulo, autor, ano);
            if(resultadoCadastro == 0)
            {
                int livro = RealocarMemoriaLivros();
                AlocadoOuNaoAlocadoMensagensLivros(livro);
                break;
            }
        }
    }
    else
    {
        printf("Todas as posicoes ja estao ocupadas");
    }

}

int main(int argc, char *argv[]) {

    int code = -1;
    int stop = 0;
    int encontrado;
    
    int tamanhoChars = RecuperarTamanhoChars();


    //Alocacao de memoria
    int cliente = AlocarMemoriaClientes();
    AlocadoOuNaoAlocadoMensagensClientes(cliente);
    
    int livro = AlocarMemoriaLivros();
    AlocadoOuNaoAlocadoMensagensLivros(livro);
    
    InicializarArrays();

//    int maxIndiceClientes = RecuperarMaxIndiceClientes();
    int ocupadoCliente = RecuperarOcupadoClientes();

    int maxIndiceLivros = RecuperarMaxIndiceLivros();
    int ocupadoLivro = RecuperarOcupadoLivros();
    
    LerArquivos();
    
    int menu;
    do
    {
        MostrarMenu();
        printf("O que deseja fazer? \n");
        fflush(stdin);
        scanf("%d", &menu);
        
        switch(menu)
        {
            //Sair
            case 0:
            {
                system("cls");
                printf("SISTEMA ENCERRADO!");
                break;
            }
            case 1:
                ListarClientes();
                break;
            
            case 2:
                CadastrarCliente();
                break;
            
            //Pesquisar cliente pelo nome
            case 3:
               { system("cls");

                char nomeEscolhido[tamanhoChars];
                char phone[tamanhoChars];
                char cpf[tamanhoChars];


                printf("PESQUISAR CLIENTE PELO NOME: \n");
                printf("Informe o nome do cliente:   \n");
                fflush(stdin);
                scanf("%[^\n]", nomeEscolhido);

                int encontrado = 0;
                int code = 0;
                encontrado = PesquisarClientePeloNome(code, nomeEscolhido, phone, cpf);

                if(encontrado == 0)
                {
                    printf("CLIENTE ENCONTRADO \n");
                    printf("    Codigo: %d   \n", code);
                    printf("    Nome: %s     \n", nomeEscolhido);
                    printf("    Telefone: %s \n", phone);
                    printf("    CPF: %s         \n", cpf);
                    break;
                }
                   
                if(encontrado == 1)
                {
                    printf("Nao encontrado!");
                }

                break;
                }
            //Excluir cliente pelo codigo
            case 4:
               { system("cls");

                ListarClientes();

                printf("--------------------EXCLUIR CLIENTE----------------------------\n");

                do
                {
                    printf("Qual o codigo do cliente: (0-%d) \n", (ocupadoCliente-1));
                    fflush(stdin);
                    scanf("%d", &code);

                    int excluido = -1;
                    excluido = ExcluirClientePeloCodigo(code);

                    switch (excluido) {
                        case 0:

                            printf("Excluido com sucesso! \n");
                            AlocadoOuNaoAlocadoMensagensClientes(cliente);
                            stop = 1;
                            break;
                        case 1:
                            printf("Cliente nao encontrado. \n");
                            break;
                        case 2:
                            printf("Esse cliente tem livro locado.   \n");
                            printf("Ele precisa devolver o livro antes de ser excluido. \n");
                            break;
                        default:
                            break;
                    }
                }
                while (stop != 1);
                break;
               }
            //Listar livros
            case 5:
                {system("cls");
                ListarLivros();}
                break;

            //Cadastrar livro
            case 6:
                system("cls");
                CadastrarLivro();

                break;
                
            //Pesquisar livro pelo nome
            case 7:
               { system("cls");

                char tituloEscolhido[tamanhoChars];
                char autor[tamanhoChars];
                char ano[tamanhoChars];


                printf("PESQUISAR LIVRO PELO TITULO: \n");
                printf("Informe o titulo do livro:   \n");
                fflush(stdin);
                scanf("%[^\n]", tituloEscolhido);

                encontrado = 0;

                for(int i = 0; i < maxIndiceLivros; i++)
                {
                    encontrado = PesquisarLivroPeloTitulo(i, tituloEscolhido, autor, ano);
                    if(encontrado == 0)
                    {
                        printf("LIVRO ENCONTRADO \n");
                        printf("    Codigo: %d   \n", i);
                        printf("    Titulo: %s     \n", tituloEscolhido);
                        printf("    Autor: %s \n", autor);
                        printf("    Ano: %s         \n", ano);
                        break;
                    }
                }

                if(encontrado == 1)
                {
                    printf("Nao encontrado!");
                }


                break;
                }
            //Excluir livro pelo codigo
            case 8:
             {   system("cls");
                code = -1;

                ListarLivros();

                printf("--------------------EXCLUIR LIVRO----------------------------\n");
                stop = 0;
                do
                {
                    printf("Qual o codigo do livro: (0-%d) \n", (ocupadoLivro-1));
                    fflush(stdin);
                    scanf("%d", &code);

                    int excluido = -1;
                    excluido = ExcluirLivroPeloCodigo(code);

                    switch (excluido) {
                        case 0:
                            printf("Excluido com sucesso! \n");
                            AlocadoOuNaoAlocadoMensagensLivros(livro);
                            stop = 1;
                            break;
                        case 1:
                            printf("Livro nao encontrado. \n");
                            stop = 1;
                            break;
                        case 2:
                            printf("Esse livro esta locado.   \n");
                            printf("Ele precisa ser devolvido antes de ser excluido. \n");
                            break;
                        default:
                            break;
                    }
                }
                while (stop != 1);
                
                break;}
            
            //Listar livros locados
            case 9:
               { system("cls");
                ListarLivrosLocados();
                break;
                }
            //locar livro
            case 10:
               { system("cls");

                ListarClientes();

                int locado = -1;
                int codeCliente = -1;
                int codeLivro = -1;

                char data_de_entrega[tamanhoChars];

                printf("Informe o codigo do cliente (0-%d): \n", (ocupadoCliente-1));
                fflush(stdin);
                scanf("%d", &codeCliente);

                ListarLivros();

                printf("Informe o codigo do livro para locar (0-%d): \n", (ocupadoLivro-1));
                fflush(stdin);
                scanf("%d", &codeLivro);

                printf("Informe a data de entrega: \n");
                fflush(stdin);
                scanf("%[^\n]", data_de_entrega);

                locado = LocarLivro (codeCliente, codeLivro, data_de_entrega);

                switch (locado) {
                    case 0:
                        printf("Locado com sucesso!");
                        break;

                    case 1:
                        printf("Este cliente ja tem livro locado.          \n");
                        printf("Ele precisa devolver antes de locar outro. \n");
                        break;

                    case 2:
                        printf("Este livro foi locado por outro cliente.");
                        break;

                    default:
                        break;
                }
                break;
}
            //Devolver livro pelo codigo do cliente
            case 11:
               { system("cls");
                do
                {
                    stop = 1;
                    ListarClientes();

                    printf("Informe o codigo do cliente: \n");
                    fflush(stdin);
                    scanf("%d", &code);

                    int resultadoDevolucao = DevolverLivro(code);

                    switch (resultadoDevolucao) {
                        case 0:
                            printf("Livro devolvido com sucesso!");
                            stop = 0;
                            break;
                        case 1:
                            printf("Este cliente nao tem livro locado!");
                            break;
                        case 2:
                            printf("Indice inexistente!");
                        default:
                            break;
                    }

                }
                while(stop != 0);
                break;}

            default:
               { system("cls");
                printf("ENTRADA INVALIDA");
                break;}
        }
    
    }
    while(menu != 0);

    FinalizarSistema();
    
    return 0;
}
