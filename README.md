# optical-mouse-hack
 
Github Repo containing Arduino code to interface with Optical Mouse Sensor ADNS-2610.
For more information, please read my hackster article here : https://www.hackster.io/RVLAD/tinkering-with-an-old-optical-mouse-using-arduino-85e396

Also, this project makes use of the OptiMouse Library, located [here](https://github.com/zapmaker/OptiMouse)

Repo Structure :
- xy_Coordinates 
    - Arduino code to get the coordinates of the mouse.
- image_capture 
    - Arduino code to read the sensor's pixel data buffer and output the image as array over serial monitor
- image_capture_python
    - Python code to convert the array output by arduino into grayscale image.

