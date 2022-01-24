/*
 * container.c
 *
 *  Created on: Jan 24, 2022
 *      Author: william
 */

#include <stdio.h>
#include <string.h>
#include "../lvgl/lvgl.h"
#include "container.h"

void page(void);
void window(void);
void tab(void);

void container(void)
{
//	page();
//	window();
	tab();
}

void page()
{
	lv_obj_t * page = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page, 150, 200);
	lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_t * label = lv_label_create(page, NULL);
	lv_label_set_text(label, "There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form,\n"
			" by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, \n"
			"you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend \n"
			"to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, \n"
			"combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore \n"
			"always free from repetition, injected humour, or non-characteristic words etc.");
	lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);
	lv_obj_set_width(label, lv_page_get_width_fit(page));
}

void on_settings_handler(lv_obj_t * btn, lv_event_t event)
{
	if(event == LV_EVENT_CLICKED) {
		// DO SOMETHING HERE
	}

	lv_win_close_event_cb(btn, event);
}

void window()
{
	lv_obj_t * win = lv_win_create(lv_scr_act(), NULL);
	lv_win_set_title(win, "My Window");
	lv_obj_t * close_btn = lv_win_add_btn(win, LV_SYMBOL_CLOSE);
	lv_obj_set_event_cb(close_btn, lv_win_close_event_cb);

	lv_obj_t * settings_btn = lv_win_add_btn(win, LV_SYMBOL_SETTINGS);
	lv_obj_set_event_cb(settings_btn, on_settings_handler);

	lv_obj_set_event_cb(close_btn, lv_win_close_event_cb);
	lv_obj_set_event_cb(close_btn, lv_win_close_event_cb);

	lv_win_add_btn(win, LV_SYMBOL_CHARGE);

	lv_obj_t * label = lv_label_create(win, NULL);
	lv_label_set_text(label, "There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form,\n"
			" by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, \n"
			"you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend \n"
			"to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, \n"
			"combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore \n"
			"always free from repetition, injected humour, or non-characteristic words etc.");
	lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);
	lv_obj_set_width(label, lv_page_get_width_fit(win));
}

void tab()
{
	lv_obj_t * tab_view = lv_tabview_create(lv_scr_act(), NULL);
	lv_tabview_set_btns_pos(tab_view, LV_TABVIEW_TAB_POS_BOTTOM);

	lv_obj_t * tab1 = lv_tabview_add_tab(tab_view, "Tab 1");
	lv_obj_t * tab2 = lv_tabview_add_tab(tab_view, "Tab 2");
	lv_obj_t * tab3 = lv_tabview_add_tab(tab_view, "Tab 3");

}
