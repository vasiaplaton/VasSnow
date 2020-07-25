void breath(int del) {
  clear();
  set_br(std_br);
  delay(del);
  for (int i = 0; i < ANODES_Q; i++) {
    for (int j = 0; j < CATHODES_Q; j++) {
      leds[j][i] = 1;
    }
    if (i != 1) delay(del);
  }
  for (int i = ANODES_Q - 1; i >= 0; i--) {
    for (int j = 0; j < CATHODES_Q; j++) {
      leds[j][i] = 0;
    }
    if (i != 2) delay(del);
  }
}
void round_m(int del) {
  clear();
  set_br(std_br);
  delay(del);
  for (int i = 0; i < CATHODES_Q; i++) {
    leds[i][0] = 1;
    delay(del);
    leds[i][2] = 1;
    delay(del);
    leds[i][3] = 1;
    delay(del);
    leds[i][1] = 1;
    delay(del);
  }
  for (int i = 0; i < CATHODES_Q; i++) {
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

void breath2(int fade_del) {
  set_br(MAX_BR);
  ligth_all();
  for (int i = MAX_BR; i >= MIN_BR; i--) {
    set_br(i);
    delay(fade_del);
  }
  for (int i = MIN_BR; i <= MAX_BR; i++) {
    set_br(i);
    delay(fade_del);
  }
}
void round2_m(int del) {
  clear();
  set_br(std_br);
  delay(del);
  for (int i = 0; i < CATHODES_Q; i++) {
    leds[i][0] = 1;
    delay(del);
  }
  for (int i = 0; i < CATHODES_Q; i++) {
    leds[i][2] = 1;
    leds[i][1] = 1;
    delay(del);
  }
  for (int i = 0; i < CATHODES_Q; i++) {
    leds[i][3] = 1;
    delay(del);
  }
  delay(del * 5);
  ///
  for (int i = CATHODES_Q - 1; i >= 0; i--) {
    leds[i][3] = 0;
    delay(del);
  }
  for (int i = CATHODES_Q - 1; i >= 0; i--) {
    leds[i][1] = 0;
    leds[i][2] = 0;
    delay(del);
  }
  for (int i = CATHODES_Q - 1; i >= 0; i--) {
    leds[i][0] = 0;
    delay(del);
  }
  delay(del * 5);
}
void random_m(int del) {
  clear();
  set_br(std_br);
  while (true) {
    int cathode = random_f() % CATHODES_Q;
    int anode = random_f() % ANODES_Q;
    boolean filled = true;
    if (leds[cathode][anode] == 0) {
      leds[cathode][anode] = 1;
      delay(del);
    }
    for (int i = 0; i < CATHODES_Q; i++) {
      for (int j = 0; j < ANODES_Q; j++) {
        if (leds[i][j] == 0) filled = false;
      }
    }
    if (filled) {
      delay(del * 5);
      break;
    }
  }
  //////
  while (true) {
    int cathode = random_f() % CATHODES_Q;
    int anode = random_f() % ANODES_Q;
    boolean filled = false;
    if (leds[cathode][anode] == 1) {
      leds[cathode][anode] = 0;
      delay(del);
    }
    for (int i = 0; i < CATHODES_Q; i++) {
      for (int j = 0; j < ANODES_Q; j++) {
        if (leds[i][j] == 1) filled = true;
      }
    }
    if (!filled) {
      delay(del * 5);
      break;
    }
  }
}
void firework(int del, int fade_del) {
  clear();
  set_br(std_br);
  delay(del * 10);
  for (int i = 0; i < CATHODES_Q / 2; i++) {
    set_br(10);
    leds[i][1] = 1;
    leds[i + 3][1] = 1;
    for (int i = 10; i < MAX_BR / 3; i++) {
      set_br(i);
      delay(fade_del);
    }
    leds[i][2] = 1;
    leds[i + 3][2] = 1;
    for (int i = MAX_BR / 3; i < MAX_BR / 3 * 2; i++) {
      set_br(i);
      delay(fade_del);
    }
    leds[i][3] = 1;
    leds[i + 3][3] = 1;
    for (int i = MAX_BR / 3 * 2; i < MAX_BR; i++) {
      set_br(i);
      delay(fade_del);
    }
    leds[i][0] = 1;
    leds[i + 3][0] = 1;
    for (int i = MAX_BR; i > MIN_BR; i--) {
      set_br(i);
      delay(fade_del);
    }
    clear();
  }
  int counter = 0;
  for (int i = 0; i < ANODES_Q; i++) {
    for (int j = 0; j < CATHODES_Q; j++) {
      leds[j][i] = 1;
    }
    if (i != 1) {
      for (int i = MAX_BR / 3 * counter; i < MAX_BR / 3 * (counter + 1); i++) {
        set_br(i);
        delay(fade_del * 3);
      }
      counter++;
    }
  }
  for (int i = MAX_BR; i > MIN_BR; i--) {
    set_br(i);
    delay(fade_del * 3);
  }
  clear();

}
void ray_m(int del) {
  clear();
  set_br(std_br);
  for (int i = 0; i < CATHODES_Q / 2; i++) {
    for (int j = 0; j < ANODES_Q; j++) {
      leds[i][j] = 1;
      if (j != 1) delay(del);
    }
    for (int j = 0; j < ANODES_Q; j++) {
      leds[i + 3][j] = 1;
      if (j != 1) delay(del);
    }
    delay(del * 2);
  }
  for (int i = CATHODES_Q / 2 - 1; i >= 0; i--) {
    for (int j = ANODES_Q - 1; j >= 0; j--) {
      leds[i][j] = 0;
      if (j != 2) delay(del);
    }
    for (int j = ANODES_Q - 1; j >= 0; j--) {
      leds[i + 3][j] = 0;
      if (j != 2) delay(del);
    }
    delay(del * 2);
  }

}
