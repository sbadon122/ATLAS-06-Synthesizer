/*
  ==============================================================================

    SliderLookAndFeel.h
    Created: 29 Nov 2018 11:36:45am
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

struct SliderLookAndFeel    : public LookAndFeel_V4
{
    
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        auto sliderRadius = (float) getSliderThumbRadius (slider);
        
        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        
        auto knobColour = slider.findColour (Slider::rotarySliderFillColourId)
        .withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
        .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f);
        
        g.setColour (knobColour);
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
                float kx, ky;
                kx = x + width * 0.5f;
                ky = sliderPos;
                g.fillRect (Rectangle<float> (kx - sliderRadius, ky - 2.5f, sliderRadius * 2.0f, 10.0f));
                g.setColour(Colours::whitesmoke);
                g.fillRect (Rectangle<float> (kx - sliderRadius * 0.5f, ky + 0.5f, sliderRadius, 2.0f));
        }
        else
        {
            // Just call the base class for the demo
            LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
        //g.fillAll (slider.findColour (Slider::backgroundColourId));
        
        if (style == Slider::LinearBar || style == Slider::LinearBarVertical)
        {
            Path p;
            
            p.addRectangle ((float) x, sliderPos, (float) width * 0.5f, 1.0f + height - sliderPos);
            
            auto baseColour = slider.findColour (Slider::rotarySliderFillColourId)
            .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
            .withMultipliedAlpha (0.8f);
            
            g.setColour (baseColour);
            g.fillPath (p);
            
            auto lineThickness = 5.0f;
            g.drawRect (slider.getLocalBounds().toFloat(), lineThickness);
        }
        else
        {
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb      (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
        auto sliderRadius = getSliderThumbRadius (slider) - 7.5f;
        Path on, off;
        auto ix = x + width * 0.5f - sliderRadius * 0.5f;
        Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
        auto onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));
            
        on.addRectangle (r.removeFromBottom (onH));
        off.addRectangle (r);
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId));
        g.fillPath (on);
        
        g.setColour (slider.findColour (Slider::trackColourId));
        g.fillPath (off);
        
        float spacing = height / 10.0f;
        g.setColour(Colours::whitesmoke);
        for(int i = 0; i<11; i++){
            float thickness = i % 5  ? 0.5f : 2.0f;
            g.fillRect (Rectangle<float> (x, y + spacing*i, width/2-sliderRadius, thickness));
            g.fillRect (Rectangle<float> (x + width/2+sliderRadius, y + spacing*i, width/2-sliderRadius, thickness));
        }
    }
    
};

struct SliderToggleLookAndFeel    : public LookAndFeel_V4
{
    
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        auto sliderRadius = (float) getSliderThumbRadius (slider) * 0.75f;
        
        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        
        auto knobColour = slider.findColour (Slider::rotarySliderFillColourId)
        .withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
        .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f);
        
        g.setColour (knobColour);
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;
            kx = x + width * 0.5f;
            ky = sliderPos;
            g.fillRect (Rectangle<float> (kx - sliderRadius, ky - 2.5f, sliderRadius * 2.0f, 10.0f));
            g.setColour(Colours::whitesmoke);
            g.fillRect (Rectangle<float> (kx - sliderRadius, ky + 1.5f, sliderRadius*2.0f, 2.0f));
        }
        else
        {
            // Just call the base class for the demo
            LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
        // g.fillAll (slider.findColour (Slider::backgroundColourId));
        drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        drawLinearSliderThumb      (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
    
    }
    
    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
        auto sliderRadius = getSliderThumbRadius (slider) - 1.0f;
        Path on, off;
        auto ix = x + width * 0.5f - sliderRadius * 0.5f;
        Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
        auto onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));
        
        on.addRectangle (r.removeFromBottom (onH));
        off.addRectangle (r);
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId));
        g.fillPath (on);
        
        g.setColour (slider.findColour (Slider::trackColourId));
        g.fillPath (off);
        
    }
    
    
};

struct PitchBendLookAndFeel    : public LookAndFeel_V4
{
    
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        auto sliderRadius = (float) getSliderThumbRadius (slider);
        auto grey = Colour(0xff2b2e33);
        auto knobColour = slider.findColour (Slider::rotarySliderFillColourId)
        .withMultipliedSaturation ((slider.hasKeyboardFocus (false)) ? 1.3f : 0.9f)
        .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f);
        
       
        g.setColour (Colour(grey).withMultipliedSaturation(0.8f));
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;
            kx = sliderPos;
            ky = x + height * 0.5f;
            g.fillRect (Rectangle<float> (kx -5.0f, ky -  sliderRadius+0.2f, 10.0f, sliderRadius -0.2f));
            
            auto white = Colours::grey.withMultipliedAlpha(0.5f);
            g.setColour(white);
            auto calculatedOffset = (sliderPos-12.0f)/66.0f * 8.0f;
            g.fillRect (Rectangle<float> (kx-5.0f+ calculatedOffset, ky -  sliderRadius+0.2f, 2.0f, sliderRadius -0.2f));
        }
    
    }
    
    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
    
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb      (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
    }
    
    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float sliderPos,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
        
         auto percent = (sliderPos-12.0f)/66.0f;
        Colour black(0xff2b2e33);
        
        g.setColour (black);
        auto grey = Colour(0xff444951);
        auto sliderRadius = getSliderThumbRadius (slider) - 1.0f;
        Path on, off;
        auto iy = x + height * 0.5f - sliderRadius;
        Rectangle<float> r (x-sliderRadius*0.5f, iy ,width+ sliderRadius ,  sliderRadius);
        g.setColour(Colours::black.withMultipliedAlpha(0.35f));
        Rectangle<float> backgroundR (x-8.0f, iy - 2.0f ,width+ sliderRadius + 4.0f ,  sliderRadius+4.0f);
        g.fillRect(backgroundR);
        auto onH = r.getWidth() * ((float) slider.valueToProportionOfLength (slider.getValue()));
        g.setGradientFill({black, r.getX(),r.getY(), grey,(r.getX()+r.getWidth()/2)*percent, r.getY()+r.getHeight(), true});
        on.addRectangle (r.removeFromLeft (onH));
        off.addRectangle (r);
       
        g.fillPath (on);
       g.setGradientFill({grey, r.getX()+r.getWidth()/2,r.getY(), black,(r.getX()+r.getWidth())*percent, r.getY()+r.getHeight(), true});
        g.fillPath (off);
        
    
    }
//
    
};

struct SliderPitchBendLookAndFeel    : public LookAndFeel_V4
{
    
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        auto sliderRadius = (float) getSliderThumbRadius (slider)*3/4;
        
        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        
        auto knobColour = slider.findColour (Slider::rotarySliderFillColourId)
        .withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
        .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f);
        
        g.setColour (knobColour);
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;
            kx = x + width * 0.5f;
            ky = sliderPos;
            g.fillRect (Rectangle<float> (kx - sliderRadius, ky - 2.5f, sliderRadius * 2.0f, 10.0f));
            g.setColour(Colours::whitesmoke);
            g.fillRect (Rectangle<float> (kx - sliderRadius * 0.5f, ky + 0.75f, sliderRadius, 1.0f));
        }
        else
        {
            // Just call the base class for the demo
            LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
        //g.fillAll (slider.findColour (Slider::backgroundColourId));
        
        if (style == Slider::LinearBar || style == Slider::LinearBarVertical)
        {
            Path p;
            
            p.addRectangle ((float) x, sliderPos, (float) width * 0.5f, 1.0f + height - sliderPos);
            
            auto baseColour = slider.findColour (Slider::rotarySliderFillColourId)
            .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
            .withMultipliedAlpha (0.8f);
            
            g.setColour (baseColour);
            g.fillPath (p);
            
            auto lineThickness = 5.0f;
            g.drawRect (slider.getLocalBounds().toFloat(), lineThickness);
        }
        else
        {
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb      (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
        auto sliderRadius = getSliderThumbRadius (slider) - 7.5f;
        Path on, off;
        auto ix = x + width * 0.5f - sliderRadius * 0.5f;
        Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
        auto onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));
        
        on.addRectangle (r.removeFromBottom (onH));
        off.addRectangle (r);
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId));
        g.fillPath (on);
        
        g.setColour (slider.findColour (Slider::trackColourId));
        g.fillPath (off);
        
        float spacing = height / 10.0f;
        g.setColour(Colours::whitesmoke);
        for(int i = 0; i<11; i++){
            float thickness = i % 5  ? 0.25f : 1.0f;
            g.fillRect (Rectangle<float> (x, y + spacing*i, width/2-sliderRadius, thickness));
            g.fillRect (Rectangle<float> (x + width/2+sliderRadius, y + spacing*i, width/2-sliderRadius, thickness));
        }
    }
    
};
