const int analogPin = A0; // マイクモジュールのA0出力接続先
const int ledPin = 11; // LEDのピン出力接続先(PWMが可能なPIN)
float volume;
int limit;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT); // LEDピンをOUTPUTにする
  limit = 30;
}

void loop() {
  float volume = (float)analogRead(analogPin) / 1024.0f * 100.0f; // analogReadは0~1024の値を取る．音の大きさを%に変換
  Serial.print("音量:");
  Serial.println(volume); // シリアルモニタに音量を表示
  analogWrite(ledPin,random(16, 255));
  delay(100);
  /*
  if(volume > limit){
    analogWrite(ledPin,0);
    delay(5000); // 3000ms（3秒）待つ

  }
  else{
    analogWrite(ledPin,random(16, 255));
    delay(100); // 100ms（0.1秒）待つ
  }*/
}
