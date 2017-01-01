/*
*
* 出荷時スケッチ
*
*/

// 設定
int duration = 20;  // LEDを点灯する時間（ミリ秒）
int inputPin = 6;  // スイッチ入力ピン（オンでLOW）
int ledMin = 7;   // LEDピン範囲の最小
int ledMax = 13;  // LEDピン範囲の最大
int buzzPin = 14;  // ブザーピン（A0はD14としてアクセス）
int buzzTone = 4000;  // ブザーの音程
int buzzTime = 10;  // ブザーを鳴らす時間（ミリ秒）

// グローバル変数
unsigned long lastOn = 0; // ブザー鳴らし始め時刻（0なら鳴っていない）

void setup() {
 pinMode(inputPin, INPUT); // スイッチは入力
 digitalWrite(inputPin, HIGH); // 内蔵プルアップ有効
 for (int i = ledMin; i <= ledMax; i++) {
   pinMode(i, OUTPUT);  // LEDへの接続は出力
 }
 pinMode(buzzPin, OUTPUT); // ブザーは出力
}

// LED点灯中にやるべき処理
void pause() {
 unsigned long started = millis();

 for (;;) {
   unsigned long now = millis();

   // LED点灯時間が経過したら、
   if (now - started > duration) {
     // この関数を終わる。
     return;
   }

   // スイッチがオンになっていたら、
   if (digitalRead(inputPin) == LOW) {
     tone(buzzPin, buzzTone); // ブザーを鳴らす。
     lastOn = now;  // 鳴らし始めた時刻を覚えておく。
   }

   // ブザーが鳴っていて、かつ一定時間経過していたら、
   if (lastOn != 0 && now - lastOn > buzzTime) {
     noTone(buzzPin);  // ブザーを止める。
     lastOn = 0;  // 止めたことを覚えておく。
   }
 }
}

void loop() {
 // 上方向
 for (int i = ledMin; i <= ledMax; i++) {
   digitalWrite(i, HIGH); // 点灯する
   pause();
   digitalWrite(i, LOW); // 消灯する
 }

 // 下方向
 for (int i = ledMax; i >= ledMin; i--) {
   digitalWrite(i, HIGH); // 点灯する
   pause();
   digitalWrite(i, LOW); // 消灯する
 }
}
