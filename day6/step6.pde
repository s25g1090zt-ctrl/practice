import ddf.minim.*;
import ddf.minim.ugens.*;

Minim minim;
AudioOutput out;
Waveform currentWaveform;
String[] melody = {"C4", "D4", "E4", "F4", "E4", "D4", "C4"}; // 音の高さ
float[] duration = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0};       // 音の長さ
float[] startTime = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0};      // 鳴り始める時間

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

void playSong(){
  out.pauseNotes();
  float delayTime = 2.0;
  for(int i=0; i<melody.length; i++){
    out.playNote(startTime[i], duration[i], new HackInstrument(Frequency.ofPitch( melody[i] ).asHz(), 0.5, currentWaveform) );
    out.playNote(startTime[i]+delayTime, duration[i], new HackInstrument(Frequency.ofPitch( melody[i] ).asHz(), 0.5, currentWaveform) );

  }
    out.resumeNotes();
}

class HackInstrument implements Instrument {
  Oscil wave;
  Line ampEnv;
  
  // コンストラクタ
  HackInstrument(float frequency, float maxAmp, Waveform wf){
    wave = new Oscil(frequency, 0, wf);
    ampEnv = new Line();
    ampEnv.patch(wave.amplitude);
  }
  
  void noteOn(float duration){
    ampEnv.activate(duration, 0.5f, 0);
    wave.patch(out);
  }
  
  // 抜けていた noteOff を追加
  void noteOff(){
    wave.unpatch(out);
  }
}

void keyPressed(){
  switch(key){
    case'p':
      playSong();
      break;
  }
}
  