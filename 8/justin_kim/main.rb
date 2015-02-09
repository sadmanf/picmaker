require_relative 'ppm'

DIM = 1000
WIDTH = DIM
HEIGHT = DIM
OUTPUT_FILENAME = 'output.ppm'

def red(x, y)
  s = 3.0 / (y + 99)
  y = (y+Math.sin((x*x+((y-700)**2)*5)/100.0/DIM)*35)*s
  ((((x + DIM) * s + y) % 2).to_i + (((DIM * 2 - x) * s + y) % 2).to_i) * 127
end

def green(x, y)
  s = 3.0 / (y + 99)
  y = (y+Math.sin((x*x+((y-700)**2)*5)/100.0/DIM)*35)*s
  ((10 * ((x + DIM) * s + y) % 2).to_i + (10 * ((DIM * 2 - x) * s + y) % 2).to_i) * 127
end

def blue(x, y)
  s = 3.0 / (y + 99)
  y = (y+Math.sin((x*x+((y-700)**2)*5)/100.0/DIM)*35)*s
  ((25 * ((x + DIM) * s + y) % 2).to_i + (25 * ((DIM * 2 - x) * s + y) % 2).to_i) * 127
end


# Generate pixels
image_data = []

(0...HEIGHT).each do |y|
  row = []
  (0...WIDTH).each do |x|
    row << [red(x, y), green(x, y), blue(x, y)]
  end
  image_data << row
end

# Write to file
p = PPM.new(image_data)
File.open(OUTPUT_FILENAME, 'w') do |f|
  p.write(f)
end
