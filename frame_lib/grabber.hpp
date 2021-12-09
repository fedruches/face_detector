#ifndef MODULE_H
#define MODULE_H

#include <memory>
#include <thread>

#include <opencv2/opencv.hpp>
#include <boost/lockfree/spsc_queue.hpp>

#include "thread_queue.hpp"

class Grabber
{
public:
    enum class EDeviceType : uint8_t
    {
        file = 0,
        camera = 1
    };

    enum class EOpenStatus : uint8_t
    {
        success = 0,
        error = 1
    };

    Grabber(const std::string &devicePath, EDeviceType deviceType, std::atomic_bool &isStop);

    ~Grabber();

    EOpenStatus Open();

    std::pair<bool, cv::Mat> GetFrame();

    void WorkFunc();

    void Run();

private:
    std::unique_ptr<cv::VideoCapture> _capturePtr;

    std::string _devicePath;

    std::thread _workerThread;

    std::atomic_bool &_isStop;
};

#endif // MODULE_H
