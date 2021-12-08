#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <iostream>
#include <thread>

#include <opencv2/opencv.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include "thread_queue.hpp"

class FrameProcessor
{
public:
    FrameProcessor();

    ~FrameProcessor();

    cv::Mat Process(const cv::Mat &frame);

    void WorkFunc();

    void Run();

private:
    std::thread _workerThread;
};

#endif // FRAMEPROCESSOR_H
