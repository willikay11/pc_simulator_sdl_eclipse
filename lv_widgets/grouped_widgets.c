/*
 * grouped_widgets.c
 *
 *  Created on: Jan 24, 2022
 *      Author: william
 */
#include <stdio.h>
#include <string.h>
#include "../lvgl/lvgl.h"
#include "grouped_widgets.h"

void lists(void);
void groups(void)
{
	lists();
}

void list_btn_clicked(lv_obj_t * btn, lv_event_t event)
{
	if(event == LV_EVENT_CLICKED) {
		printf("%s was pressed \n", lv_list_get_btn_text(btn));
		fflush(NULL);
	}
}

void lists()
{
	lv_obj_t * list = lv_list_create(lv_scr_act(), NULL);
	lv_obj_set_size(list, lv_obj_get_width_fit(lv_scr_act()), lv_obj_get_height_fit(lv_scr_act()));
	lv_obj_t * btn;
	btn = lv_list_add_btn(list, LV_SYMBOL_AUDIO, "Audio");
	lv_obj_set_event_cb(btn, list_btn_clicked);
	btn = lv_list_add_btn(list, LV_SYMBOL_BELL, "Bell");
	lv_obj_set_event_cb(btn, list_btn_clicked);
}
