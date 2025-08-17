void delays(void);

void setup(){
  volatile char *dir;
  dir = 0x30;
  *dir = 0xFF;
}
void delays(){
  volatile long i;
  for(i=0;i<500000;i++);
}

void loop(){
  volatile char num_7segment[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  volatile char *out;
  out = 0x31;
  for(char j=0;j<10;j++){
    *out = num_7segment[j];
    delays();
  }
}