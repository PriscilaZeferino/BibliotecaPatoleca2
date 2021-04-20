#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifndef dados_h
#define dados_h

int RecuperarTamanhoChars (void);

int RecuperarMaxIndiceClientes(void);
int RecuperarMaxIndiceLivros(void);

int RecuperarOcupadoClientes(void);
int RecuperarOcupadoLivros(void);

int AlocarMemoriaClientes(void);
int RealocarMemoriaClientes(void);

int AlocarMemoriaLivros (void);
int RealocarMemoriaLivros(void);

int limparArraysClientes(void);
int limparArraysLivros(void);
void InicializarArrays(void);

void AtualizarMaxIndiceClientes(void);
void AtualizarMaxIndiceLivros(void);

void ObterDadosCliente(int i, char name[], char phone[],char cpf[]);
void ObterDadosLivros(int i, char titulo[], char autor[],char ano[]);
int  ObterDadosLivrosLocados(int i, char titulo[], char autor[],char ano[]);

int CadastrarNovoCliente(int i, char name[], char phone[], char cpf[]);
int CadastrarNovoLivro(int i, char titulo[], char autor[], char ano[]);

int PesquisarClientePeloNome(int code, char nomeEscolhido[], char cpf[], char phone[]);
int PesquisarLivroPeloTitulo (int code, char tituloEscolhido[], char autor[], char ano[]);

int ExcluirClientePeloCodigo(int code);
int ExcluirLivroPeloCodigo(int code);

int LocarLivro (int codeCliente, int codeLivro, char data_de_entrega[]);
int DevolverLivro(int code);

int AbrirArquivoParaEscritaClientes(void);
int SalvarListaClientes(void);
int AbrirArquivoParaLeituraClientes(void);
int LerListaClientes(void);
void FecharClientes(void);

int AbrirArquivoParaEscritaLivros (void);
int SalvarListaLivros(void);
int AbrirArquivoParaLeituraLivros(void);
int LerListaLivros(void);
void FecharLivros(void);

int verificarTamanhoArquivoClientes(void);
int verificarTamanhoArquivoLivros(void);

int LerArquivos(void);
int FinalizarSistema(void);


#endif /* dados_h */


