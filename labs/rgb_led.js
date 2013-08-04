var arduino = require("johnny-five"),
    board, led;

module.exports = function (io) {
  io.sockets.on('connection', function (socket) {
    board = new arduino.Board();

    board.on("ready", function () {
      led = new arduino.Led.RGB([9, 10, 11]); // Led is wired on these pins

      this.repl.inject({
        led: led
      });

      socket.on('set_color', function (color) {
        // console.log(color);

        led.red.brightness(color.red)
        led.green.brightness(color.green)
        led.blue.brightness(color.blue)
      });
    });

  });
};