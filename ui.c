#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

typedef struct _departamento
{
    char nome[MAX_CHARS_INPUT];
    int id_departamento;
} Departamento;

typedef struct _funcionario
{
    int id_funcionario;
    char nome[MAX_CHARS_INPUT];
    char cargo[MAX_CHARS_INPUT];
    char departamento[MAX_CHARS_INPUT];
    int asset;
} Funcionario;

typedef struct _assets
{
    int id_asset;
    char marca[MAX_CHARS_INPUT];
    char modelo[MAX_CHARS_INPUT];
} Assets;

Assets filial_lisboa[MAX_ASSETS];                  //Foi criada uma estrutura assets com o nome filial_lisboa onde vão estar inseridos os assets criados no programa.
Funcionario funcionarios_lisboa[MAX_FUNCIONARIOS]; //Foi criada uma estrutura funcionario com o nome funcionarios_lisboa onde vão estar inseridos os funcionarios criados no programa.
Departamento departamentos_lisboa[MAX_INPUT];      //Foi criada uma estrutura departamento com o nome departamentos_lisboa onde vão estão inseridos os departamentos pré-criados.

//Criei dois contadores de forma a possibilitar os for loops que percorrem o counter e apresentam as estruturas preenchidas.
int counter_assets = 0;
int counter_funcionarios = 0;

//FUNÇÕES DE APOIO ÀS ESTRUTURAS

int marca_asset()
{

    int marca;
    do
    {
        puts("Escolha uma marca   1 ACER | 2 APPLE | 3 ASUS | 4 HP | 5 LENOVO");
        marca = pedeInteiro("Escolha uma marca");
    } while (marca < 1 || marca > 5);
    return marca;
}

int departamentos()
{
    int departamentos;
    departamentos_lisboa[1].id_departamento = 1;
    strcpy(departamentos_lisboa[1].nome, "IT");
    departamentos_lisboa[2].id_departamento = 2;
    strcpy(departamentos_lisboa[2].nome, "RH");
    departamentos_lisboa[3].id_departamento = 3;
    strcpy(departamentos_lisboa[3].nome, "CONTABILIDADE");

    do
    {
        puts("Departamentos da Filial de Lisboa   1 IT | 2 RH | 3 Contabilidade");
        departamentos = pedeInteiro("Escolha um departamento");
    } while (departamentos != 1 && departamentos != 2 && departamentos != 3);

    return departamentos;
}

//MENUS

int menu_principal()
{
    int input;

    do
    {
        system("clear");
        puts("//////////////////////////////////");
        puts("||Bem vindo ao ASSET MANAGER 1.0||");
        puts("//////////////////////////////////\n");
        puts("Escolha uma das seguntes funções:");
        puts("(1)Gestão assets");
        puts("(2)Gestão funcionários");
        puts("(3)Impressão report de assets");
        puts("(4)Impressão report de funcionarios e assets atribuídos");
        puts("(5)Sobre o Asset Manager 1.0");
        puts("-----------------------------------");
        input = pedeInteiro("Insira a opção pretendida");
    } while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5);
    return input;
}


void gerir_assets()
{
    int input_gestao_assets;
    do
    {
        puts("/////////////////////////");
        puts("||MENU GESTÃO DE ASSETS||");
        puts("/////////////////////////\n");
        puts("(1)Criar assets");
        puts("(2)Visualizar assets");
        puts("(3)Mudar para Menu gestão de funcionários");
        puts("(0)Voltar ao menu inicial");
        input_gestao_assets = pedeInteiro("Introduza a sua escolha");
        system("clear");

        switch (input_gestao_assets)
        {
        case 1:
            criar_assets();
            break;

        case 2:
            banner_visualizacao_assets();
            resumo_assets();
            visualizar_assets();
            return_para_menu_inicial();
            break;

        case 3:
            gerir_funcionarios();
            break;

        case 0:
            return;
            break;
        }
    } while (input_gestao_assets != 1 && input_gestao_assets != 2 && input_gestao_assets != 3 && input_gestao_assets != 0);
    return;
}

