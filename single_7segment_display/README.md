# Arduino Mega with Seven Segment Display (0–9 Counter)

This project demonstrates how to interface a **7-segment display** with an **Arduino Mega** using **bare-metal programming** (direct register access).  
The display counts from **0 to 9** with a simple delay in between.

---

## 🖼️ Circuit Connection

The project connects an **Arduino Mega 2560** with a **common cathode 7-segment display**.  
Pins from the Arduino are connected directly to the 7-segment display segments.

## Wiring  
- Arduino **PORTF (pins A0–A7)** → **7-Segment Display segments (a–g + dp)**  
- Arduino **GND** → **Display common cathode**

---

## ⚙️ Code Explanation

The code is written in **bare-metal C** style by directly configuring registers:

```c
void delays(void);

void setup(){
  volatile char *dir;  // seting the Direction of the Port F
  dir = 0x30;
  *dir = 0xFF; //Setting all the Pins as the OUTPUT PIN
}
void delays(){  //System Delay
  volatile long i;
  for(i=0;i<500000;i++);
}

void loop(){
  volatile char num_7segment[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  //This num_7segment[] refers to the num 0 to 9
  volatile char *out; 
  out = 0x31;  
  for(char j=0;j<10;j++){
    *out = num_7segment[j];
    delays();
  }
}
```
## 📸 Demo (Simulation)
![20250817-1323-59 6653235]([https://github.com/user-attachments/assets/e3a5d908-c776-4a0b-825b-82b2c3b676c4](https://github.com/arivenkkataram-asj/My-wokwi-projects-Arduino-mega/blob/main/single_7segment_display/Simulation_output_gif.gif))


## 📚 Learning Takeaways

-->Interfacing a 7-segment display with Arduino.

-->Understanding bare-metal programming (direct register manipulation).


##🔧 Requirements

1. Arduino Mega 2560

2. Common Cathode 7-Segment Display

3. Jumper Wires


