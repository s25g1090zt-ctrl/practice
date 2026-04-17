import ddf.minim.*;

Minim minim;
AudioOutput out;

void setup(){
  size(512, 200);
  minim = new Minim(this);
  out = minim.getLineOut();
}

void draw(){
  background(0);
  stroke(255);
  
  for(int i=0; i<out.bufferSize()-1; i++){
    line(i, 100+out.left.get(i)*50, i+1, 100+out.left.get(i+1)*50);
  }
}
  
 void keyPressed(){
   switch(key){
     case'1':
       out.playNote(0.0, 1.0, "C4");
       break;
     case'2':
       out.playNote(0.0, 1.0, "D4");
       break;
     case'3':
       out.playNote(0.0, 1.0, "E4");
       break;
   }
 }