void gerir_funcionarios()
{
    int input_gestao_funcionarios;

    do
    {
        puts("////////////////////////////");
        puts("||MENU GESTÃO FUNCIONÁRIOS||");
        puts("////////////////////////////\n");
        puts("Escolha uma das seguntes funções:");
        puts("(1)Criar funcionário");
        puts("(2)Visualizar funcionários");
        puts("(3)Atribuir assets a funcionários");
        puts("(4)Mudar para Menu gestão de assets");
        puts("(0)Voltar ao menu inicial");
        input_gestao_funcionarios = pedeInteiro("Introduza a sua escolha");
        system("clear");

        switch (input_gestao_funcionarios)
        {
        case 1:
            criar_funcionarios();
            break;

        case 2:
            banner_visualizacao_funcionarios();
            resumo_funcionarios();
            visualizar_funcionarios();
            prompt_return_menu_inicial();
            break;

        case 3:
            atribuir_assets();

            break;

        case 4:
            gerir_assets();
            break;

        case 0:
            return;
            break;
        }

    } while (input_gestao_funcionarios != 1 && input_gestao_funcionarios != 2 && input_gestao_funcionarios != 3 && input_gestao_funcionarios != 0);
    return;
}

void about_asset_manager()
{
    puts("O Asset Manager 1.0 é um programa criado na linguagem de programação C.");
    puts("Tem como objetivo ajudar as empresas na árdua tarefa de gerir todos os\ncomputadores da mesma,atribuindo-os a cada funcionários e permitindo\nsaber a um determinado instante quantos existem e a quem estão alocados.");
    puts("De momento é possível exportar para .txt relatórios de Assets e Funcionários com Assets atribuídos.");
    puts("\nAutor: Paulo Jorge - CISEG 1021 - ATEC");
    prompt_return_menu_inicial();
}

//ASSETS

void criar_assets()
{
    int input_asset;
    system("clear");
    puts("////////////////////");
    puts("||ADICIONAR ASSETS||");
    puts("////////////////////\n");

    filial_lisboa[counter_assets].id_asset = counter_assets;
    input_asset = marca_asset();
    switch (input_asset)
    {
    case 1:
        strcpy(filial_lisboa[counter_assets].marca, "ACER");
        break;

    case 2:
        strcpy(filial_lisboa[counter_assets].marca, "APPLE");
        break;

    case 3:
        strcpy(filial_lisboa[counter_assets].marca, "ASUS");
        break;

    case 4:
        strcpy(filial_lisboa[counter_assets].marca, "HP");
        break;

    case 5:
        strcpy(filial_lisboa[counter_assets].marca, "LENOVO");
        break;
    }
    pedeString("Insira modelo do asset", filial_lisboa[counter_assets].modelo, MAX_CHARS_INPUT);
    system("clear");
    puts("///////////////////////////////");
    puts("||ASSET ADICONADO COM SUCESSO||");
    puts("///////////////////////////////\n");
    puts("Pressione enter para voltar ao menu inicial");
    getchar();

    counter_assets++;
}

void visualizar_assets()
{
    for (int i = 0; i < counter_assets; i++)
    {
        printf("ID: %d \n", filial_lisboa[i].id_asset);
        printf("Marca: %s \n", filial_lisboa[i].marca);
        printf("Modelo: %s \n", filial_lisboa[i].modelo);
        puts("--------------");
    }
    return;
}

void resumo_assets()
{
    if (counter_assets == 0)
    {
        puts("Não existem assets no ASSET MANAGER, de momento");
    }
    else
    {
        puts("Resumo ASSET MANAGER 1.0 - ASSETS");
        printf("De momento existem %d assets inseridos no Asset Manager 1.0\n", counter_assets);
        puts("----------------------------------\n");
    }
}

int impressao_assets()
{

    if (counter_assets == 0)
    {
        puts("||||||||||ERRO||||||||||");
        puts("Não existem assets inseridos de momento.");
        puts("Por favor introduza assets através do menu (1)Gestão assets.");
        prompt_return_menu_inicial();
    }
    else
    {
        printf("Impressão realizada com sucesso!\nO ficheiro de destino é Report_assets.txt");
        prompt_return_menu_inicial();
        FILE *assets_pointer = fopen("Report_assets.txt", "w+");
        {
            fprintf(assets_pointer, "Resumo ASSET MANAGER 1.0 - ASSETS\n");
            fprintf(assets_pointer, "De momento existem %d assets inseridos no Asset Manager 1.0\n", counter_assets);
            fprintf(assets_pointer, "----------------------------------\n");

            for (int i = 0; i < counter_assets; i++)
            {
                fprintf(assets_pointer, "ID: %d \n", filial_lisboa[i].id_asset);
                fprintf(assets_pointer, "Marca: %s \n", filial_lisboa[i].marca);
                fprintf(assets_pointer, "Modelo: %s \n", filial_lisboa[i].modelo);
                fprintf(assets_pointer, "----------------\n");
            }
            fclose(assets_pointer);
        }
    }
    return 0;
}

