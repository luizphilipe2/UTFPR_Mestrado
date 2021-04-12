#include "stdio.h"

typedef struct{
   int dia;
   int mes;
   int ano;
} Data;

typedef struct{ 
   int RA;  
   char nome[100];
   double notas[3];
   Data dataNascimento;
} Aluno;


void cadastrarAluno(Aluno *a, int posicao){
   printf("Insira o RA do aluno \n");
   scanf(" %i", &a[posicao].RA);

   printf("Insira o nome do aluno \n");
   scanf(" %s", a[posicao].nome);

   for (int i = 0; i < 3; i++){
      printf("Insira a nota numero %i do aluno \n", i+1);
      scanf( "%lf", &a[posicao].notas[i]);
   }

   printf("Insira o dia de nascimento do aluno \n");
   scanf(" %i", &a[posicao].dataNascimento.dia);

   printf("Insira o mes de nascimento do aluno \n");
   scanf(" %i", &a[posicao].dataNascimento.mes);

   printf("Insira o ano de nascimento do aluno \n");
   scanf(" %i", &a[posicao].dataNascimento.ano);

   printf("Aluno cadastrado com sucesso!!! \n");
}

double media(double notas[3]){
   double soma = notas[0] + notas[1] + notas[2];
   return soma/3;
}

void listarNomesMedias(Aluno *a, int quantidadeAlunos){
   for (int i = 0; i < quantidadeAlunos; i++)
      printf("Aluno: %s | Média: %.2lf \n", a[i].nome, media(a[i].notas));
}

void listarAlunosMaiorQueAno(Aluno *a, int quantidadeAlunos, int ano){
   for (int i = 0; i < quantidadeAlunos; i++)
      if(a[i].dataNascimento.ano > ano)
         printf("Aluno: %s | Data de nascimento: %i/%i/%i \n", a[i].nome, a[i].dataNascimento.dia, a[i].dataNascimento.mes, a[i].dataNascimento.ano);
}


int main(){
   int opcao = 0;
   int anoBusca = 0;
   int qtdAlunosCadastrados = 0;
   int maxAlunos = 20;
   Aluno alunos[maxAlunos];

   do { 
      printf("Quantidade de alunos cadastrados: %i \nNúmero máximo de alunos possí­veis: %i \n", qtdAlunosCadastrados, maxAlunos);

      printf("\n \nInsira uma opção: \n");
      printf("1 - Inserir um novo aluno: RA, nome, vetor com 3 notas e data de nascimento (use aninhamento de estruturas); \n");
      printf("2 - Listar os nomes e as mÃ©dias das notas de todos os alunos; \n");
      printf("3 - Listar os nomes dos alunos que nasceram depois de um certo ano. \n");
      printf("Para sair, digite qualquer outro número\n");
      scanf(" %i", &opcao);
      switch(opcao){

         case 1: 
         if (qtdAlunosCadastrados == maxAlunos){
            printf("Número máximo de alunos já cadastrado. \n");
            break;
         }

         cadastrarAluno(alunos, qtdAlunosCadastrados);
         qtdAlunosCadastrados++;
         break;

         case 2: 
         listarNomesMedias(alunos, qtdAlunosCadastrados);
         break;

         case 3: 
         printf("Insira o ano da busca: ");
         scanf( "%i", &anoBusca);
         listarAlunosMaiorQueAno(alunos, qtdAlunosCadastrados, anoBusca);
         break;

         default: opcao = 0;
         
      }
   
    } while (opcao != 0);

}