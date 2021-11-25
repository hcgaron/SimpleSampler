/*
  ==============================================================================

    SamplerPad.h
    Created: 21 Nov 2021 10:48:49am
    Author:  hans

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SamplerPad  : public juce::Component
{
public:
    SamplerPad();
    SamplerPad(juce::Colour padColor, const std::string& text);
    ~SamplerPad() override;

    void paint (juce::Graphics& g) override;
    void resized() override;


private:
    void mouseEnter(const juce::MouseEvent& event) override;
    void mouseExit(const juce::MouseEvent& event) override;
    juce::Colour padColor;
    std::string padText;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplerPad)
};