//FUNCIONARIOS

void criar_funcionarios()
{
    int input_departamento;
    puts("/////////////////////////");
    puts("||ADICIONAR FUNCIONARIO||");
    puts("/////////////////////////\n");

    funcionarios_lisboa[counter_funcionarios].id_funcionario = counter_funcionarios;
    pedeString("Insira o nome do funcionario", funcionarios_lisboa[counter_funcionarios].nome, MAX_CHARS_INPUT);
    input_departamento = departamentos();

    switch (input_departamento)
    {
    case 1:
        strcpy(funcionarios_lisboa[counter_funcionarios].departamento, departamentos_lisboa[1].nome);
        break;

    case 2:
        strcpy(funcionarios_lisboa[counter_funcionarios].departamento, departamentos_lisboa[2].nome);
        break;

    case 3:
        strcpy(funcionarios_lisboa[counter_funcionarios].departamento, departamentos_lisboa[3].nome);
        break;
    }

    funcionarios_lisboa[counter_funcionarios].asset = -1;

    system("clear");
    puts("/////////////////////////////////////");
    puts("||FUNCIONÁRIO ADICONADO COM SUCESSO||");
    puts("//////////////////////////////////////\n");
    puts("Pressione enter para voltar ao menu inicial");
    getchar();
    counter_funcionarios++;
}

void visualizar_funcionarios()
{
    for (int i = 0; i < counter_funcionarios; i++)
    {
        printf("ID: %d \n", funcionarios_lisboa[i].id_funcionario);
        printf("Nome: %s \n", funcionarios_lisboa[i].nome);
        printf("Departamento: %s \n", funcionarios_lisboa[i].departamento);

        if (funcionarios_lisboa[i].asset == -1)
        {
            printf("Asset atribuído (ID): Sem asset atribuído\n");
        }
        else
        {
            printf("Asset atribuído (ID): %d\n", funcionarios_lisboa[i].asset);
            printf("Asset atribuído (Marca e modelo): %s %s\n", filial_lisboa[funcionarios_lisboa[i].asset].marca, filial_lisboa[funcionarios_lisboa[i].asset].modelo);
        }

        printf("----------------\n");
    }
}

void resumo_funcionarios()
{
    if (counter_funcionarios == 0)
    {
        puts("Não existem funcionários no ASSET MANAGER, de momento");
    }
    else
    {
        puts("Resumo ASSET MANAGER 1.0 - FUNCIONARIOS");
        printf("De momento existem %d funcionarios inseridos no Asset Manager 1.0\n", counter_funcionarios);
        puts("----------------------------------\n");
    }
}

void atribuir_assets()
{
    int escolha_asset, escolha_funcionario;

    if (counter_funcionarios == 0 || counter_assets == 0)
    {
        printf("O Asset Manager não tem, de momento, assets e funcionários inseridos.\nDeve introduzir pelo menos 1 funcionário e 1 asset.\n");
        printf("De momento a DB do Asset Manager 1.0 tem %d assets e %d funcionários inseridos.", counter_assets, counter_funcionarios);
        prompt_return_menu_inicial();
    }
    else
    {
        banner_visualizacao_assets();
        visualizar_assets();
        banner_visualizacao_funcionarios();
        visualizar_funcionarios();
        escolha_asset = pedeInteiro("Escolha um asset para atribuir a um funcionário");
        
        while (escolha_asset >= counter_assets)
        {
            puts("Asset não disponível - verifique o ID do asset");
            escolha_asset = pedeInteiro("Escolha um asset para atribuir a um funcionário");
        }
        
        escolha_funcionario = pedeInteiro("Escolha um funcionário");

        while (escolha_funcionario >= counter_funcionarios)
        {
            puts("Funcionário não disponível - verifique o ID do funcionário ao qual pretende atribuir um asset");
            escolha_funcionario = pedeInteiro("Escolha um funcionário");
        }

        funcionarios_lisboa[escolha_funcionario].asset = escolha_asset;

        printf("\nOperação concluída com sucesso!\n");
        printf("\nLista de funcionários actualizada:\n");
        visualizar_funcionarios();
        getchar();
        submenu_atribuir_assets();
        }
    }

