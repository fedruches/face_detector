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
    FrameProcessor(std::atomic_bool &isStop);

    ~FrameProcessor();

    cv::Mat Process(const cv::Mat &frame);

    void WorkFunc();

    void Run();

private:
    std::thread _workerThread;

    std::atomic_bool &_isStop;
};

#endif // FRAMEPROCESSOR_H
