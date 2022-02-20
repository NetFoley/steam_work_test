using namespace std;

#include <iostream>
#include <conio.h>
#include "SteamNetwork.h"

SteamNetwork steam_network;

void _process();

int main()
{
    cout << "start" << endl;
    if (!steam_network.get_steam_status()) { // init steam api
        cout << "steam ok" << endl;
        steam_network.display_user_information();
        //steam_network.open_overlay("steamid"); // ActivateGameOverlay will not work and callbacks will never be called due to project console application
        steam_network.display_friends();

        steam_network.create_lobby(k_ELobbyTypePublic, 5); //Then give the CSteamID to the other person, PUBLIC Lobby, Max 5 members
        steam_network.search_lobbies();
        steam_network.leave_lobby();

        _process();
    }
    return 0;
}

void _process() {
    while (1)
    {
        SteamAPI_RunCallbacks(); //Used to get all responses from Steam Callbacks, usually return a pCallBack
    };
}