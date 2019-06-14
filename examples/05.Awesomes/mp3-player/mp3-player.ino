#include <M5Stack.h>
#include <WiFi.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputI2S.h"

struct Track
{
  String label;
  int timePos;
  Track *left;
  Track *right;
};

Track *trackList;
bool playing = true;
unsigned long currentMillis;

extern unsigned char logo[];
extern unsigned char timer_logo[];
extern unsigned char insertsd_logo[];
extern unsigned char error_logo[];

AudioGeneratorMP3 *mp3;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

char* strToChar(String str) {
  int len = str.length() + 1;
  char* buf = new char[len];
  strcpy(buf, str.c_str());
  return buf;
}

int cntChar(String str, char chr) {
  int n = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == chr) n++;
  }
  return n;
}

int posChar(String str, char chr) {
  int n = cntChar(str, chr);
  int t = 0;
  for (int p = 0; p < str.length(); p++)
  {
    if (str[p] == chr) t++;
    if (t == n) return p; 
  }
  return -1;
}

String parseString(int idSeparator, char separator, String str) { // like a split JS
  String output = "";
  int separatorCout = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if ((char)str[i] == separator)
    {
      separatorCout++;
    }
    else
    {
      if (separatorCout == idSeparator)
      {
        output += (char)str[i];
      }
      else if (separatorCout > idSeparator)
      {
        break;
      }
    }
  }
  return output;
}

bool createTrackList(String dir) {
  int i = 0;
  File root = SD.open(strToChar(dir));
  if (root)
  {
    while (true)
    {
      File entry =  root.openNextFile();
      if (!entry) break;
      if (!entry.isDirectory())
      {
        String ext = parseString(cntChar(entry.name(), '.'), '.', entry.name());
        if (ext == "mp3") 
        {
          i++;
          Track *tmp = new Track;
          tmp->label = entry.name();
          tmp->timePos = 0;
          tmp->right = tmp; 
          if (trackList == NULL)
          {
            tmp->left = tmp;
            trackList = tmp;
          }
          else
          {
            tmp->left = trackList;
            trackList->right = tmp;
            trackList = trackList->right;
          }
        }
      }
      entry.close();
    }
    if (i > 1)
    {
      do
      {
        trackList = trackList->left;
      } while(trackList != trackList->left);
    }
    root.close();
  }
  if (i > 0)
    return true;
  return false;
}

bool play(char dir) {
  switch (dir)
  {
    case 'r':
      if (trackList == trackList->right) return false;
      trackList->timePos = 0;
      trackList = trackList->right;       
    break;
    case 'l':
    if (trackList == trackList->left) return false;
      trackList->timePos = 0;
      trackList = trackList->left;
    break;
    case 'm': // mute
      delete file;
      delete out;
      delete mp3;
      mp3 = NULL;
      file = NULL;
      out = NULL;
      file = new AudioFileSourceSD("/");
      id3 = new AudioFileSourceID3(file);
      out = new AudioOutputI2S(0, 1);
      out->SetOutputModeMono(true);
      mp3 = new AudioGeneratorMP3();
      mp3->begin(id3, out);
      playing = false;
    return true;
    default:
      if (playing)
      {
        trackList->timePos = id3->getPos();
        play('m');
        return true;
      }
    break;
  }
  drawCover();
  file = new AudioFileSourceSD(strToChar(trackList->label));
  id3 = new AudioFileSourceID3(file);
  id3->seek(trackList->timePos, 1);
  out = new AudioOutputI2S(0, 1);
  out->SetOutputModeMono(true);
  mp3 = new AudioGeneratorMP3();
  playing = true;
  mp3->begin(id3, out);
  
  return true;
}

unsigned long genSpectrum_previousMillis = 0;
void genSpectrum() {
  currentMillis = millis();
  if (currentMillis - genSpectrum_previousMillis > 100)
  {
    genSpectrum_previousMillis = currentMillis;
    drawSpectrum(random(0,101),random(0,101),random(0,101),random(0,101));
  }
}

void drawCover() {
  M5.Lcd.drawJpgFile(SD, strToChar(trackList->label + ".jpg"), 30, 15, 75, 75);
}

unsigned long drawTimeline_previousMillis = 0;
void drawTimeline() {
  currentMillis = millis();
  if (currentMillis - drawTimeline_previousMillis > 250)
  {
    int x = 30;
    int y = 110;
    int width = 260;
    int heightLine = 2;
    int heightMark = 20;
    int widthMark = 2;
    int yClear = y - (heightMark / 2);
    int wClear = width + (widthMark / 2);
    
    drawTimeline_previousMillis = currentMillis;
    M5.Lcd.fillRect(x, yClear, wClear, heightMark, 0xffff);
    M5.Lcd.fillRect(x, y, width, heightLine, 0x7bef);
    int size_ = id3->getSize();
    int pos_ = id3->getPos();
    int xPos = x + ((pos_ * (width - (widthMark / 2))) / size_);
    M5.Lcd.fillRect(xPos, yClear, widthMark, heightMark, 0xe8e4);
  }
}

