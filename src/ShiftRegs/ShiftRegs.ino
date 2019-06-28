
int clk = 3;
int shift = 2;
int clr = 4;
int buttPlayerLeft = 6;
int buttPlayerRight = 5;
int counter = 7;
int leftPlayerScore = 0;
int rightPlayerScore = 0;
int ballDelay = 120;
bool directionLeft = false;


void startGame();       // starts a new game
void risingEdge();      // rising clk_edge to shift the next bit
void shiftRegs();       // shift the bits
void setFirstLed();     // clears the shift regs and sets first bit to high
int  checkButtClick();  // checks if the buttons are pressed at the right time
void setLedPos(int pos); // set led on position pos
void fail();            // blinck the current LED where the fail happened


void setup() {
  pinMode(clk, OUTPUT);
  pinMode(shift, OUTPUT);
  pinMode(clr, OUTPUT);

  pinMode(buttPlayerLeft, INPUT);
  pinMode(buttPlayerRight, INPUT);

  digitalWrite(clk, LOW);
  digitalWrite(shift, LOW);
  digitalWrite(clr, HIGH);

  Serial.begin(9600);
  
  Serial.println("LET THE GAMES BEGIN !!!");
  
  Serial.print(leftPlayerScore);
  Serial.print(" - ");
  Serial.println(rightPlayerScore);
}

void loop() {
  shiftRegs();
  delay(ballDelay);
  if(counter == 15){
    fail();
  } else if(counter == 0){
    fail();
  }
}

void risingEdge(){
  digitalWrite(clk, LOW);
  digitalWrite(clk, HIGH);
}

void clearRegister(){
  digitalWrite(clr, LOW);
  digitalWrite(clr, HIGH);
}

void shiftRegs(){
  checkButtClick();
  
  if(directionLeft){
    counter--;    
  } else{
    counter++;
  }
  
  setLedPos(counter);
}

void setFirstLed(){
  digitalWrite(shift, HIGH);
  risingEdge();
  digitalWrite(shift, LOW);
}

int checkButtClick(){
  if(digitalRead(buttPlayerLeft)){
    if(counter >= 1 && counter <= 3){
      directionLeft = 0;
      ballDelay -= 10;
    } else if(directionLeft == 1){
      fail();
    }
  }else if(digitalRead(buttPlayerRight)){
    if(counter >= 12 && counter <= 14){
      directionLeft = 1;
      ballDelay -= 10;
    } else if (directionLeft == 0){
      fail(); 
    }
  }
}

void setLedPos(int pos){
  clearRegister();
  setFirstLed();
  while(pos--){
    risingEdge();
  }
}

void fail(){
  int i = 5;
  while(i--){
    delay(100);
    clearRegister();
    delay(100);
    setLedPos(counter);
  }
  if(directionLeft == 0){
    leftPlayerScore++;
  }else{
    rightPlayerScore++;
  }
  directionLeft = !directionLeft;
  Serial.print(leftPlayerScore);
  Serial.print(" - ");
  Serial.println(rightPlayerScore);
  ballDelay = 120;
  counter = 7;
}


//Failstate: 1,2,3,12,13,14 (und alles dazwischen) Für Player umgekehrt (wenn bei sich selbst gedrückt)
