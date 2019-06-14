#include <Ticker.h>

//#include "lv_draw/lv_draw_img.h"

#include <Cubic32.h>

#define XP 26
#define XM 33
#define YM 25
#define YP 32
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

Ticker tick;
const float togglePeriod = 0.05; //seconds

//Ticker function to keep the GUI running
static void lv_tick_handler(void) {
    lv_tick_inc(togglePeriod * 1000);
}

void disp_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p) {
    uint16_t c;
    Cubic.Lcd.startWrite(); // Start new TFT transaction
    Cubic.Lcd.setAddrWindow(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1));
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            c = Cubic.Lcd.color565(color_p->red, color_p->green, color_p->blue);
            Cubic.Lcd.writePixels(&c, 1);
            color_p++;
        }
    }
    Cubic.Lcd.endWrite();
    lv_flush_ready();
}

bool my_input_read(lv_indev_data_t *data)
{
    static uint16_t prev_x, prev_y;
    TSPoint p = ts.getPoint();

    if (p.z > ts.pressureThreshhold) {
        data->point.x = p.x;
        data->point.y = p.y;
        data->state = LV_INDEV_STATE_PR;
        prev_x = data->point.x;
        prev_y = data->point.y;
    } else {
        data->point.x = prev_x;
        data->point.y = prev_y;
        data->state = LV_INDEV_STATE_REL;
    }

    return false;        /*No buffering so no more data read*/
}


void setup() {
    Cubic.begin(true,false);
    
    Cubic.Lcd.setRotation(1);
    
    lv_init();
    
    /*Initialize the display*/
    lv_disp_drv_t disp_drv;
    disp_drv.disp_flush = disp_flush;
    lv_disp_drv_register(&disp_drv);
    
    /* Initialize input device touch */
    lv_indev_drv_t indev_drv;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = my_input_read;
    lv_indev_drv_register(&indev_drv);
      
    /*Initialize the graphics library's tick*/
    tick.attach(togglePeriod, lv_tick_handler);
    
    //demo_create();
    /*Create styles for the keyboard*/
    static lv_style_t rel_style, pr_style;
    
    lv_style_copy(&rel_style, &lv_style_btn_rel);
    rel_style.body.radius = 0;
    
    lv_style_copy(&pr_style, &lv_style_btn_pr);
    pr_style.body.radius = 0;
    
    /*Create a keyboard and apply the styles*/
    lv_obj_t *kb = lv_kb_create(lv_scr_act(), NULL);
    lv_kb_set_cursor_manage(kb, true);
    lv_kb_set_style(kb, LV_KB_STYLE_BG, &lv_style_transp_tight);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_REL, &rel_style);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_PR, &pr_style);
    
    /*Create a text area. The keyboard will write here*/
    lv_obj_t *ta = lv_ta_create(lv_scr_act(), NULL);
    lv_obj_align(ta, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
    lv_ta_set_text(ta, "");
    
    /*Assign the text area to the keyboard*/
    lv_kb_set_ta(kb, ta);

}

void loop() {

    delay(10);
    lv_task_handler();
}
