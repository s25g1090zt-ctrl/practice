import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
Waveform currentWaveform ; 

void setup(){
  size(512, 200);
  minim = new Minim(this);
  out = minim.getLineOut();
  currentWaveform = Waves.SINE;
}

void draw(){
  background(0);
  stroke(255);
  
  for(int i=0; i<out.bufferSize()-1; i++){
    line(i, 100+out.left.get(i)*50, i+1, 100+out.left.get(i+1)*50);
  }
}
// --- ここから下はコピペして配置してください ---
class HackInstrument implements Instrument {
  Oscil wave;
  Line ampEnv;
  HackInstrument(float frequency, float maxAmp, Waveform wf) {
    wave = new Oscil(frequency, 0, wf);
    ampEnv = new Line();
    ampEnv.patch(wave.amplitude);
  }
  void noteOn(float duration) {
    ampEnv.activate(duration, 0.5f, 0);
    wave.patch(out);
  }
  void noteOff() {
    wave.unpatch(out);
  }
}
// --- ここまで ---
  
 void keyPressed(){
   switch(key){
     case'1':
       currentWaveform = Waves.SINE;
       break;
       
      case'2':
        currentWaveform = Waves.TRIANGLE;
        break;
        
       case'3':
         currentWaveform = Waves.SAW;
         break;
         
        case'p':
        out.playNote(0.0, 1.0, new HackInstrument(Frequency.ofPitch("C4").asHz(), 0.5, currentWaveform));
        break;
   }
 }
        
