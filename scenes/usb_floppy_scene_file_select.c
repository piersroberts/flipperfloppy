#include "../usb_floppy_app_i.h"

static bool usb_floppy_file_select(UsbFloppyApp* app) {
    furi_assert(app);

    DialogsFileBrowserOptions browser_options;
    dialog_file_browser_set_basic_options(
        &browser_options, USB_FLOPPY_APP_EXTENSION, &I_floppy_10px);
    browser_options.base_path = USB_FLOPPY_APP_PATH_FOLDER;
    browser_options.hide_ext = false;

    // Input events and views are managed by file_select
    return dialog_file_browser_show(
        app->dialogs, app->file_path, app->file_path, &browser_options);
}

void usb_floppy_scene_file_select_on_enter(void* context) {
    UsbFloppyApp* app = context;

    if(usb_floppy_file_select(app)) {
        usb_floppy_app_open_image(app);
    } else {
        scene_manager_previous_scene(app->scene_manager);
    }
}

bool usb_floppy_scene_file_select_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void usb_floppy_scene_file_select_on_exit(void* context) {
    UNUSED(context);
}
