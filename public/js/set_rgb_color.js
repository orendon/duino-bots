
// conects to socket.io server
var socket = io.connect('http://localhost');

// notify color change
function setColor(color) {
  socket.emit('set_color', {
    red   : color.rgb[0] * 255,
    green : color.rgb[1] * 255,
    blue  : color.rgb[2] * 255
  });
}

// shows user camara (if present)
window.addEventListener("DOMContentLoaded", function() {
  var video = document.querySelector("video"),
    videoObj = { "video": true },
    errBack = function(error) {
      console.log("Video capture error: ", error.code);
    };

  if(navigator.getUserMedia) {
    navigator.getUserMedia(videoObj, function(stream) {
      video.src = stream;
      video.play();
    }, errBack);
  } else if(navigator.webkitGetUserMedia) {
    navigator.webkitGetUserMedia(videoObj, function(stream){
      video.src = window.webkitURL.createObjectURL(stream);
      video.play();
    }, errBack);
  }
}, false);