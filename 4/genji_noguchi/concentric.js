module.exports = function(width, height) {

	var circle = function(cx, cy, rad) {
		return function(arr) {
			semicircle(1, cx, cy, rad)(arr);
			semicircle(-1, cx, cy, rad)(arr);
		}
	}

	/*
	 * Function to plot out a semicircle.
	 * Put in -1 or 1 for up.
	 *
	 */
	function semicircle(up, cx, cy, rad) {
		if(up===-1 || up===1) {
			return function(arr) {
				function f(x) {
					return up*Math.sqrt((rad*rad) - (x*x));
				}
				var y=0;
				for (var x=-rad;x<=rad;x++) {
					y = Math.round(f(x));
					if (!isNaN(y)) {
						try {
							arr[cx + x][cy + y].red = 255;
							arr[cx + x][cy + y].green = 255;
							arr[cx + x][cy + y].blue = 255;
						} catch (err) {}
					}
				}
			}
		} else {
			console.log("test2 : use -1 or 1 for the first parameter.");
		}
	}

	return {
		circle: circle
	}
}
