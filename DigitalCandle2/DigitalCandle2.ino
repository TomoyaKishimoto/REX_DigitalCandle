const int analogPin = A0; // マイクモジュールをアナログピン0番に接続
const int ledPin = 11; // LEDを9ピンに接続
float volume = 0; //マイクセンサが計測する音量
int limit; // LEDが点灯するときのマイクセンサの値

void setup() {
  Serial.begin(9600); //シリアルポートの設定
  pinMode(ledPin,OUTPUT); // LEDピンを出力先に設定
  limit = 55; // 閾値を55にする
}

void loop() {
  volume = (float)analogRead(analogPin) / 1024.0f * 100.0f; // アナログピン0番から値を読み取る
  Serial.print("音量:");
  Serial.println(volume); // シリアルモニタに音量を表示
  
  if(volume > limit){ // volumeがlimitより大きい場合
    digitalWrite(ledPin,HIGH); // LEDが光る
    delay(100); // 3000ms（3秒）待つ
  }
  else{
    digitalWrite(ledPin,LOW); // LEDを光らせない
    delay(100); // 100ms（0.1秒）待つ
  }
}
