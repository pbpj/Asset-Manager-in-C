#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

int main(int argc, char const *argv[])
{
    int input;

    do
    {
        input = menu_principal();
        system("clear");
        switch (input)
        {
        case 1:
            gerir_assets();
            break;

        case 2:
            gerir_funcionarios();
            break;

        case 3:
            impressao_assets();
            break;

        case 4:
            impressao_funcionarios();
            break;

        case 5:
            about_asset_manager();
            break;

        default:
            break;
        }
    } while (1);

    return 0;
}
