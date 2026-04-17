import ddf.minim.*;

Minim minim;
AudioOutput out;

void setup(){
  size(200, 200);
  minim = new Minim(this);
  out = minim.getLineOut();
}

void draw(){
  background(0);
}

void keyPressed(){
  switch(key){
    case '1':
      out.playNote(0.0, 1.0, "C4");//ド
      break;
     case'2':
       out.playNote(0.0, 1.0, "D4");//レ
       break;
     case'3':
       out.playNote(0.0, 1.0, "E4");//ミ
       break;
  }
}
    
