import ddf.minim.*;//minimをインポート，「＊」はminimのすべて使えるようにする．

Minim minim;
AudioOutput out;

void setup(){
  size(200, 200);
  minim = new Minim(this);//minimを起動
  out = minim.getLineOut();//パソコンから音をだす．minimの出力
  
  out.playNote(0.0, 4.0, "E4");//音を鳴らすプログラム（開始時間，鳴らす時間，音の高さ）
}

void draw(){
  background(0);
}
