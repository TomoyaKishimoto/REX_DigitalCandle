const int analogPin = A0; // マイクモジュールをアナログピン0番に接続
float volume = 0; //マイクセンサーが計測する音量

void setup() {
  Serial.begin(9600);
}

void loop() {
  volume = (float)analogRead(analogPin) / 1024.0f * 100.0f; // アナログピン0番から値を読み取る
  Serial.print("音量:");
  Serial.println(volume); // シリアルモニタに音量を表示
  delay(100); // 100ms（0.1秒）待つ
}
