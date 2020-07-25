void breath(int del){
  clear();
  byte ray[ANODES_Q] = {0, 0, 0, 0};
  set_rays(ray);
  center = true;
  delay(del);
  ray[0] = 1;
  set_rays(ray);
  delay(del);
  ray[1] = 1;
  ray[2] = 1;
  set_rays(ray);
  delay(del);
  ray[3] = 1;
  set_rays(ray);
  delay(del);
  ray[3] = 0;
  set_rays(ray);
  delay(del);
  ray[1] = 0;
  ray[2] = 0;
  set_rays(ray);
  delay(del);
  ray[0] = 0;
  set_rays(ray);
  delay(del);
  //center = false;
  //delay(del);
}
void roundd(int del, int fade_del){
  clear();
  set_br(std_br);
  delay(del);
  for(int i=0; i<CATHODES_Q; i++){
    leds[i][0] = 1;
    delay(del);
    leds[i][2] = 1;
    delay(del);
    leds[i][3] = 1;
    delay(del);
    leds[i][1] = 1;
    delay(del);
  }
  for(int i=0; i<CATHODES_Q; i++){
    leds[i][0] = 0;
    delay(del);
    leds[i][2] = 0;
    delay(del);
    leds[i][3] = 0;
    delay(del);
    leds[i][1] = 0;
    delay(del);
  }
}

void breath2(int fade_del){
  set_br(MAX_BR);
  ligth_all();
  for(int i=MAX_BR; i>=MIN_BR; i--){
    set_br(i);
    delay(fade_del);
  }
  for(int i=MIN_BR; i<=MAX_BR; i++){
    set_br(i);
    delay(fade_del);
  }
}
