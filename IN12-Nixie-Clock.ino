#define BOARD_TYPE 0
#define DUTY 180

byte FLIP_EFFECT = 1;

#define INDI_BRIGHT 23      // яркость цифр дневная (1 - 24) !на 24 могут быть фантомные цифры!
#define INDI_BRIGHT_N 3     // яркость ночная (1 - 24)

#define DOT_BRIGHT 35       // яркость точки дневная (1 - 255)
#define DOT_BRIGHT_N 15     // яркость точки ночная (1 - 255)

#define BACKL_BRIGHT 250    // макс. яркость подсветки ламп дневная (0 - 255)
#define BACKL_BRIGHT_N 50   // макс. яркость подсветки ламп ночная (0 - 255, 0 - подсветка выключена)
#define BACKL_MIN_BRIGHT 20 // мин. яркость подсветки ламп в режиме дыхание (0 - 255)
#define BACKL_PAUSE 400     // пазуа "темноты" между вспышками подсветки ламп в режиме дыхание, мс

// =======================  ГЛЮКИ =======================
#define GLITCH_MIN 30       // минимальное время между глюками, с
#define GLITCH_MAX 120      // максимальное время между глюками, с

// ======================  МИГАНИЕ =======================
#define DOT_TIME 500        // время мигания точки, мс
#define DOT_TIMER 20        // шаг яркости точки, мс

#define BACKL_STEP 2        // шаг мигания подсветки
#define BACKL_TIME 5000     // период подсветки, мс

// ==================  АНТИОТРАВЛЕНИЕ ====================
#define BURN_TIME 10        // период обхода индикаторов в режиме очистки, мс
#define BURN_LOOPS 3        // количество циклов очистки за каждый период
#define BURN_PERIOD 15      // период антиотравления, минут


// *********************** ДЛЯ РАЗРАБОТЧИКОВ ***********************
byte BACKL_MODE = 0;                          // Выбранный активен при запуске и меняется кнопками
byte FLIP_SPEED[] = {0, 130, 50, 40, 70, 70}; // скорость эффектов, мс (количество не меняй)
byte FLIP_EFFECT_NUM = sizeof(FLIP_SPEED);    // количество эффектов
boolean GLITCH_ALLOWED = 1;                   // 1 - включить, 0 - выключить глюки. Управляется кнопкой
boolean IS_24_HOUR = 0;
byte CUR_BRIGHT = 1;

// --------- БУДИЛЬНИК ---------
#define ALM_TIMEOUT 30      // таймаут будильника
#define FREQ 900            // частота писка будильника

// пины
#define PIEZO 2   // пищалка
#define KEY0 3    // часы
#define KEY1 4    // часы 
#define KEY2 5    // минуты
#define KEY3 6    // минуты
#define BTN1 7    // кнопка 1
#define BTN2 8    // кнопка 2
#define GEN 9     // генератор
#define DOT 10    // точка
#define BACKL 11  // подсветка
#define BTN3 12   // кнопка 3

// дешифратор
#define DECODER0 A0
#define DECODER1 A1
#define DECODER2 A2
#define DECODER3 A3

// распиновка ламп
#if (BOARD_TYPE == 0)
const byte digitMask[] = {7, 3, 6, 4, 1, 9, 8, 0, 5, 2};   // маска дешифратора платы in12_turned (цифры нормальные)
const byte opts[] = {KEY0, KEY1, KEY2, KEY3};              // порядок индикаторов слева направо
const byte cathodeMask[] = {1, 6, 2, 7, 5, 0, 4, 9, 8, 3}; // порядок катодов in12

#elif (BOARD_TYPE == 1)
const byte digitMask[] = {2, 8, 1, 9, 6, 4, 3, 5, 0, 7};   // маска дешифратора платы in12 (цифры вверх ногами)
const byte opts[] = {KEY3, KEY2, KEY1, KEY0};              // порядок индикаторов справа налево (для IN-12 turned) и ин-14
const byte cathodeMask[] = {1, 6, 2, 7, 5, 0, 4, 9, 8, 3}; // порядок катодов in12

#elif (BOARD_TYPE == 2)
const byte digitMask[] = {9, 8, 0, 5, 4, 7, 3, 6, 2, 1};   // маска дешифратора платы in14
const byte opts[] = {KEY3, KEY2, KEY1, KEY0};              // порядок индикаторов справа налево (для IN-12 turned) и ин-14
const byte cathodeMask[] = {1, 0, 2, 9, 3, 8, 4, 7, 5, 6}; // порядок катодов in14

#elif (BOARD_TYPE == 3)
const byte digitMask[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};   // тут вводим свой порядок пинов
const byte opts[] = {KEY0, KEY1, KEY2, KEY3};              // свой порядок индикаторов
const byte cathodeMask[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // и свой порядок катодов

#endif