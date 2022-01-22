/*
 * base_obj.c
 *
 *  Created on: Jan 22, 2022
 *      Author: william
 */


#include <stdio.h>
#include <string.h>
#include "../lvgl/lvgl.h"
#include "base_obj.h"

void base_obj()
{
	printf("Base Object\n");

	lv_obj_t * base_obj = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_drag(base_obj, true);
	lv_obj_set_size(base_obj, 200, 200);
	lv_obj_set_pos(base_obj, 200, 200);

	lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_drag(btn, true);
	lv_obj_set_size(btn, 100, 100);
	lv_obj_set_pos(btn, 100, 100);

	lv_obj_t * led = lv_led_create(lv_scr_act(), NULL);
	lv_obj_set_drag(led, true);
	lv_obj_set_pos(led, 50, 50);
	fflush(NULL);
}
