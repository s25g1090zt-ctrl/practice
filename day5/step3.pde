import ddf.minim.*;

Minim minim;
AudioOutput out;

void setup(){
  size(200, 200);
  minim = new Minim(this);
  out = minim.getLineOut();
  
  out.playNote(0.0, 2.0, "C4");
}

void draw(){
  background(0);
  stroke(255);
  
  for(int i=0; i<out.bufferSize(); i++){
    line(20, 100+out.left.get(i)*50, 180, 100+out.left.get(i+1)*50);
  }
  
 void keyPress
