// RPG.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <steam/steam_api.h>

int main()
{
    SteamAPI_Init();

    std::cout << "Hello World!\n";
}

