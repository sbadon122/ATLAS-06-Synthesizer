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
        auto sliderRadius = (float) getSliderThumbRadius (slider) * 0.5f;
        
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
        g.setColour(Colours::black.withMultipliedAlpha(0.8f));
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

struct RotaryLookAndFeel    : public LookAndFeel_V4
{
    void drawRoundThumb (Graphics& g, float x, float y, float diameter, Colour colour, float outlineThickness)
    {
        auto halfThickness = outlineThickness * 0.5f;
        
        Path p;
        p.addEllipse (x + halfThickness,
                      y + halfThickness,
                      diameter - outlineThickness,
                      diameter - outlineThickness);
        
        DropShadow (Colours::black, 1, {}).drawForPath (g, p);
        
        g.setColour (colour);
        g.fillPath (p);
        
        g.setColour (colour.brighter());
        g.strokePath (p, PathStrokeType (outlineThickness));
    }
    
    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
        .withMultipliedAlpha      (button.isEnabled() ? 0.9f : 0.5f);
        
        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);
        
        auto flatOnLeft   = button.isConnectedOnLeft();
        auto flatOnRight  = button.isConnectedOnRight();
        auto flatOnTop    = button.isConnectedOnTop();
        auto flatOnBottom = button.isConnectedOnBottom();
        
        auto width  = button.getWidth()  - 1.0f;
        auto height = button.getHeight() - 1.0f;
        
        if (width > 0 && height > 0)
        {
            auto cornerSize = jmin (15.0f, jmin (width, height) * 0.45f);
            auto lineThickness = cornerSize    * 0.1f;
            auto halfThickness = lineThickness * 0.5f;
            
            Path outline;
            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
                                         cornerSize, cornerSize,
                                         ! (flatOnLeft  || flatOnTop),
                                         ! (flatOnRight || flatOnTop),
                                         ! (flatOnLeft  || flatOnBottom),
                                         ! (flatOnRight || flatOnBottom));
            
            auto outlineColour = button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                                    : TextButton::textColourOffId);
            
            g.setColour (baseColour);
            g.fillPath (outline);
            
            if (! button.getToggleState())
            {
                g.setColour (outlineColour);
                g.strokePath (outline, PathStrokeType (lineThickness));
            }
        }
    }
    
    void drawTickBox (Graphics& g, Component& component,
                      float x, float y, float w, float h,
                      bool ticked,
                      bool isEnabled,
                      bool isMouseOverButton,
                      bool isButtonDown) override
    {
        auto boxSize = w * 0.7f;
        
        auto isDownOrDragging = component.isEnabled() && (component.isMouseOverOrDragging() || component.isMouseButtonDown());
        
        auto colour = component.findColour (TextButton::buttonColourId)
        .withMultipliedSaturation ((component.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
        .withMultipliedAlpha (component.isEnabled() ? 1.0f : 0.7f);
        
        drawRoundThumb (g, x, y + (h - boxSize) * 0.5f, boxSize, colour,
                        isEnabled ? ((isButtonDown || isMouseOverButton) ? 1.1f : 0.5f) : 0.3f);
        
        if (ticked)
        {
            g.setColour (isEnabled ? findColour (TextButton::buttonOnColourId) : Colours::grey);
            
            auto scale = 9.0f;
            auto trans = AffineTransform::scale (w / scale, h / scale).translated (x - 2.5f, y + 1.0f);
            
            g.fillPath (LookAndFeel_V4::getTickShape (6.0f), trans);
        }
    }
    
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        auto sliderRadius = (float) (getSliderThumbRadius (slider) - 2);
        
        auto isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        
        auto knobColour = slider.findColour (Slider::thumbColourId)
        .withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
        .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f);
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;
            
            if (style == Slider::LinearVertical)
            {
                kx = x + width * 0.5f;
                ky = sliderPos;
            }
            else
            {
                kx = sliderPos;
                ky = y + height * 0.5f;
            }
            
            auto outlineThickness = slider.isEnabled() ? 0.8f : 0.3f;
            
            drawRoundThumb (g,
                            kx - sliderRadius,
                            ky - sliderRadius,
                            sliderRadius * 2.0f,
                            knobColour, outlineThickness);
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
        g.fillAll (slider.findColour (Slider::backgroundColourId));
        
        if (style == Slider::LinearBar || style == Slider::LinearBarVertical)
        {
            Path p;
            
            if (style == Slider::LinearBarVertical)
                p.addRectangle ((float) x, sliderPos, (float) width, 1.0f + height - sliderPos);
            else
                p.addRectangle ((float) x, (float) y, sliderPos - x, (float) height);
            
            auto baseColour = slider.findColour (Slider::rotarySliderFillColourId)
            .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
            .withMultipliedAlpha (0.8f);
            
            g.setColour (baseColour);
            g.fillPath (p);
            
            auto lineThickness = jmin (15.0f, jmin (width, height) * 0.45f) * 0.1f;
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
        auto sliderRadius = getSliderThumbRadius (slider) - 5.0f;
        Path on, off;
        
        if (slider.isHorizontal())
        {
            auto iy = y + height * 0.5f - sliderRadius * 0.5f;
            Rectangle<float> r (x - sliderRadius * 0.5f, iy, width + sliderRadius, sliderRadius);
            auto onW = r.getWidth() * ((float) slider.valueToProportionOfLength (slider.getValue()));
            
            on.addRectangle (r.removeFromLeft (onW));
            off.addRectangle (r);
        }
        else
        {
            auto ix = x + width * 0.5f - sliderRadius * 0.5f;
            Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
            auto onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));
            
            on.addRectangle (r.removeFromBottom (onH));
            off.addRectangle (r);
        }
        
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId));
        g.fillPath (on);
        
        g.setColour (slider.findColour (Slider::trackColourId));
        g.fillPath (off);
    }
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
    {
        auto radius = jmin (width / 2, height / 2)-6.5f;
        auto centreX = x + width  * 0.5f;
        auto centreY = y + height * 0.5f;
        auto rx = centreX - radius;
        auto ry = centreY - radius;
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        g.setColour( Colours::black.withMultipliedAlpha(0.8f));
        g.fillEllipse(x, y, width, height);

        
            g.setColour (Colours::whitesmoke);
            for (int i = 0; i<= 360; i += 36){
                auto dx1 = (-12)*std::cos(i) - std::sin(i);
                auto dy1 = std::cos(i) + (-12)*std::sin(i);
                auto dx2 = (-15)*std::cos(i) - std::sin(i);
                auto dy2 = std::cos(i) + (-15)*std::sin(i);
                Line<float> line (Point<float> (dx1+centreX, dy1+centreY),
                                  Point<float> (dx2+centreX, dy2+centreY));
                g.drawLine(line, 2.0f);
            }
        
            Path p;
            Colour black(0xff2b2e33);
            float modifer = .45 * sliderPos;
            auto grey = Colour(0xff444951);
            g.setGradientFill({Colours::black, (float)width/2, (float)height/(2), grey,(float)width*modifer, (float)height, true});
            p.addEllipse(x+2, y+2, width-3.5, height-3.5);
            g.fillPath(p);
        
       
        
        g.setColour (Colours::whitesmoke);
            auto dx = (rx-centreX)*std::cos(angle) - (ry-centreY)*std::sin(angle);
            auto dy = (ry-centreY)*std::cos(angle) + (rx-centreX)*std::sin(angle);
            Line<float> line (Point<float> (centreX, centreY),
                              Point<float> (dx+centreX, dy+centreY));
            g.drawLine(line, 2.0f);
        
        
            
       
    }
};
