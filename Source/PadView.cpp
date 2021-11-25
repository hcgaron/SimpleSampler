/*
  ==============================================================================

    PadView.cpp
    Created: 21 Nov 2021 10:54:07am
    Author:  hans

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PadView.h"
#include "ColorPalette.h"

//==============================================================================
SimpleSampler::PadView::PadView()
{
  for (int i = 0; i < DEFAULT_NUM_PADS; ++i)
  {
    padGridProps.addSamplerPad(SimpleSampler::Colors::secondary, std::to_string(i));
    addAndMakeVisible(padGridProps.samplerPads[i]);
  }

  // Initialize with default rows and columns
  using Track = juce::Grid::TrackInfo;
  using Fr = juce::Grid::Fr;

  for (int track = 0; track < padGridProps.numRows; ++track)
  {
    padGrid.templateRows.add(Track(Fr(1)));
  }

  for (int track = 0; track < padGridProps.numCols; ++track)
  {
    padGrid.templateColumns.add(Track(Fr(1)));
  }
  padGrid.items.addArray(padGridProps.samplerPads);

  padGrid.rowGap = padGridProps.rowGap;
  padGrid.columnGap = padGridProps.colGap;
  padGrid.autoFlow = juce::Grid::AutoFlow::row;
}

// SimpleSampler::PadView::PadView(juce::Grid grid) : padGrid{grid} {};

SimpleSampler::PadView::~PadView()
{
}

void SimpleSampler::PadView::paint(juce::Graphics &g)
{
  /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

  g.fillAll(juce::Colours::darkgrey); // clear the background

  g.setColour(juce::Colours::grey);
  g.drawRect(getLocalBounds(), 1); // draw an outline around the component

  g.setColour(juce::Colours::white);
  g.setFont(14.0f);
}

void SimpleSampler::PadView::resized()
{
  padGrid.performLayout(getLocalBounds());
}

void SimpleSampler::PadView::PadGridProperties::addSamplerPad(juce::Colour color, const std::string &text)
{
  samplerPads.add(new SamplerPad(color, text));
}
