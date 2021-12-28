#include <IRremote.hpp>

int IR_Alici=11;
int Role=10;

IRrecv irrecv(IR_Alici);

//Okunan değer
decode_results results;

void setup()
{
  Serial.begin(9600);
  //IR sensör aktif
  irrecv.enableIRIn();

  pinMode(Role,OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results))//Bir değişim varsa,değer okunduysa
  {
    Serial.println(results.value);

    if(results.value==1086294135)
    {
      digitalWrite(Role,HIGH);
    }
    else if(results.value==1086277815)
    {
      digitalWrite(Role,LOW);
    }

   irrecv.resume();
    
  }

  delay(100);

}
