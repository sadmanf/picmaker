/* 
 * The main file for creating PPM files.
 * For STUYCS Graphics MKS65.
 *
 * by Genji Noguchi
 */

var mod = "./concentric.js";
var filename = "concentric.ppm";
var ppm = "",
	header = "P3",
	width = 900,
	height = 900,
	colorres = 255,
	pixels;


var fs = require('fs');
var draw = require(mod)(width, height);


/* Header */
ppm += header;
ppm += "\n";
ppm += width + " " + height;
ppm += "\n";
ppm += colorres;
ppm += "\n";


/* Initialize the 2d pixel array */

function init() {
	function Pixel(r,g,b) {
		this.red = r? 0:r;
		this.green = g? 0:g;
		this.blue = b? 0:b;
		
	}

	pixels = new Array(width);
	for (var l=0; l<pixels.length; l++) pixels[l] = new Array(height);
	for (var x=0;x<pixels.length; x++) {
		for (var y=0;y<pixels[0].length; y++) {
			pixels[x][y] = new Pixel(0,0,0);
		}
	}
}

/*
 * Function to turn the array into a string
 *
 */
function stringify(arr) {
	var str = "";
	for(var x=0;x<arr.length;x++) {
		for(var y=0;y<arr[0].length;y++) {
			str += arr[y][x].red+" "+arr[x][y].green+" "+arr[x][y].blue+" ";
		}
	}
	return str;
}

init();
for(var x=1;x<25;x++) draw.circle(width/2, height/2, (x*x))(pixels);
ppm += stringify(pixels);

fs.writeFile(filename, ppm, function(err) {
	if(err) {
		console.log(err);
	} else {
		console.log("The file was saved!");
	}
}); 
