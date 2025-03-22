#include <cstdio>
#include <cstdlib>
#include <iostream>


//Una funci�n movePlayer que mueve al jugador a la siguiente casilla de d�nde se encuentra dependiendo
//del tipo de PlayerMovement que se le pasa c�mo par�metro.Reflexione(antes de programar) si la funci�n tambi�n
//tiene que recibir c�mo par�metro la posici�n d�nde est� el jugador o no.

void MovePlayer(Player& player)
{
    //DungeonCreator(position);
    char input;
    cout << "\nEscribe W, A, S o D para mover al jugador: " << std::endl;
    cin >> input;

    while (getchar() != '\n');
    PlayerAction(input,player);
}

void PlayerAction(char input, Player& player)
{
    switch (input)
    {
    case 'a' || 'A':
        CheckMovement(player.position[][], input);
        if(CheckMovement(input))
            SetPosition(player, 0, -1);
        else
        {
            cout << "\nMovimiento inv�lido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 'd' || 'D':
        CheckMovement(player.position[][], input);
        if(CheckMovement(input))
            SetPosition(player, 0, 1);
        else
        {
            cout << "\nMovimiento inv�lido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 'w' || 'W':
        CheckMovement(player.position[][], input);
        if(CheckMovement(input))
            SetPosition(player, -1, 0);
        else
        {
            cout << "\nMovimiento inv�lido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 's' || 'S':
        if(CheckMovement(player.position[][], input))
            SetPosition(player, 1, 0);
        else
        {
            cout << "\nMovimiento inv�lido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    default: 
        cout << "\nMovimiento inv�lido." << std::endl;
        MovePlayer(Player player);
    }
}

//Una funci�n checkMovement que recibe dos par�metros : la posici�n del jugador en el tablero y el tipo de
//PlayerMovement que se desea hacer.Devuelve true si el movimiento es v�lido y false en caso contrario.
//Reflexione(antes de programar) que debe considerarse �movimiento v�lido�.

bool CheckMovement(int pos[][], char PlayerMovement)
{
    switch (input)
    {
    case 'a' || 'A':
        if (position[posX][posY - 1] != PARED)
            return true;
        else
            return false;
    case 'd' || 'D':
        if (position[posX][posY + 1] != PARED)
            return true;
        else
            return false;
    case 'w' || 'W':
        if (position[posX - 1][posY] != PARED)
            return true;
        else
            return false;
    case 's' || 'S':
        if (position[posX + 1][posY] != PARED)
            return true;
        else
            return false;
    }
}

//Una funci�n setPosition que actualiza la posici�n del jugador.Reflexione(antes de programar) qu�
//par�metros debe tener esta funci�n.

void SetPosition(Player& player, int moveY, int moveX)
{
    position[Player.posY][Player.posX] = ' '; //La posicion actual de la entidad pasa a estar vac�a
    player.posX += moveX; //Se cambia el valor de las posiciones
    player.posY += moveY;
    ExistGema();
    position[Player.posY][Player.posX] = Player.symbol; //Se pone la entidad en la nueva posici�n
}

//Una funci�n existGem que devuelve true si hay una gema en la siguiente casilla a la que deber�a moverse el
//jugador seg�n el tipo de PlayerMovement que se la pasa c�mo par�metro y false en caso contrario.
//Reflexione(antes de programar) si la funci�n tambi�n tiene que recibir c�mo par�metro la posici�n d�nde est� el jugador o no.

bool ExistGem()
{
    if (player.position[player.posX][player.posY] == GEMA)
    {
        player.position[player.posX][player.posY] = VACIO;
        AddScore();
        return true;
    }
    else
        return false;
}

//Una funci�n addScore que actualiza el score del jugador del jugador sumando 1.
//Reflexione(antes de programar) si �sta funci�n tiene que tener o no par�metros.

void AddScore(Player& player)
{
    player.score++;
}

//Una funci�n gameOver que verifica si en el tablero no quedan gemas o si el player ha pisado un pincho.
//Reflexione sobre qu� tipo debe devolver la funci�n.

void GameOver()
{
    if (countGemas == 0 || position[Player.posY][Player.posX] == 'M')
        DestroyBoard();
}