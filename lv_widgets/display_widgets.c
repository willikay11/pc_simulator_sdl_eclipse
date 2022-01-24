/*
 * display_widgets.c
 *
 *  Created on: Jan 24, 2022
 *      Author: william
 */

#include <stdio.h>
#include <string.h>
#include "../lvgl/lvgl.h"
#include "display_widgets.h"

void draw_chart(void);

void display_widgets(void)
{
	draw_chart();
}

void draw_chart(void)
{
	static lv_style_t chart_style;
	lv_style_init(&chart_style);
	lv_style_set_pad_bottom(&chart_style, LV_STATE_DEFAULT, 60);

	lv_obj_t * chart = lv_chart_create(lv_scr_act(), NULL);
	lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
	lv_chart_set_range(chart, 0, 200);
	lv_chart_set_x_tick_texts(chart, "1\n2\n3\n4\n5\n6\n7\n8\n9", 3, LV_CHART_AXIS_DRAW_LAST_TICK);
	lv_obj_add_style(chart, LV_CHART_PART_BG ,&chart_style);

	lv_chart_series_t * series1 = lv_chart_add_series(chart, LV_COLOR_BLUE);
	lv_chart_set_next(chart, series1, 50);
	lv_chart_set_next(chart, series1, 120);
	lv_chart_set_next(chart, series1, 51);
	lv_chart_set_next(chart, series1, 120);
	lv_chart_set_next(chart, series1, 52);
	lv_chart_set_next(chart, series1, 56);
	lv_chart_set_next(chart, series1, 89);
	lv_chart_set_next(chart, series1, 80);
	lv_chart_set_next(chart, series1, 90);

	lv_chart_series_t * series2 = lv_chart_add_series(chart, LV_COLOR_RED);
	lv_chart_set_next(chart, series2, 150);
	lv_chart_set_next(chart, series2, 170);
	lv_chart_set_next(chart, series2, 56);
	lv_chart_set_next(chart, series2, 120);
	lv_chart_set_next(chart, series2, 70);
	lv_chart_set_next(chart, series2, 56);
	lv_chart_set_next(chart, series2, 78);
	lv_chart_set_next(chart, series2, 10);
	lv_chart_set_next(chart, series2, 40);

}

