import numpy as np
from PIL import Image

# Copy paste the array from Arduino Serial monitor to below numpy array
pixel_data = np.array([
236, 103, 97, 95, 88, 85, 84, 83, 84, 83, 83, 82, 83, 85, 88, 90, 90, 93, 
100, 91, 89, 88, 86, 85, 83, 83, 82, 83, 82, 81, 81, 82, 84, 85, 87, 93, 
93, 90, 89, 87, 87, 88, 86, 84, 83, 83, 82, 83, 81, 81, 81, 82, 86, 90, 
91, 90, 91, 90, 94, 96, 92, 85, 84, 86, 88, 89, 86, 83, 82, 81, 84, 87, 
94, 95, 97, 98, 108, 110, 100, 86, 82, 88, 92, 93, 91, 85, 82, 81, 82, 86, 
98, 100, 102, 106, 114, 111, 102, 86, 85, 87, 93, 95, 95, 91, 84, 81, 81, 79, 
94, 99, 104, 111, 118, 111, 101, 87, 85, 87, 94, 94, 97, 97, 86, 82, 80, 73, 
90, 98, 103, 114, 117, 112, 102, 87, 86, 89, 95, 95, 98, 96, 88, 82, 80, 78, 
90, 98, 103, 117, 117, 114, 104, 87, 86, 87, 93, 93, 99, 98, 85, 75, 78, 84, 
90, 96, 102, 113, 117, 117, 106, 88, 86, 87, 92, 93, 95, 91, 81, 81, 82, 86, 
89, 92, 99, 107, 113, 114, 107, 87, 85, 86, 90, 91, 91, 86, 79, 82, 82, 88, 
89, 89, 93, 104, 104, 109, 103, 86, 84, 85, 89, 86, 86, 81, 81, 81, 83, 90, 
89, 88, 88, 93, 98, 101, 97, 86, 84, 84, 85, 84, 82, 81, 82, 83, 87, 89, 
92, 89, 87, 87, 91, 98, 94, 86, 84, 83, 82, 82, 82, 82, 83, 86, 89, 95, 
104, 92, 88, 89, 90, 99, 97, 86, 84, 83, 83, 82, 82, 84, 89, 93, 96, 95, 
114, 111, 100, 93, 96, 106, 100, 89, 87, 87, 86, 88, 92, 95, 96, 98, 94, 98, 
116, 112, 111, 109, 105, 110, 107, 98, 93, 75, 80, 90, 97, 95, 98, 98, 97, 95, 
111, 110, 110, 108, 104, 106, 109, 103, 96, 85, 75, 75, 75, 93, 92, 93, 93, 93
], dtype=np.uint8)

# Resize the array as 18*18 2D matrix
pixel_data.resize(18, 18)
print(pixel_data)

# Apply bitwise & with 63 (00111111) to all the elements.
# because the actual image pixel has just 6-bit grayscale resolution.
# First 2 bits (bits 6 and 7) are the "start_of_frame"
# and "Data_Valid" flags, which are not required to construct image
pixel_data = np.bitwise_and(pixel_data, 63)
print(pixel_data)

# Multiply each element by 4 (or say left shift by 2 places)
# so that it becomes an 8-bit grayscale image, 
# althogh the resolution is still 6-bit.
# The reasons being that 8-bit image will look a bit better
# compared to 6-bit, and python PIL library shows 8-bit grayscale image
pixel_data = pixel_data * 4
print(pixel_data)

# Convert numpy array to image > save it > display it
im = Image.fromarray(pixel_data)
im.save("mouse_capture.png")
im.show()

