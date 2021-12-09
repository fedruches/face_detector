#ifndef THREAD_QUEUE_HPP
#define THREAD_QUEUE_HPP

#include <boost/lockfree/spsc_queue.hpp>
#include <opencv2/opencv.hpp>

class ThreadQueue
{

public:
    static bool Push(const cv::Mat &frame)
    {
        return _spscQueue.push(frame);
    }

    static bool Pop(cv::Mat &frame)
    {
        return _spscQueue.pop(frame);
    }

private:
    static boost::lockfree::spsc_queue<cv::Mat, boost::lockfree::capacity<1024>> _spscQueue;
};

#endif // THREAD_QUEUE_HPP
