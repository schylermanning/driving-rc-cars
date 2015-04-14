# Driving RC Cars with Node.js and C++

## Prerequisites / Dependencies
- NPM
- Node.js
- Node Serial Port  (Node.js package to access serial ports for reading and writing)
  - https://github.com/voodootikigod/node-serialport
```
npm install serialport
```

- Node Servi  (A simple library for serving web pages)
  - https://www.npmjs.com/package/servi
```
npm install servi
```

- Basic soldering

## RC Car
- Picking an RC Car
- Wiring Digital vs Analog Buttons
- Determining power consumption differences needed for various controllers


## Arduino
- Creating serial server and mapping input to GPIO
- Need 4 GPIO for Car and 2 GPIO for TX/RX via USB
- Arduino Nano or larger required*
- Using Uno for this project


## Node.js
- Running Node v0.12.0 as serial client.
  - Currently having issues with memory leak
  - Could also use Socat in Linux or Virtual Serial Port in Windows
