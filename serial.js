
var serialport = require("/usr/local/node_sources/node_modules/serialport/serialport"),
    SerialPort = serialport.SerialPort,
    servi = require('/usr/local/node_sources/node_modules/servi'),
    app = new servi(false);

app.port(8082);
app.route('/', setIndexPage);
app.route('/radio/', sendDirection);
app.route('/radio/:direction', sendDirection);

app.start();
console.log("Listening on port 8082");
/*
*  The portName changes depending on the USB port used.
*
* */


var portName = "/dev/tty.usbmodem1411";

var newPort = new SerialPort(portName, {
    baudRate: 9600,
    parser: serialport.parsers.readline("\r\n")
});

/**
 *
 * @param {type} request
 * @returns {undefined}
 */
function setIndexPage(request) {
    request.serveFile('./index.html');
}


/**
 *
 * @param {type} request
 * @returns {undefined}
 */
function sendDirection(request) {
    var direction = request.params.direction;
    // Pass direction to serial
    newPort.write(direction, function () {
        // Write serial response for the client
        newPort.on('data', function (data) {
            // Send response
            request.respond(data);
        });
    });

}


