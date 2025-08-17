# Arduino Mega 7-Segment 4-Digit Counter (0000–9999)
---
This project demonstrates how to interface a 4-digit 7-segment display with an Arduino Mega using bare-metal programming. The display counts from 0000 to 9999 using only 12 pins:

8 pins → for 7-segment data input

4 pins → for digit selection

# 🖼️ Circuit Diagram
---
## ⚡ Working Principle
The 7-segment display is multiplexed:

  Only one digit is active at a time.

  Digits are switched very quickly, giving the illusion that all digits are ON simultaneously.

The program loops from 0000 → 9999, refreshing each digit at high speed.
# 🔧 Connections
PORTF (0–7) → Segment pins (a–g + dp)

PORTK (0–3) → Digit select pins (1–4)

```c
/*Counting of numbers */

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
void delays(){
  volatile long i;
  for(i=0;i<1000;i++);
}

void setup() {
  init_port();

}

void loop() {
  for(char i=0;i<9;i++){//1000th digit
        for(char j=0;j<9;j++){//100th digit
            for(char k=0;k<9;k++){//10th digit
                for(char l=0;l<9;l++){
                    unsigned char p=100;
                    while(p){
                    // Digit 1 → "1"
                    output_f(num_7segment[i]);
                    output_k(digit_sel[4]);
                    delays();
                    output_k(digit_sel[0]);  // turn OFF

                    // Digit 2 → "2"
                    output_f(num_7segment[j]);
                    output_k(digit_sel[3]);
                    delays();
                    output_k(digit_sel[0]);

                    // Digit 3 → "3"
                    output_f(num_7segment[k]);
                    output_k(digit_sel[2]);
                    delays();
                    output_k(digit_sel[0]);

                    // Digit 4 → "4"
                    output_f(num_7segment[l]);
                    output_k(digit_sel[1]);
                    delays();
                    output_k(digit_sel[0]);
                    p--;
                    }
                }    
            }
        }
    }
}
```
# 📊 Output
The display starts at 0000

Increments up to 9999
<img width="923" height="798" alt="image" src="https://github.com/user-attachments/assets/70509976-77ea-4582-b63f-f3699f11363a" />



