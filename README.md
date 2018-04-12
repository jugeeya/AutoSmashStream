# AutoSmashStream
## Description
This is an application used in conjunction with a video feed of a
Super Smash Bros. for Wii U tournament in order to automatically
generate data for viewers in the stream overlay, using OpenCV
and Tesseract API for computer vision and character recognition.
![Description Image](https://github.com/jugeeya/AutoSmashStream/raw/master/showcase.png "Description Image")

## Application itself
![Application Image](https://github.com/jugeeya/AutoSmashStream/raw/master/showcase2.png "Application Image")

## My setup
Here are the tools I use to stream:
El Gato HD60
Windows 10, 1920x1080 resolution
OBS

The window is captured by using a video source called "El Gato" in OBS and creating a "Windowed Capture (Source)" from it, then taking that window and pressing WinKey+LeftArrow to place the window on the left half of the screen. So long as this window is not minimized, the video feed will be captured. The application's bottom left corner indicates whether or not the stream is being read in.

