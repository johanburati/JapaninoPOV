/*
メロディ

メロディを奏でます。

回路：
* スピーカー（8オームの物を推奨）をデジタルピン14番に接続。

初版 2010年1月21日 作者 Tom Igoe
翻訳・変更 2010/4/23 大人の科学

http://arduino.cc/en/Tutorial/Tone

*/
#include "pitches.h"

// 音程
int melody[] = {
 NOTE_C4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4, 0, NOTE_G4,
 NOTE_F4, NOTE_D4, NOTE_C4 ,0 };

// 音の長さ 4→四分音符、8→八分音符）
int noteDurations[] = {
8,8,2,16,16,8,4,4,4,2,4,2,4 
};

void setup() {
}

void loop() {
 // メロディの音程を順番に奏でる。
 for (int thisNote = 0; thisNote < 13; thisNote++) {
   // 音の長さを計算する。
   // 1秒＝1000を、音の長さの数値で割る。
   // 四分音符なら1000/4、八分音符なら1000/8
   int noteDuration = 2000/noteDurations[thisNote];
   tone(14, melody[thisNote], noteDuration);

   // 音と音の間に無音の時間を設ける。
   // 音の長さの30%増しくらいがちょうどいい。
   int pauseBetweenNotes = noteDuration * 1.30;
   delay(pauseBetweenNotes);
 }
 delay(1000);  // メロディが終わったら1秒待って繰り返す。
}

