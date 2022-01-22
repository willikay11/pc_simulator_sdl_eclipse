/*
 * widget.c
 *
 *  Created on: Jan 22, 2022
 *      Author: william
 */

#include <stdio.h>
#include <string.h>
#include "../lvgl/lvgl.h"
#include "widget.h"

void label(void);

void widget(void)
{
	printf("Widgets\n");
	label();
	fflush(NULL);
}

void label(void)
{
	lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(label1, "Hello World");
	lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);

	lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_recolor(label2, true);
	lv_label_set_text(label2, "#03fc0b Hello#  #03fc0b World#");
	lv_label_set_align(label2, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_y(label2, 60);
}
