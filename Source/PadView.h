/*
  ==============================================================================

    PadView.h
    Created: 21 Nov 2021 10:54:07am
    Author:  hans

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SamplerPad.h"
#include "Spacing.h"

//==============================================================================
/*
*/
namespace SimpleSampler
{

  class PadView : public juce::Component
  {
    static constexpr int DEFAULT_NUM_ROWS = 2;
    static constexpr int DEFAULT_NUM_COLS = 2;
    static constexpr int DEFAULT_NUM_PADS = 6;

  public:
    PadView();
    /**
     * @brief Construct a new Pad View object
     * 
     * @param grid initialize with a grid rather than a default grid initilization
     */
    // PadView(juce::Grid grid);
    ~PadView() override;

    void paint(juce::Graphics &) override;
    void resized() override;

  private:
    juce::Grid padGrid;

    struct PadGridProperties
    {

      int numRows{2};
      int numCols{3};
      int numPads{6};
      // TODO: make this gap dynamic
      juce::Grid::Px rowGap{juce::Grid::Px{SimpleSampler::Spacing::space[3]}};
      juce::Grid::Px colGap{juce::Grid::Px{SimpleSampler::Spacing::space[3]}};

      juce::OwnedArray<SamplerPad> samplerPads;
      void addSamplerPad(juce::Colour color, const std::string& text);
      // void removeSamplerPad();
    };

    PadGridProperties padGridProps;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PadView)
  };
}
