#define PIN            6

#define NUMPIXELS      7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int red;
int green;
int blue;
int oldRed = 0;
int oldGreen = 0;
int oldBlue = 0;

void setup() {
  pixels.begin();
  pixels.setBrightness(150);
}

void loop() {
  red = random(0, 256);
  green = (256 - random(0, 256));
  blue = random(0, 256);
  
 int redDiff = (red - oldRed);
 int greenDiff = (green - oldGreen);
 int blueDiff = (blue - oldBlue);
 
 int redSteps = (redDiff/20);
 int greenSteps = (greenDiff/20);
 int blueSteps = (blueDiff/20);

  for(int i=0;i<20;i++) {
    for(int j=0;j<NUMPIXELS;j++){
      redDiff = (red - oldRed);
      greenDiff = (green - oldGreen);
      blueDiff = (blue - oldBlue);
      pixels.setPixelColor(j, pixels.Color((red - redDiff),(green - greenDiff),(blue - blueDiff))); // Moderately bright green color.
      pixels.show();
    }
    oldRed = oldRed + redSteps;
    oldGreen = oldGreen + greenSteps;
    oldBlue = oldBlue + blueSteps;   
    delay(100);
 }  
   
  oldRed = red;
  oldGreen = green;
  oldBlue = blue;
}

