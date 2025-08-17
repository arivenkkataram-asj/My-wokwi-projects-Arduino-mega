/*Displaing any number 0000 to 9999 using of 8pins for 7segment 
And 4 pins for digit seletion*/

void init_port(void);
void output_f(char);
void output_f_k_a_c(char);
volatile char num_7segment[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
volatile char digit_sel[]={0xFF,0xF7,0xFB,0xFD,0xFE};
// FF = all OFF, F7 = digit1 ON, FB = digit2 ON, FD = digit3 ON, FE = digit4 ON

void init_port(){
  volatile char *port_f_dir,*port_k_dir;
  port_f_dir = 0x30;  port_k_dir = 0x107;
  *port_f_dir = 0xFF; *port_k_dir = 0xFF; 
}
void output_f(char outdata_f){
  volatile char *port_f_data = 0x31;
  *port_f_data = outdata_f;
}


void output_k(char outdata_k){
  volatile char *port_k_data = 0x108;
  *port_k_data = outdata_k;
}
void delays(){ // changing the digits at a time
  volatile long i;
  for(i=0;i<1000;i++);
}
void delays_long(){ // having an 1sec delay
  volatile long i;
  for(i=0;i<100000;i++);
}

void digits_4(unsigned int digit){
  char num_bin[4]={0},i=3;
  while(digit){
    num_bin[i]= digit%10;
    digit/=10;
    i--;
  }
  // Digit 1 → "1"
  output_f(num_7segment[num_bin[0]]);
  output_k(digit_sel[4]);
  delays();
  output_k(digit_sel[0]);  // turn OFF

  // Digit 2 → "2"
  output_f(num_7segment[num_bin[1]]);
  output_k(digit_sel[3]);
  delays();
  output_k(digit_sel[0]);

  // Digit 3 → "3"
  output_f(num_7segment[num_bin[2]]);
  output_k(digit_sel[2]);
  delays();
  output_k(digit_sel[0]);

  // Digit 4 → "4"
  output_f(num_7segment[num_bin[3]]);
  output_k(digit_sel[1]);
  delays();
  output_k(digit_sel[0]);

}
void setup() {

  init_port();
  
}

void loop(){
        int i=3425;  //Here you can give any input from 0 to 9999;
        digits_4(i);
}
