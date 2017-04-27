
#include "globals.h"
#include "pres.h"
#include "elements.h"
#include "controls.h"

void setup() {
 arduboy.boot();
 arduboy.flashlight();
 arduboy.systemButtons();
 arduboy.setFrameRate(60);
}

void loop() {
  
  if (!arduboy.nextFrame()){
  return;
  }
  
  arduboy.clear();

  arduboy.pollButtons();

  switch(gamestate) {
    
    case 0:
      pres();
    break;

    case 1:
      speedBuggy();
      buttons();
      mezzo();
      if(level > 2)aliens();
      if(level > 1)rock();
      salto();
      fire();
      percorso();
      sfondo();
      showScore();
      //arduboy.setCursor(0 ,0); arduboy.print(arduboy.cpuLoad());
    break;

    case 2:
      arduboy.setCursor(12, 30);
      arduboy.setTextSize(2);
      arduboy.print("GAME OVER");
      arduboy.display();
      delay(1500);
      arduboy.setTextSize(1);
      gamestate = 0;
      level = 1;
      for(byte n = 0; n < 17; n++){
        ster[n] = random(2);
      }
      posx = 3;
      posy = 42;
      veloc = 0;
      alienon = false;
      rockx = 128;
      rokon = false;
      bombon = false;
      shake = false;
      score = 0;
      shot = 5;
      maxAlienY = 25;
      break;
      
    case 3:
      tempo2 = (millis() - tempo) / 1000;
      if(tempo2 > tempo3){
        minutes = tempo2 / 60;
        seconds = tempo2 - minutes * 60;
        delay(1000);
      arduboy.setCursor(14, 30);
      arduboy.setTextSize(2);
      arduboy.print("NEW BEST!");
      arduboy.display();
      delay(2000);
      }else{
        delay(1000);
        arduboy.setCursor(40, 30);
        arduboy.setTextSize(2);
        arduboy.print("GREAT!!!!");
        arduboy.display();
        delay(2000);
        }
      win = true;

      arduboy.setTextSize(1);
      gamestate = 0;
      level = 1;
      for(byte n = 0; n < 17; n++){
        ster[n] = random(2);
      }
      posx = 3;
      posy = 42;
      veloc = 0;
      alienon = false;
      rockx = 128;
      rokon = false;
      bombon = false;
      shake = false;
      score = 0;
      shot = 5;
      maxAlienY = 25;
    break;
  }


  arduboy.display();

}
