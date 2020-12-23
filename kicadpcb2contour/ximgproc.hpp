/*
 *  By downloading, copying, installing or using the software you agree to this license.
 *  If you do not agree to this license, do not download, install,
 *  copy or use the software.
 *
 *
 *  License Agreement
 *  For Open Source Computer Vision Library
 *  (3 - clause BSD License)
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met :
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and / or other materials provided with the distribution.
 *
 *  * Neither the names of the copyright holders nor the names of the contributors
 *  may be used to endorse or promote products derived from this software
 *  without specific prior written permission.
 *
 *  This software is provided by the copyright holders and contributors "as is" and
 *  any express or implied warranties, including, but not limited to, the implied
 *  warranties of merchantability and fitness for a particular purpose are disclaimed.
 *  In no event shall copyright holders or contributors be liable for any direct,
 *  indirect, incidental, special, exemplary, or consequential damages
 *  (including, but not limited to, procurement of substitute goods or services;
 *  loss of use, data, or profits; or business interruption) however caused
 *  and on any theory of liability, whether in contract, strict liability,
 *  or tort(including negligence or otherwise) arising in any way out of
 *  the use of this software, even if advised of the possibility of such damage.
 */

#ifndef __OPENCV_XIMGPROC_HPP__
#define __OPENCV_XIMGPROC_HPP__


 /** @defgroup ximgproc Extended Image Processing
   @{
     @defgroup ximgproc_edge Structured forests for fast edge detection

 This module contains implementations of modern structured edge detection algorithms,
 i.e. algorithms which somehow takes into account pixel affinities in natural images.

     @defgroup ximgproc_edgeboxes EdgeBoxes

     @defgroup ximgproc_filters Filters

     @defgroup ximgproc_superpixel Superpixels

     @defgroup ximgproc_segmentation Image segmentation

     @defgroup ximgproc_fast_line_detector Fast line detector

     @defgroup ximgproc_fourier Fourier descriptors

     @defgroup ximgproc_run_length_morphology Binary morphology on run-length encoded image

     These functions support morphological operations on binary images. In order to be fast and space efficient binary images are encoded with a run-length representation.
     This representation groups continuous horizontal sequences of "on" pixels together in a "run". A run is charactarized by the column position of the first pixel in the run, the column
     position of the last pixel in the run and the row position. This representation is very compact for binary images which contain large continuous areas of "on" and "off" pixels. A checkerboard
     pattern would be a good example. The representation is not so suitable for binary images created from random noise images or other images where little correlation between neighboring pixels
     exists.

     The morphological operations supported here are very similar to the operations supported in the imgproc module. In general they are fast. However on several occasions they are slower than the functions
     from imgproc. The structuring elements of cv::MORPH_RECT and cv::MORPH_CROSS have very good support from the imgproc module. Also small structuring elements are very fast in imgproc (presumably
     due to opencl support). Therefore the functions from this module are recommended for larger structuring elements (cv::MORPH_ELLIPSE or self defined structuring elements). A sample application
     (run_length_morphology_demo) is supplied which allows to compare the speed of some morphological operations for the functions using run-length encoding and the imgproc functions for a given image.

     Run length encoded images are stored in standard opencv images. Images have a single column of cv::Point3i elements. The number of rows is the number of run + 1. The first row contains
     the size of the original (not encoded) image.  For the runs the following mapping is used (x: column begin, y: column end (last column), z: row).

     The size of the original image is required for compatibility with the imgproc functions when the boundary handling requires that pixel outside the image boundary are
     "on".

     @}
 */

namespace cv
{
    namespace ximgproc
    {

        enum ThinningTypes {
            THINNING_ZHANGSUEN = 0, // Thinning technique of Zhang-Suen
            THINNING_GUOHALL = 1  // Thinning technique of Guo-Hall
        };

        /**
        * @brief Specifies the binarization method to use in cv::ximgproc::niBlackThreshold
        */
        enum LocalBinarizationMethods {
            BINARIZATION_NIBLACK = 0, //!< Classic Niblack binarization. See @cite Niblack1985 .
            BINARIZATION_SAUVOLA = 1, //!< Sauvola's technique. See @cite Sauvola1997 .
            BINARIZATION_WOLF = 2,    //!< Wolf's technique. See @cite Wolf2004 .
            BINARIZATION_NICK = 3     //!< NICK technique. See @cite Khurshid2009 .
        };

        //! @addtogroup ximgproc
        //! @{
        
        /** @brief Applies a binary blob thinning operation, to achieve a skeletization of the input image.

        The function transforms a binary blob image into a skeletized form using the technique of Zhang-Suen.

        @param src Source 8-bit single-channel image, containing binary blobs, with blobs having 255 pixel values.
        @param dst Destination image of the same size and the same type as src. The function can work in-place.
        @param thinningType Value that defines which thinning algorithm should be used. See cv::ximgproc::ThinningTypes
         */
        CV_EXPORTS_W void thinning(InputArray src, OutputArray dst, int thinningType = THINNING_ZHANGSUEN);

        //! @}

    }
}

#endif // __OPENCV_XIMGPROC_HPP__