int t1 = 4, e1 = 3; 
int t2 = 9, e2 = 8; 

int c = 0;  

void setup()
{
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(e2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  float dr1, dr2;
  float dst1, dst2;
  float gate = 150;
  
  
  digitalWrite(t1, LOW);
  delayMicroseconds(2);
  digitalWrite(t2, LOW);
  delayMicroseconds(2); 
  
  
  digitalWrite(t1, HIGH);
  delayMicroseconds(10);
  digitalWrite(t1, LOW);  
  dr1 = pulseIn(e1, HIGH);  
  dst1 = 0.034*(dr1/2);
  
  
  digitalWrite(t2, HIGH);
  delayMicroseconds(10);
  digitalWrite(t2, LOW);  
  dr2 = pulseIn(e2, HIGH);  
  dst2 = 0.034*(dr2/2);
  
  if(dst1<gate)
  {
    c++;
    delay(1000);  
  }
  
  if(dst2<gate)
  {
    if(c>0){
      c--;
      delay(1000);
    }  	
  }
  
  Serial.print("\nNumber of Sheeps Inside = ");
  Serial.println(c);
  delay(500);
}
