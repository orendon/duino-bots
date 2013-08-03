var arduino = require("johnny-five"),
    board, led;

board = new arduino.Board();

board.on("ready", function() {
  // the led is wired on these pins
  led = new arduino.Led.RGB([9, 10, 11]);

  this.repl.inject({
    led: led
  });
});