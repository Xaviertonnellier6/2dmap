/*
** EPITECH PROJECT, 2020
** my_2d
** File description:
** first
*/

#include "game.h"

int ch_move(sfRenderWindow *window, sfVector2f *map_pos, sfVector2f *dino_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (map_pos->x <= 0) map_pos->x += 1.5;
        else
            if (dino_pos->x >= 30) dino_pos->x -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (map_pos->x >= -430) map_pos->x -= 1.5;
        else
            if (dino_pos->x <= 990) dino_pos->x += 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (map_pos->y <= 0) map_pos->y += 1.5;
        else
            if (dino_pos->y >= 30) dino_pos->y -= 1.5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (map_pos->y >= -300) map_pos->y -= 1.5;
        else
            if (dino_pos->y <= 570) dino_pos->y += 1.5;
    }
}

int my_perso(sfRenderWindow *window, sfVector2f center)
{
    sfTexture *back = sfTexture_createFromFile("pic/dino.png", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f sprite_size = {0.2, 0.2};
    sfSprite_setPosition(my_spr, center);
    sfSprite_scale(my_spr, sprite_size);

    sfSprite_setTexture(my_spr, back, sfTrue);
    sfRenderWindow_drawSprite(window, my_spr, NULL);
    sfTexture_destroy(back), sfSprite_destroy(my_spr);
}

int game(sfRenderWindow *window, sfVector2f size_window)
{
    sfEvent event;
    sfTexture *back = sfTexture_createFromFile("pic/map.jpg", NULL);
    sfSprite *my_spr = sfSprite_create();
    sfVector2f size = {1.5, 1.5};
    sfVector2f map_pos = {0, 0};
    sfVector2f dino_pos;
    dino_pos.x = (size_window.x / 2), dino_pos.y = (size_window.y / 2);
    sfSprite_scale(my_spr, size);

    sfSprite_setTexture(my_spr, back, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
        ch_move(window, &map_pos, &dino_pos);
        sfSprite_setPosition(my_spr, map_pos);
        sfRenderWindow_drawSprite(window, my_spr, NULL);
        my_perso(window, dino_pos);
        sfRenderWindow_display(window);
    }
}

int main()
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode video_m = {1080, 720, 32};
    sfVector2f size_window = {1080, 720};
    window = sfRenderWindow_create(video_m, "Hs", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 90);
    sfRenderWindow_clear(window, sfBlack);
    game(window, size_window);
}