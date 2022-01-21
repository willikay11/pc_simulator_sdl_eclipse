/*
 * base_obj.c
 *
 *  Created on: Jan 20, 2022
 *      Author: william
 */


#include <stdio.h>
#include <string.h>
#include "base_obj.h"
#include "../lvgl/lvgl.h"

void base_obj(void)
{
	printf("base_obj\n");

	lv_obj_t * base_obj = lv_obj_create(lv_scr_act());
	lv_obj_set_size(base_obj, 200, 200);
	lv_obj_set_pos(base_obj, 200, 100);

	lv_obj_t * button = lv_btn_create(lv_scr_act());
	lv_obj_set_size(button, 100, 100);
	lv_obj_set_pos(button, 100, 100);

	lv_obj_t * led = lv_led_create(lv_scr_act());
	lv_obj_set_pos(led, 50, 50);

	fflush(NULL);
}

