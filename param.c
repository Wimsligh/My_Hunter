/*
** EPITECH PROJECT, 2022
** param
** File description:
** param
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

info_t struct_param_game_4(sfRenderWindow* window,sfEvent event)
{
    info_t start;
    start.texture = sfTexture_createFromFile("Picture/bouton-start.png", NULL);
    start.sprite = sfSprite_create();
    start.scale = (sfVector2f){1.12, 1.12};
    start.scale_boutton = (sfVector2f){0.50,0.50};
    start.pos_boutton = (sfVector2f){800,500};
    sfSprite_setTexture(start.sprite, start.texture, sfTrue);

    return start;
}

info_t struct_param_game_3(sfRenderWindow* window,sfEvent event)
{
    info_t lobby;
    lobby.texture = sfTexture_createFromFile("Picture/Fond.jpeg", NULL);
    lobby.sprite = sfSprite_create();
    sfSprite_setTexture(lobby.sprite, lobby.texture, sfTrue);

    return lobby;
}

info_t struct_param_game_2(sfRenderWindow* window,sfEvent event)
{
    info_t back;
    back.texture = sfTexture_createFromFile("Picture/In_game.jpeg", NULL);
    back.sprite = sfSprite_create();
    sfSprite_setTexture(back.sprite, back.texture, sfTrue);

    return back;
}

info_t struct_param_game(sfRenderWindow* window,sfEvent event)
{
    info_t cannard;
    cannard.texture = sfTexture_createFromFile("Picture/Sprite.png", NULL);
    cannard.sprite = sfSprite_create();
    cannard.size_canard = (sfVector2f){1.5,1.5};
    cannard.velocity = (sfVector2f){0.1};
    cannard.canard_pos = (sfVector2f){500,400};
    cannard.rect = (sfIntRect){0, 0, 110, 110};
    cannard.duck = 0;
    sfSprite_setTexture(cannard.sprite, cannard.texture, sfTrue);
    sfSprite_setScale(cannard.sprite, cannard.size_canard);
    sfSprite_setPosition(cannard.sprite,cannard.canard_pos);

    return cannard;
}
