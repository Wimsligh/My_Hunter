/*
** EPITECH PROJECT, 2022
** My_Hunter
** File description:
** My_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void if_click_2(sfRenderWindow* window,sfMouseButtonEvent mouse,info_t *cannard)
{
    sfTexture* anim;
    sfSprite* sprite;
    anim = sfTexture_createFromFile("Picture/Anim.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, anim, sfTrue);

    if (mouse.x <= cannard->canard_pos.x + 110 &&
    mouse.x >= cannard->canard_pos.x)
        if (mouse.y <= cannard->canard_pos.y + 110 &&
        mouse.y >= cannard->canard_pos.y) {
            sfSprite_setPosition(sprite,cannard->canard_pos);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            cannard->duck++;
            my_printf("Duck shoot : %d\n",cannard->duck);
        }
}

void if_click(sfRenderWindow* window,sfEvent event, info_t *cannard)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 816 && mouse.x <= 1062 && mouse.x >= 816 &&
    mouse.x <= 1062) {
            launch_game(window,event, cannard);
    }
}

int hunter(void)
{
    sfVideoMode mode = {1920,1080, 64};
    sfRenderWindow* window;
    sfEvent event;
    info_t cannard = struct_param_game(window,event);
    info_t start = struct_param_game_4(window,event);
    info_t lobby = struct_param_game_3(window,event);
    sfSprite_setScale(lobby.sprite, start.scale);
    sfSprite_setScale(start.sprite, start.scale_boutton);
    sfSprite_setPosition(start.sprite, start.pos_boutton);

    window = sfRenderWindow_create(mode, "Matheo Hunter", sfResize |
    sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        launch_game_2(window,event, 0, &cannard);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, lobby.sprite, NULL);
        sfRenderWindow_drawSprite(window, start.sprite, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}

int main(int argc,char **argv)
{
    if (argc == 1) {
        hunter();
    }
    if (argc == 2) {
        my_printf("Matheo Hunter et un jeu basé sur un tir au canard\n");
        my_printf("Click Gauche : Start,Tir");
    }
}
