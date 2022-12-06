/*
** EPITECH PROJECT, 2022
** Launch_game
** File description:
** Launch_game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System.h>
#include "include/my.h"

void launch_game(sfRenderWindow* window, sfEvent event, info_t *cannard)
{
    info_t back = struct_param_game_2(window,event);
    sfClock *clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        launch_game_3(window,event, cannard, &clock);
        if (cannard->canard_pos.x > 1920) {
            cannard->canard_pos.x = 0;
        }
        if (cannard->canard_pos.x < 0)
            cannard->velocity.x = 0.1;
        cannard->canard_pos.x += cannard->velocity.x;
        sfSprite_setPosition(cannard->sprite, cannard->canard_pos);
        sfRenderWindow_clear(window, sfWhite);
        sfSprite_setTextureRect(cannard->sprite,cannard->rect);
        sfRenderWindow_drawSprite(window, back.sprite, NULL);
        sfRenderWindow_drawSprite(window, cannard->sprite, NULL);
        while (sfRenderWindow_pollEvent(window, &event)) {
            launch_game_4(window,event, cannard);
        }
        sfRenderWindow_display(window);
    }
}
