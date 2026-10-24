#include "../usb_floppy_app_i.h"

void usb_floppy_scene_about_on_enter(void* context) {
    UsbFloppyApp* app = context;

    widget_add_text_scroll_element(
        app->widget,
        0,
        0,
        128,
        64,
        "\e#USB Floppy v" FAP_VERSION "\n"
        "Emulates a USB floppy drive from a 720K or 1.44M .img disk image on the SD card.\n\n"
        "Put images in\n"
        "apps_data/usb_floppy\n\n"
        "\e#Source code\n"
        "github.com/piersroberts/\n"
        "flipperfloppy");

    view_dispatcher_switch_to_view(app->view_dispatcher, UsbFloppyAppViewWidget);
}

bool usb_floppy_scene_about_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void usb_floppy_scene_about_on_exit(void* context) {
    UsbFloppyApp* app = context;
    widget_reset(app->widget);
}