int submenu_atribuir_assets()
{
    int input;
    do
    {
        puts("Escolha uma das seguntes funções:");
        puts("(1)Atribuir outro asset");
        puts("(2)Regressar ao menu principal");
        input=pedeInteiro("Insira a opção pretendida ");
        switch (input)
        {
        case 1:
            atribuir_assets();
            break;

        case 2:
            menu_principal();
            break;
        }
    } while (input != 1 && input != 2 && input != 3);
    return input;
}

int impressao_funcionarios()
{
    if (counter_assets == 0 || counter_funcionarios == 0)
    {
        puts("||||||||||ERRO||||||||||");
        puts("Não existem assets nem funcionários inseridos de momento.");
        puts("Por favor introduza assets através dos menus (1)Gestão assets e (2)Gestão funcionários.");
        prompt_return_menu_inicial();
    }
    else
    {
        printf("Impressão realizada com sucesso!\nO ficheiro de destino é Report_funcionarios_e_assets.txt");
        prompt_return_menu_inicial();
        FILE *funcionarios_pointer = fopen("Report_funcionarios_e_assets.txt", "w+");
        {
            fprintf(funcionarios_pointer, "Resumo ASSET MANAGER 1.0 - FUNCIONARIOS\n");
            fprintf(funcionarios_pointer, "De momento existem %d funcionarios e %d assets inseridos no Asset Manager 1.0\n", counter_funcionarios, counter_assets);
            fprintf(funcionarios_pointer, "----------------------------------\n");
            for (int i = 0; i < counter_funcionarios; i++)
            {
                fprintf(funcionarios_pointer, "ID: %d \n", funcionarios_lisboa[i].id_funcionario);
                fprintf(funcionarios_pointer, "Nome: %s \n", funcionarios_lisboa[i].nome);
                fprintf(funcionarios_pointer, "Departamento: %s \n", funcionarios_lisboa[i].departamento);

                if (funcionarios_lisboa[i].asset == -1)
                {
                    fprintf(funcionarios_pointer, "Asset atribuído (ID): Sem asset atribuído\n");
                }
                else
                {
                    fprintf(funcionarios_pointer, "Asset atribuído (ID): %d\n", funcionarios_lisboa[i].asset);
                    fprintf(funcionarios_pointer, "Asset atribuído (Marca e modelo): %s %s\n", filial_lisboa[funcionarios_lisboa[i].asset].marca, filial_lisboa[funcionarios_lisboa[i].asset].modelo);
                    fprintf(funcionarios_pointer, "----------------\n");
                }
            }
            fclose(funcionarios_pointer);
        }
    }
    return 0;
}



void banner_visualizacao_assets()
{
    puts("///////////////////////////");
    puts("||REPORT GESTÃO DE ASSETS||");
    puts("///////////////////////////\n");
}

void banner_visualizacao_funcionarios()
{
    puts("/////////////////////////////////");
    puts("||REPORT GESTÃO DE FUNCIONARIOS||");
    puts("/////////////////////////////////\n");
}

void return_para_menu_inicial()
{
    printf("\n\n\n\nPressione enter para regressar ao menu inicial\n");
    getchar();
}

void prompt_return_menu_inicial()
{
    printf("\n\n\n\nPressione enter para regressar ao menu inicial\n");
    getchar();
    return;
}


//Funções extra

int pedeInteiro(char *pergunta)
{
    char aux[MAX_INPUT];
    //int opt;
    memset(aux, '\0', MAX_INPUT);
    printf("%s-> ", pergunta);
    fgets(aux, MAX_INPUT - 1, stdin);
    //sscanf(aux,"%d",&opt);
    //return opt;
    return atoi(aux); //transforma string em inteiro
}

double pedeDouble(char *pergunta)
{
    char aux[MAX_INPUT];
    double opt;
    memset(aux, '\0', MAX_INPUT);
    printf("%s-> ", pergunta);
    fgets(aux, MAX_INPUT - 1, stdin);
    sscanf(aux, "%lf", &opt);
    return opt;
}

void pedeString(char *pergunta, char *resposta, int max)
{
    char aux[MAX_INPUT];
    memset(aux, '\0', MAX_INPUT);
    printf("%s-> ", pergunta);
    fgets(aux, MAX_INPUT - 1, stdin);
    aux[strlen(aux) - 1] = '\0'; //Retirar um último caracter
    strncpy(resposta, aux, max);
    return;
}
