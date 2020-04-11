int led[3] = {15, 4, 17};
int gnd[3] = {2, 16, 5};
int trigPin = 12;
int echoPin = 14;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<3; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], 0);
    
    pinMode(gnd[i], OUTPUT);
    digitalWrite(gnd[i], 0);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  int j=0;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;

  if(distance < 10){
    digitalWrite(led[0], 1);
    digitalWrite(led[1], 1);
    digitalWrite(led[2], 1);
  }else{
    digitalWrite(led[0], 0);
    digitalWrite(led[1], 0);
    digitalWrite(led[2], 0);
  }
  //시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시해준다.
  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDIstance:");
  Serial.print(distance);
  Serial.println("cm\n");
  delay(500);
}
