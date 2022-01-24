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
void form(void);

void widget(void)
{
	printf("Widgets\n");
//	label();
	form();
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

lv_obj_t * label_status;

void on_check_changed(lv_obj_t * checkbox, lv_event_t event)
{
	if (event == LV_EVENT_VALUE_CHANGED) {
		bool is_checked = lv_checkbox_is_checked(checkbox);
		lv_label_set_text_fmt(label_status, "checkbox changed to %s", is_checked ? "True" : "False");
	}
}

void on_switch_changed(lv_obj_t * lv_switch, lv_event_t event) {
	if (event == LV_EVENT_VALUE_CHANGED) {
		bool is_checked = lv_switch_get_state(lv_switch);
		lv_label_set_text_fmt(label_status, "switch changed to %s", is_checked ? "True" : "False");
	}
}

void on_drop_down_changed(lv_obj_t * drop_down, lv_event_t event) {
	if (event == LV_EVENT_VALUE_CHANGED) {
		char buffer[50];
		lv_dropdown_get_selected_str(drop_down, buffer, buffer);
		lv_label_set_text_fmt(label_status, "%s was selected", buffer);
	}
}

void btn_event_handler(lv_obj_t * btn, lv_event_t event) {
	if(event == LV_EVENT_CLICKED) {
		lv_label_set_text(label_status, "button was clicked");
	}
}

void form(void)
{
	label_status = lv_label_create(lv_scr_act(), NULL);
	lv_obj_t * container = lv_cont_create(lv_scr_act(), NULL);
	lv_obj_set_auto_realign(container, true);
	lv_cont_set_fit(container, LV_FIT_TIGHT);
	lv_cont_set_layout(container, LV_LAYOUT_COLUMN_MID);
	lv_obj_t * checkbox = lv_checkbox_create(container, NULL);
	lv_checkbox_set_text(checkbox, "Yes or No");
	lv_obj_set_event_cb(checkbox, on_check_changed);

	lv_obj_t * a_switch = lv_switch_create(container, NULL);
	lv_obj_set_event_cb(a_switch, on_switch_changed);

	lv_obj_t * drop_down = lv_dropdown_create(container, NULL);
	lv_dropdown_set_options(drop_down, "Kenya\nTz\nUg");
	lv_obj_set_event_cb(drop_down, on_drop_down_changed);

	lv_obj_t * btn = lv_btn_create(container, NULL);
	lv_obj_t * btn_label = lv_label_create(btn, NULL);
	lv_label_set_text(btn_label, "Submit");
	lv_obj_set_event_cb(btn, btn_event_handler);

}