void drawSpectrum(int a, int b, int c, int d) { // %
  int x = 195;
  int y = 30;
  int padding = 10;
  int height = 30;
  int width = 15;

  int aH = ((a * height) / 100);
  int aY = y + (height - aH);
  M5.Lcd.fillRect(x, y, width, height, 0xffff);
  M5.Lcd.fillRect(x, aY, width, aH, 0x7bef); //0xe8e4
  
  int bH = ((b * height) / 100);
  int bY = y + (height - bH);
  int bX = x + width + padding;
  M5.Lcd.fillRect(bX, y, width, height, 0xffff);
  M5.Lcd.fillRect(bX, bY, width, bH, 0x7bef); //0xff80

  int cH = ((c * height) / 100);
  int cY = y + (height - cH);
  int cX = bX + width + padding;
  M5.Lcd.fillRect(cX, y, width, height, 0xffff);
  M5.Lcd.fillRect(cX, cY, width, cH, 0x7bef);//0x2589

  int dH = ((d * height) / 100);
  int dY = y + (height - dH);
  int dX = cX + width + padding;;
  M5.Lcd.fillRect(dX, y, width, height, 0xffff);
  M5.Lcd.fillRect(dX, dY, width, dH, 0x7bef);//0x051d
}

void drawTrackList() {
  M5.Lcd.fillRect(0, 130, 320, 75, 0xffff);
  if (trackList->left != trackList)
  {
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(0x7bef);
    M5.Lcd.setCursor(10, 130);
    String label = ((trackList->left)->label).substring(1, posChar(((trackList->left)->label), '.'));
    if (((trackList->left)->label).length() > 24) label = label.substring(0, 24) + ".";
    M5.Lcd.print(label);
  }
 
  M5.Lcd.setTextSize(3); 
  M5.Lcd.setTextColor(0x0000);
  M5.Lcd.setCursor(10, 155);
  String label = (trackList->label).substring(1, posChar((trackList->label), '.'));
  if ((trackList->label).length() > 16) label = label.substring(0, 16) + ".";
  M5.Lcd.print(label);

  if (trackList->right != trackList)
  {
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(0x7bef);
    M5.Lcd.setCursor(10, 185);
    String label = ((trackList->right)->label).substring(1, posChar(((trackList->right)->label), '.'));
    if (((trackList->right)->label).length() > 24) label = label.substring(0, 24) + ".";
    M5.Lcd.print(label);
  }
}

void drawGUI() {
  M5.Lcd.drawBitmap(0, 0, 320, 150, (uint16_t *)logo);
  M5.Lcd.setTextColor(0x7bef);
  drawTrackList();
  while (true)
  {
    if (m5.BtnB.wasPressed())
    {
      M5.Lcd.fillRect(0, 0, 320, 240, 0x0000);
      M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff); 
      drawTrackList();
      break; 
    }
    m5.update();
  }
}

void setup(){
  M5.begin();
  WiFi.mode(WIFI_OFF);
  M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
  M5.Lcd.setTextColor(0x7bef);
  M5.Lcd.setTextSize(2);
  M5.Lcd.drawBitmap(30, 75, 59, 59, (uint16_t *)timer_logo);
  M5.Lcd.setCursor(110, 90);
  M5.Lcd.print("STARTING...");
  M5.Lcd.setCursor(110, 110);
  M5.Lcd.print("WAIT A MOMENT");
  if (!SD.begin())
  {
    M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
    M5.Lcd.drawBitmap(50, 70, 62, 115, (uint16_t *)insertsd_logo);
    M5.Lcd.setCursor(130, 70);
    M5.Lcd.print("INSERT");
    M5.Lcd.setCursor(130, 90);
    M5.Lcd.print("THE TF-CARD");
    M5.Lcd.setCursor(130, 110);
    M5.Lcd.print("AND TAP");
    M5.Lcd.setCursor(130, 130);
    M5.Lcd.setTextColor(0xe8e4);
    M5.Lcd.print("POWER");
    M5.Lcd.setTextColor(0x7bef);
    M5.Lcd.print(" BUTTON"); 
    while(true);
  }
  if (!createTrackList("/"))
  {
    M5.Lcd.fillRoundRect(0, 0, 320, 240, 7, 0xffff);
    M5.Lcd.drawBitmap(30, 75, 59, 59, (uint16_t *)error_logo);
    M5.Lcd.setCursor(110, 70);
    M5.Lcd.print("ADD MP3 FILES");
    M5.Lcd.setCursor(110, 90);
    M5.Lcd.print("TO THE TF-CARD");
    M5.Lcd.setCursor(110, 110);
    M5.Lcd.print("AND TAP");
    M5.Lcd.setCursor(110, 130);
    M5.Lcd.setTextColor(0xe8e4);
    M5.Lcd.print("POWER");
    M5.Lcd.setTextColor(0x7bef);
    M5.Lcd.print(" BUTTON");
    while(true);
  }
  drawGUI();
  play('m');
}

void loop(){ 
  if (m5.BtnA.wasPressed())
  {
    play('l');
    drawTrackList();
  }

  if (m5.BtnB.wasPressed())
  {
    play('t');
  }

  if (m5.BtnC.wasPressed())
  {
    play('r');
    drawTrackList();
  }

  if (playing)
  {
    if (mp3->isRunning())
    {
      if (!mp3->loop())
      {
        mp3->stop();
        playing = false;
        play('r');
        drawTrackList();
      }
    }
    else
    {
      delay(1000);
    }
    genSpectrum();
    drawTimeline();
  }
  m5.update();
}
