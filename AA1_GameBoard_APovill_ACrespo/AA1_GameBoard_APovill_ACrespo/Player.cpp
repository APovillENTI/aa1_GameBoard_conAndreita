#include <cstdio>
#include <cstdlib>
#include <iostream>


//Una función movePlayer que mueve al jugador a la siguiente casilla de dónde se encuentra dependiendo
//del tipo de PlayerMovement que se le pasa cómo parámetro.Reflexione(antes de programar) si la función también
//tiene que recibir cómo parámetro la posición dónde está el jugador o no.

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
            cout << "\nMovimiento inválido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 'd' || 'D':
        CheckMovement(player.position[][], input);
        if(CheckMovement(input))
            SetPosition(player, 0, 1);
        else
        {
            cout << "\nMovimiento inválido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 'w' || 'W':
        CheckMovement(player.position[][], input);
        if(CheckMovement(input))
            SetPosition(player, -1, 0);
        else
        {
            cout << "\nMovimiento inválido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    case 's' || 'S':
        if(CheckMovement(player.position[][], input))
            SetPosition(player, 1, 0);
        else
        {
            cout << "\nMovimiento inválido." << std::endl;
            MovePlayer(Player player);
        }
        break;
    default: 
        cout << "\nMovimiento inválido." << std::endl;
        MovePlayer(Player player);
    }
}

//Una función checkMovement que recibe dos parámetros : la posición del jugador en el tablero y el tipo de
//PlayerMovement que se desea hacer.Devuelve true si el movimiento es válido y false en caso contrario.
//Reflexione(antes de programar) que debe considerarse “movimiento válido”.

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

//Una función setPosition que actualiza la posición del jugador.Reflexione(antes de programar) qué
//parámetros debe tener esta función.

void SetPosition(Player& player, int moveY, int moveX)
{
    position[Player.posY][Player.posX] = ' '; //La posicion actual de la entidad pasa a estar vacía
    player.posX += moveX; //Se cambia el valor de las posiciones
    player.posY += moveY;
    ExistGema();
    position[Player.posY][Player.posX] = Player.symbol; //Se pone la entidad en la nueva posición
}

//Una función existGem que devuelve true si hay una gema en la siguiente casilla a la que debería moverse el
//jugador según el tipo de PlayerMovement que se la pasa cómo parámetro y false en caso contrario.
//Reflexione(antes de programar) si la función también tiene que recibir cómo parámetro la posición dónde está el jugador o no.

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

//Una función addScore que actualiza el score del jugador del jugador sumando 1.
//Reflexione(antes de programar) si ésta función tiene que tener o no parámetros.

void AddScore(Player& player)
{
    player.score++;
}

//Una función gameOver que verifica si en el tablero no quedan gemas o si el player ha pisado un pincho.
//Reflexione sobre qué tipo debe devolver la función.

void GameOver()
{
    if (countGemas == 0 || position[Player.posY][Player.posX] == 'M')
        DestroyBoard();
}