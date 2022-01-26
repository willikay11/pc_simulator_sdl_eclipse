/*
 * custom_fonts.c
 *
 *  Created on: Jan 26, 2022
 *      Author: william
 */
#include <stdio.h>
#include <string.h>
#include "img_and_font.h"
#include "../lvgl/lvgl.h"

LV_FONT_DECLARE(sofia_pro_30)

void custom_fonts(void)
{
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_text_font(&style, LV_STATE_DEFAULT, &sofia_pro_30);

	lv_obj_t * lbl = lv_label_create(lv_scr_act(), NULL);
	lv_obj_align(lbl,NULL,LV_ALIGN_CENTER,0,0);
	lv_label_set_text(lbl,"Hello New World!");
	lv_obj_add_style(lbl,LV_LABEL_PART_MAIN,&style);

}

