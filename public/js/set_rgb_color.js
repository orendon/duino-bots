
var socket = io.connect('http://localhost');

function setColor(color) {
  socket.emit('set_color', {
    red   : color.rgb[0] * 255,
    green : color.rgb[1] * 255,
    blue  : color.rgb[2] * 255
  });
}