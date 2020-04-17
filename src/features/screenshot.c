/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** Takes a screenshot
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "init.h"
#include "struct.h"
#include "elapsed_time.h"
#include "my.h"

int parse_screenshots(void)
{
	int number = -2;
	struct dirent *dp;
	DIR *fd;

	fd = opendir("screenshots");
	while ((dp = readdir(fd)) != NULL) {
		number++;
	}
	closedir(fd);
	return (number);
}

void take_screenshot(sfRenderWindow *renderWindow)
{
	sfImage *image;
	static unsigned int screenshot_nbr = 0;
	static unsigned int static_var = 0;
	char *filename;
	char *str;

	if (static_var == 0)
		screenshot_nbr = parse_screenshots();
	screenshot_nbr++;
	image = sfRenderWindow_capture(renderWindow);
	str = my_itoa(screenshot_nbr, 10);
	filename = my_strcat("screenshots/screenshot_", str);
	filename = my_strcat(filename, ".jpg");
	while (!sfImage_saveToFile(image, filename));
	static_var++;
}

void display_screenshot(window_t *window, menu_t *menu)
{
	if (get_img_seconds(&menu->screenshot) < 3) {
		if (sfSprite_getPosition(menu->screenshot.sprite).y > 960)
			sfSprite_move(menu->screenshot.sprite,
			(sfVector2f){0, -15});
	} else {
		if (sfSprite_getPosition(menu->screenshot.sprite).y < 1180)
			sfSprite_move(menu->screenshot.sprite,
			(sfVector2f){0, 15});
		else
			window->is_screenshot = 0;
	}
	sfRenderWindow_drawSprite(window->window, menu->screenshot.sprite,
	NULL);
}

void load_screenshot(window_t *window, menu_t *menu)
{
	char *name;
	int number;
	char *number_arr;

	number = parse_screenshots();
	number_arr = my_itoa(number, 10);
	name = my_strcat("screenshots/screenshot_", number_arr);
	name = my_strcat(name, ".jpg");
	init_img(&menu->screenshot, name, (sfIntRect){0, 0,
	(int)sfRenderWindow_getSize(window->window).x,
	(int)sfRenderWindow_getSize(window->window).y},
	(sfVector2f){1715, 1180});
	sfSprite_setScale(menu->screenshot.sprite, (sfVector2f){0.2, 0.2});
}

void check_screenshot(window_t *window, menu_t *menu)
{
	static int screenshot_taken = 0;

	if (sfKeyboard_isKeyPressed(sfKeyF12)) {
		sfMusic_play(window->snap.music);
		screenshot_taken++;
		if (screenshot_taken == 1) {
			take_screenshot(window->window);
			window->is_screenshot = 1;
			load_screenshot(window, menu);
		}
	} else
		screenshot_taken = 0;
}
