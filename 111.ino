#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 定义屏幕分辨率（0.96寸通常是 128x64）
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// 定义 ESP32-S3 的 SPI 引脚（与上方接线表一致）
#define OLED_MOSI   11  // 对应屏幕 D1
#define OLED_CLK    12  // 对应屏幕 D0
#define OLED_DC     10  // 对应屏幕 DC
#define OLED_CS     9   // 对应屏幕 CS
#define OLED_RESET  8   // 对应屏幕 RST

// 初始化 OLED 对象，使用硬件 SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // 初始化串口，方便调试
  Serial.begin(115200);

  // 初始化 OLED 屏幕
  // SSD1306_SWITCHCAPVCC 表示由内部生成 3.3V 显示偏压
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 初始化失败，请检查接线！"));
    for (;;); // 如果失败，卡在这里死循环
  }

  // 清除缓冲区（Adafruit库初始化时会默认显示一个Logo）
  display.clearDisplay();

  // 设置文字颜色为白色（OLED是单色屏，只有白色和黑色）
  display.setTextColor(SSD1306_WHITE);
  
  // 设置文字大小为 2 倍（1是默认最小，2是两倍大，看起来更醒目）
  display.setTextSize(2);
  
  // 设置文字显示的起始坐标 (x, y)
  // 因为屏幕宽度是128，"LOVE ADILA" 比较长，我们从 x=0, y=20 开始显示，让它居中一点
  display.setCursor(0, 25);
  
  // 写入你要的英文字符
  display.println(F("LOVE ADILA"));

  // 将缓冲区的内容真正刷新到屏幕上显示出来
  display.display();
  
  Serial.println(F("屏幕显示成功！"));
}

void loop() {
  // 我们的代码只需要显示一次，所以 loop 循环里什么都不用写
}
