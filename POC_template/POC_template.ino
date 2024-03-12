// Includes
#define FORCE_TEMPLATED_NOPS
#include <ESP32-USB-Soft-Host.h>

// Keep uncommented for a mouse
#include <BleMouse.h>
BleMouse bleMouse(/*Give your mouse a cool name here*/, "BIP Coimbra 2024", 100);

// uncomment for a keyboard
// #include <BleKeyboard.h>
// BleKeyboard bleKeyboard(/*Give your keyboard a cool name here*/, "BIP Coimbra 2024", 100);

typedef struct {
  /* Create a structure that matches your USB device HID report descriptor */
} Report_/*insert your USB device VID*/_/*insert you USB device PID*/;

Report_/*VID*/_/*PID*/ report;

// default pins tested on ESP32-Wroom
#define PROFILE_NAME "Default Wroom"
#define DP_P0  22  // always enabled
#define DM_P0  23  // always enabled

usb_pins_config_t USB_Pins_Config =
{
  DP_P0, DM_P0,
};

static void reportCB(uint8_t usbNum, uint8_t byte_depth, uint8_t* data, uint8_t data_len)
{
  /*  This function should:
  *     - Check if the report data and the report structure are the same size
  *     - Copy the report data into the report structure
  *     - Check if the BLE device is connected to a computer
  *     - If yes, use the BleMouse (or BleKeyboard) functions to send BLE actions depending on the report fields
  */
}


void setup()
{
  Serial.begin(115200);
  delay(1000);

  // necessary for USB to work with BLE
  USH.setISRAllocFlag(NULL);
  USH.init(USB_Pins_Config);

  // custom callback to handle new data reports
  USH.setPrintCb(reportCB);

  // has to begin AFTER USB host
  bleMouse.begin();
}

void loop()
{
  // Nothing to do here
}
