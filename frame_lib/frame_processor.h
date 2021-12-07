#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <iostream>

#include <opencv2/opencv.hpp>
#include <boost/lockfree/spsc_queue.hpp>

class FrameProcessor
{
public:
    FrameProcessor();

    cv::Mat Process(const cv::Mat &frame);
};

#endif // FRAMEPROCESSOR_H
