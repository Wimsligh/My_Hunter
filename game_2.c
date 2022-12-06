/*
** EPITECH PROJECT, 2022
** game_2
** File description:
** game_2
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void launch_game_3(sfRenderWindow* window,sfEvent event,
info_t *cannard, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        cannard->rect.left = cannard->rect.left + 110;
        if (cannard->rect.left > 310)
        cannard->rect.left = 0;
        sfClock_restart(clock);
    }
}

void launch_game_4(sfRenderWindow* window,sfEvent event,info_t *cannard)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if_click_2(window, event.mouseButton, cannard);
        }
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
}

void launch_game_2(sfRenderWindow* window,sfEvent event,
int test,info_t *cannard)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed
        && test == 0) {
            if_click(window, event, cannard);
        }
    }
}
