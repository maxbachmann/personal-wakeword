#include "FeatureWindowFunction.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

std::vector<float> FeatureWindowFunction::createWindow(std::size_t frame_length, WindowType windowType)
{
  std::vector<float> window (frame_length);

  const float constant = 2.0 * M_PI / (frame_length - 1);

  for (std::size_t i = 0; i < frame_length; ++i) {
    const float i_fp = static_cast<float>(i);
  
    switch (windowType)
    {
    case HanningWindow:
      window[i] = 0.5 - 0.5 * std::cos(constant * i_fp);
    case HammingWindow:
      window[i] = 0.54 - 0.46 * std::cos(constant * i_fp);
    case PoveyWindow: // similar to hamming but goes to zero at the edges
      window[i] = std::pow(0.5 - 0.5 * std::cos(constant * i_fp), 0.85);
    case RectangularWindow:
      window[i] = 1.0;
    }
  }

  return window;
}
