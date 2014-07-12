# duino-bots
Arduino &amp; Node.js experiments

## Setup
* Clone this repo `git clone git@github.com:orendon/duino-bots.git`
* Install dependencies `npm install`
* Run the server/script according to the example


## Arduino
Arduino projects using just Arduino and C++

### - Remote controlled car (bluetooth)
Bluetooth controlled car, compatible with most Android/iOS bluetooth apps.
It uses HC-06 module, Arduino motor shield and 2 DC motors.
Tested using [Bluetooth Controller](https://play.google.com/store/apps/details?id=apps.BT&hl=en) for Android, but compatible with most Android/iOS similar apps.
Grab the code on `arduino/bluetooth_car/`

### - Blinking led
Simple led blinking every second, grab the code on `arduino/blink/`

## Nodebots
Arduino projects using node.js (johnny-five), this ones requires you to load firmata into the arduino

* Open the Arduino IDE, select: File > Examples > Firmata > StandardFirmata
* Click "upload" button to load firmata into the arduino

### - RGB Led through web app
Control your lights at home using this web application
Watch it live on [youtube](http://www.youtube.com/watch?v=c3o9VuWy7ls), grab the code on `nodebots/rgb_led_webapp/`

* setup circuit and connect your arduino
* start the server, `node app`
* access the web app, `http://localhost:3000/rgb_led/`

### - Blinking led
* setup circuit and connect your arduino, led on PIN 13
* run the script, `node nodebots/blink/`
