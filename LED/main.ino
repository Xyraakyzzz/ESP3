int pinLed[] = {2,3,4,5};
int pinBtn = 9;
int pinBuzzer = 7;
int bacaNilai,a,b,c,d,e,f,i,n;
int kondisi = 0;
String info;

void setup() {
  Serial.begin(9600);
  for (i=0; i<5; i++){
    pinMode(pinLed[i], OUTPUT);
  }
  pinMode(pinBtn, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {

	//Baca Inputan Pertama Kali Untuk Mengaktifkan
  while (kondisi == 0){
    bacaNilai = digitalRead(pinBtn);
    if (bacaNilai == 0 && a < 2){
      a++;
      delay(1000);
      }
      if (a == 2){
        kondisi = 1;
        info = "Aktif";
        Serial.println(info);
        ledNyala();
        buzzerNyala();
        delay(500);
        buzzerPadam();
        delay(500);
        buzzerNyala();
        delay(500);
        buzzerPadam();
        delay(500);
        ledPadam();
        delay(500);
        
      }//Penutup Kondisi Aktif
      
 }//Penutup Kondisi While Kondisi 0
	
	//Kondisi Running LED
	while (kondisi == 1){
		bacaNilai = digitalRead(pinBtn);
		if (bacaNilai == 0 && b < 2){
			b++;
      delay(1000);
      }
		while (b>0 && b<2){
			bacaNilai = digitalRead(pinBtn);
      info = "Running LED";
      Serial.println(info);
      runningNyala();
      runningPadam();
      //Serial.println(bacaNilai);
      
      bacaNilai = digitalRead(pinBtn);
			if (bacaNilai == 0 && c < 2){
      c++;
      delay(1000);
			}
			if (c>0 && c<2) {
				kondisi = 2;
				//Kondisi Led Blinking
				while (kondisi == 2){
					bacaNilai = digitalRead(pinBtn);
					info = "Blinking";
					Serial.println(info);
					ledNyala();
					delay(200);
					ledPadam();
					delay(200);
					//Serial.println(bacaNilai);
					
					bacaNilai = digitalRead(pinBtn);
					if (bacaNilai == 0 && d < 2){
						d++;
						delay(1000);
					}
					
					
					if (d == 2){
						kondisi = 3;
					}
					
					//Kondisi untuk mematikan semua fungsi
					while (kondisi == 3){
						info = "Mati";
						ledPadam();
						Serial.println(info);
						delay(200);
						kondisi = 4;
						//Untuk melakukan proses reset semua Fungsi dan kembali ke Kondisi pertama untuk standby Diaktifkan
						if (kondisi == 4){
							info = "Sedang Me-Reset";
							Serial.println(info);
							a = 0;
							b = 0;
							c = 0;
							d = 0;
							delay(1000);
							kondisi = 0;
						}
					}
				}//Penutup While Kondisi 2
			}//Penutup If Kondisi 2
		}
	}//Penutup While Kondisi 1
}//Penutup Void Loop()


//Fungsi-Fungsi Procedure

void buzzerNyala(){
  digitalWrite(pinBuzzer, 1);
}

void buzzerPadam(){
  digitalWrite(pinBuzzer, 0);
}

void ledNyala(){
  for (i=0; i<5; i++){
    digitalWrite(pinLed[i],1);
  }
}

void ledPadam(){
   for (i=0; i<5; i++){
    digitalWrite(pinLed[i],0);
  }
}

void runningNyala(){
  for (i=0; i<5; i++){
    digitalWrite(pinLed[i],1);
    delay(100);
  }
}

void runningPadam(){
  for (i=0; i<5; i++){
    digitalWrite(pinLed[i],0);
    delay(100);
  }
}

//End Of Program
