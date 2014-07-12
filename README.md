# duino-bots
Arduino &amp; Node.js experiments

## Setup
* Clone this repo `git clone git@github.com:orendon/duino-bots.git`
* Install dependencies `npm install`
* Run the server/script according to the example


## Arduino
Arduino projects using just Arduino and C++

### - Blinking led
Simple led blinking every second, grab the code on `arduino/blink/blink.ino`

## Nodebots (node.js, johnny-five and arduino)
Arduino projects using node.js, this ones requires you to load firmata into the arduino

* Open the Arduino IDE, select: File > Examples > Firmata > StandardFirmata
* Click "upload" button to load firmata into the arduino

### - RGB Led through web app
watch it live on [youtube](http://www.youtube.com/watch?v=c3o9VuWy7ls), grab the code on `nodebots/rgb_led_webapp/`

* setup circuit and connect your arduino
* start the server, `node app`
* access the web app, `http://localhost:3000/rgb_led/`

### - Blinking led
* setup circuit and connect your arduino, led on PIN 13
* run the script, `node nodebots/blink/blink.js`
