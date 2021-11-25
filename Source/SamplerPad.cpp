/*
  ==============================================================================

    SamplerPad.cpp
    Created: 21 Nov 2021 10:48:49am
    Author:  hans

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SamplerPad.h"
#include "ColorPalette.h"

//==============================================================================
SamplerPad::SamplerPad()
{
  // In your constructor, you should add any child components, and
  // initialise any special settings that your component needs.

  // TODO: make this size dynamic
  setSize(100, 100);
}

SamplerPad::SamplerPad(juce::Colour padColor, const std::string& text) : padColor{padColor}, padText{text} {
  // TODO: make this size dynamic
  setSize(100, 100);
};

SamplerPad::~SamplerPad()
{
}

void SamplerPad::paint(juce::Graphics &g)
{
  /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

  g.fillAll(padColor);

  g.setColour(SimpleSampler::Colors::primary);
  // TODO: make this size dynamic
  g.drawText(juce::String{padText}, getLocalBounds().withSizeKeepingCentre(100, 100), juce::Justification::centred, false);
}

void SamplerPad::resized()
{
  // This method is where you should set the bounds of any child
  // components that your component contains..
}

void SamplerPad::mouseEnter(const juce::MouseEvent& e)
{
  padColor = SimpleSampler::Colors::accentLight;
  repaint();
}

void SamplerPad::mouseExit(const juce::MouseEvent& e)
{
    padColor = SimpleSampler::Colors::secondary;
  repaint();
}