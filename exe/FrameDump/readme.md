
# FrameDump

## CLI

This utility takes a video file as input and outputs its frames as separate image files in the local directory. A great testbed for AVL_ffmpeg, it supports video files compatible with FFMPEG and image formats supported by AIL_IO.

Use the following command format:

./FrameDump.exe <SourceMovieName> <DestImageType>

Example:
./FrameDump.exe A.mpg png

Expected Output:
./000001.png
./000002.png
./000003.png
...
...

## Dependencies

The project depends on the following libraries:

- ./lib/AIL_IO
- ./lib/AVL_ffmpeg