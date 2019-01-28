# fdf
A simple wireframe engine in C.
The graphical library used is MiniLibx, homemade library of school 42.

Open a file composed of integers, separated by spaces.
Each integer represent a point, its column represent its X coordinate, its row represent its Y coordinate, and its value represent its Z coordinate.

Usage:
  `./fdf maps/file.fdf`

You can change render colors by changin defines in includes/fdf.h.

Keys:
  * q/w: rotating camera around Z axis
  * a/s: rotating camera around Y axis
  * +/-: zoom
  * arrows: changing render offset on screen
