unsigned long lastStepTime = 0;
int stepLength = 1000;
int currentStep = 0;
int totalSteps = 4;
int ledPinArray[4] = { 7, 8, 9, 10 };
int switchPin1 = 33;
int switchPin2 = 34;
long randNumber;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  randomSeed(analogRead(0));
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinArray[i], OUTPUT);
  }
}

void loop() {
  if (millis() > lastStepTime + stepLength) {
    lastStepTime = millis();
    digitalWrite(ledPinArray[currentStep], LOW);
    if (digitalRead(switchPin1) == LOW) {
      nextStep();
    }
    if (digitalRead(switchPin1) == HIGH) {
      previouStep();
    }
    if (digitalRead(switchPin2) == HIGH) {
      randomStep();
    }
    Serial.println(currentStep);
    digitalWrite(ledPinArray[currentStep], HIGH);
  }
}

void nextStep() {
  currentStep = currentStep + 1;
  if (currentStep >= totalSteps) {
    currentStep = 0;
  }
  digitalWrite(ledPinArray[currentStep], LOW);
  digitalWrite(ledPinArray[currentStep], HIGH);
}

void previouStep() {
  currentStep = currentStep - 1;
  if (currentStep < 0) {
    currentStep = totalSteps - 1;
  }
  digitalWrite(ledPinArray[currentStep], LOW);
  digitalWrite(ledPinArray[currentStep], HIGH);
}

void randomStep() {
  digitalWrite(ledPinArray[currentStep], LOW);
  randNumber = random(0, 4);
  currentStep = randNumber;
  digitalWrite(ledPinArray[currentStep], HIGH);
}

