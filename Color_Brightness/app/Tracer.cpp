#include "Tracer.h" // <1>
#include "ColorSensor.h"

// static FILE *bt = NULL;
rgb_raw_t rgb;

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
    // bt = ev3_serial_open_file(EV3_SERIAL_BT);
}

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
}

void Tracer::run() {
  colorSensor.getRawColor(rgb);
  // fprintf(bt, "R:%d G:%d B:%d\r\n", rgb.r, rgb.g, rgb.b);
  //  fprintf(bt, "%d\r\n",colorSensor.getBrightness());
  //  fprintf(bt, "%d\r\n",colorSensor.getColorNumber());
  sprintf(str, "R:%d G:%d B:%d", rgb.r, rgb.g, rgb.b);
  hub_display_text_scroll(str, 100);

  msg_f("running...", 1);
}