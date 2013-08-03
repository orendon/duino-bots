var express = require('express'),
    http = require('http');

var app = express(),
    server = http.createServer(app)

app.configure(function(){
  app.set('port', process.env.PORT || 3000);
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.use(express.favicon());
  app.use(express.logger('dev'));
  app.use(express.bodyParser());
  app.use(express.methodOverride());
  app.use(app.router);
  app.use(express.static(__dirname, '/public'));
});

app.configure('development', function(){
  app.use(express.errorHandler());
});

app.get('/rgb_led', function(req, res){
  res.render('rgb_led');
});

var io = require('socket.io').listen(server.listen(3000));