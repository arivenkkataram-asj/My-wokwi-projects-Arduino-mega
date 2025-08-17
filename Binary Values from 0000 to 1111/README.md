# Arduino Mega 7-Segment Binary Counter (0000–1111)

This project demonstrates how to display **binary numbers (0000 to 1111)** on a 4-digit common cathode 7-segment display using **Arduino Mega** and **bare-metal register programming**.  
The program converts decimal numbers (0–15) into 4-bit binary and shows the result across 4 digits.

---

## 🔧 Features
- Displays binary numbers from **0000 to 1111**.
- Uses **direct register access** instead of Arduino libraries for better control.
- Multiplexing technique for 4-digit display.
- Includes timing functions for stable display output.

---

## 🖥️ Hardware Requirements
- **Arduino Mega 2560**
- **4-Digit Common Cathode 7-Segment Display**
- Jumper wires & breadboard

---

## ⚡ Pin Configuration
- **PORTF** → Segment control (a–g + DP)  
- **PORTK** → Digit selection (D1–D4)  

### Digit Select Mapping:
- `0xFF` → All OFF  
- `0xF7` → Digit 1 ON  
- `0xFB` → Digit 2 ON  
- `0xFD` → Digit 3 ON  
- `0xFE` → Digit 4 ON  

---

## 📜 Code Explanation
- `init_port()` → Configures **PORTF** & **PORTK** as output.  
- `output_f()` / `output_k()` → Send data to PORTF/PORTK.  
- `digits_4()` → Splits a decimal number into 4-bit binary and displays each bit on a digit.  
- `loop()` → Runs a counter from 0 to 15, displaying each binary number.  

---

## ▶️ How It Works
1. Counter starts at `0000` (decimal 0).  
2. Each increment updates the 4-digit display with binary equivalent.  
   - Example:  
     - Decimal 5 → Binary `0101` → Display shows `0101`  
     - Decimal 10 → Binary `1010` → Display shows `1010`  
3. Repeats up to `1111` (decimal 15).  

---

## ⏱️ Timing
- **`delays()`** → Short delay for multiplexing digits.  
- **`delays_long()`** → 1-second delay between counts.  
- Each number stays visible long enough using a refresh loop.

---
## > Wokwi Link - https://wokwi.com/projects/439543782874366977
---
## 📷 Demo (Concept)
<img width="964" height="797" alt="image" src="https://github.com/user-attachments/assets/e7e9c05b-e333-4936-b070-ae313a7b41f6" />

