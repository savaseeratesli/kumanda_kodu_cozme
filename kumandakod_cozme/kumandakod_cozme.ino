#include <IRremote.hpp>

//Açma tuşu (HEX)40BF8877 -> (DEC)1086294135
//Kapama tuşu (HEX)40BF48B7 -> (DEC)1086277815 

int RECV_Pin=11;

//Nesne oluşturdum kütüphaneyi kullanmak için
IRrecv irrecv(RECV_Pin);

//Çözülmüş kodun cevabı
decode_results results;

void setup() 
{
  Serial.begin(9600);

  //IR aktifleştirme
  irrecv.enableIRIn();
}

void loop() 
{
  if(irrecv.decode(&results))//IR a veri geliyorsa
  {
    Serial.println(results.value,HEX);//Cevabı HEX yaz 
    irrecv.resume();
  }
  delay(100);
}
