#ifndef UI_H
#define UI_H
#define MAX_INPUT 256
#define MAX_CHARS_INPUT 256
#define true 1
#define false 0

//Definição do tamanho das estruturas
//Criação da estrturua Filial Lisboa, filial_lisboa, como "container" dos assets e subsequentemente de funcionários e departamentos.
//Criação da estrutura funcionarios_lisboa como "container" dos funcionários.
//Criei um contador para ambas as estruturas de forma a identificar quais estão livres e ocupadas.

#define MAX_ASSETS 10
#define MAX_FUNCIONARIOS 10


/**
* Função que atribui a cada um dos inputs possíveis 1,2,3,4 ou 5 as respetivas marcas ACER, APPLE, ASUS, HP ou LENOVO.
**/
int marca_asset();

/**
* Função que atribui a cada um dos inputs possíveis 1,2 ou 3 os respetivos departamentos IT, RH ou CONTABILIDADE.
**/
int departamentos();

/**
*Função de menu principal inserido num ciclo de forma a que o input seja um dos desejados, de 1 a 4, para transitar para outro menu
*ou o menu continuará num loop infinito para QoL.
**/
int menu_principal();

/**
*Submenu para opções de gestão de assets.
**/
void gerir_assets();

/**
*Submenu para opções de gestão de funcionarios.
**/
void gerir_funcionarios();

/**
*Submenu de ajuda ao utilizador do programa Asset Manager 1.0
**/
void about_asset_manager();

/**
*Esta função permite ao utilizar criar um asset, escolhendo uma de 5 marcas e permitindo a introdução manual de um modelo.
**/
void criar_assets();

/**
*Esta função imprime a listagem de assets: ID, marca e modelo.
**/
void visualizar_assets();

/**
*Função que imprime o contador counter_assets, permitindo ao end user visualizar o estado do programa ao nível de assets
**/
void resumo_assets();

/**
*Esta função imprime para o "Report_assets.txt" a listagem de todos os assets no programa.
*Sempre que a função é chamado o ficheiro é limpo, não ficando registo anterior.
**/
int impressao_assets();

/**
*Esta função permite ao utilizar criar um funcionário introduzindo um nome, à escolha do utilizador e a escolha de 1 de 3 departamentos: IT, RH ou Contabilidade.
**/
void criar_funcionarios();

/**
*Mostra a listagem de funcionários e o respetivo asset atribuído. Se o asset for == -1 = nao atribuido = imprime texto.
**/
void visualizar_funcionarios();

/**
*Função que imprime o contador counter_funcionarios, permitindo ao end user visualizar o estado do programa ao nível de funcionarios.
**/
void resumo_funcionarios();

/**
*Esta função permite atribuir assets a funcionários. Só funciona se no programa estiverem inseridos de antemão assets e funcionários.
*Verifica o input do user com 2 while's - um para assets e outro para funcionários.
**/
void atribuir_assets();

/**
*QoL submenu para inserir mais que 1 asset sem ter de retornar ao menu principal.
**/
int submenu_atribuir_assets();

/**
*Esta função imprime para o "Report funcionarios_e_assets.txt" a listagem de todos os funcionários e respetivos assets atribuídos.
*Sempre que a função é chamado o ficheiro é limpo, não ficando registo anterior.
**/
int impressao_funcionarios();

/**
*Função criada para efeitos de QoL do programa.
**/
void banner_visualizacao_assets();

/**
*Função criada para efeitos de QoL do programa.
**/
void banner_visualizacao_funcionarios();

/**
*Função criada para efeitos de QoL do programa.
**/
void prompt_return_menu_inicial();

/**
*Função criada para efeitos de QoL do programa.
**/
void return_para_menu_inicial();

/**
*Função facultada pelo professor. Pede um inteiro ao utilizador e guarda na variável escolhida.
**/
int pedeInteiro(char *pergunta);

/**
*Função facultada pelo professor. Pede um double ao utilizador e guarda na variável escolhida.
**/
double pedeDouble(char *pergunta);

/**
*Função facultada pelo professor. Pede uma string ao utilizador e guarda na variável escolhida.
**/
void pedeString(char *pergunta, char *resposta, int max);

int imprimir_report();











#endif
