## kicad-laser-min

The application will take a PCB file generated by KICAD and create paths which will isolate all PCB tracks  from each other. This has the added benefit
of minimum laser travel.

### Usage

Usage: 
    Option: -m         Process map.png directly
            -f         Process Front Copper Layer. (default Bottom Copper Layer)
            -p<pxmm>   Change pixels per mm (default 30)


### Files
kicadpcb2contour.cpp

### Dependencies
OpenCV libraries (version 4.2 used)

### Compilation
`g++ -g kicadpcb2contour.cpp -o kicadpcb2contour -I /usr/local/include/opencv4/opencv -I /usr/local/include/opencv4 -L /usr/local/lib -l opencv_dnn -l opencv_gapi -l opencv_highgui -l opencv_ml -l opencv_objdetect -l opencv_photo -l opencv_stitching -l opencv_video -l opencv_calib3d -l opencv_features2d -l opencv_flann -l opencv_videoio -l opencv_imgcodecs -l opencv_imgproc -l opencv_core`

### Docker image( To come )

### Errors

Opencv follow contour sometimes does not make closed contours. This is a problem in PCB making, as it would short-circuit PCB tracks. 
However, as shown the inter-contour distance tolerance is of 0.066mm. I have a laser cutter with an engraving width of 0.2mm (i.e. a
possible 0.1mm engraving width on the centre of track to a track coninciding from left or right side)