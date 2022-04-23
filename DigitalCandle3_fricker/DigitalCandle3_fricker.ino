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
  volume = (float)analogRead(analogPin) / 1024.0f * 100.0f; // analogReadは0~1024の値を取る．音の大きさを%に変換
  Serial.print("音量:");
  Serial.println(volume); // シリアルモニタに音量を表示
  analogWrite(ledPin,random(16, 255)); //LEDがランダムに光る
  delay(100); // 100ms（0.1秒）待つ
  /*
  if(volume > limit){ // volumeがlimitより大きい場合
    digitalWrite(ledPin,HIGH); // LEDが光る
    delay(100); // 3000ms（3秒）待つ
  }
  else{
    digitalWrite(ledPin,LOW); // LEDを光らせない
    delay(100); // 100ms（0.1秒）待つ
  }
  */
}
