#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

class EyeTracker {
public:
    EyeTracker() : cursor_x(0), cursor_y(0), running(false) {}

    void startTracking() {
        running = true;
        trackingThread = std::thread(&EyeTracker::_updateCursor, this);
    }

    void stopTracking() {
        running = false;
        if (trackingThread.joinable()) {
            trackingThread.join();
        }
    }

    std::pair<int, int> getCursorPosition() {
        return std::make_pair(cursor_x, cursor_y);
    }

private:
    int cursor_x;
    int cursor_y;
    bool running;
    std::thread trackingThread;

    void _updateCursor() {
        while (running) {
            // Simulate eye movement control here
            cursor_x += 1;
            cursor_y += 1;

            // Limit cursor position to screen boundaries
            int screen_width = 1920;
            int screen_height = 1080;
            cursor_x = std::max(0, std::min(cursor_x, screen_width));
            cursor_y = std::max(0, std::min(cursor_y, screen_height));

            // Simulate moving cursor using keyboard (arrow keys)
            keybd_event(VK_RIGHT, 0, 0, 0);
            keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

int main() {
    EyeTracker eyeTracker;
    eyeTracker.startTracking();

    try {
        while (true) {
            auto cursorPosition = eyeTracker.getCursorPosition();
            std::cout << "Cursor position: (" << cursorPosition.first << ", " << cursorPosition.second << ")\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (...) {
        eyeTracker.stopTracking();
    }

    return 0;
}
