#ifndef HX711_H
#define HX711_H  1

void Hx711(uint8_t pin_din, uint8_t pin_slk);
long getValue(void);
long averageValue(uint8_t times);
void setOffset(long offset);
void setScale(float scale);
float getGram();

#endif

	// EOF
