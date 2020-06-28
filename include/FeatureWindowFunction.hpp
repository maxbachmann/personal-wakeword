#pragma once

#include <vector>

enum WindowType {
    HanningWindow,
    HammingWindow,
    PoveyWindow,
    RectangularWindow
};

namespace FeatureWindowFunction
{
    std::vector<float> createWindow(std::size_t frame_length, WindowType windowType);
};
