// toggle debug on/off    1 = on   0 = off
#define DEBUG 1
// debug print methods
#if DEBUG == 1
#define debug(x) Serial.print(x);
#define debugln(x) Serial.print(x);
#else
#define debug(x)
#define debugln(x)
#endif
