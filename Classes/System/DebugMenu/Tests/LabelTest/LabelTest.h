/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef _ATLAS_TEST_H_
#define _ATLAS_TEST_H_

#include "BaseTest.h"

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif

DEFINE_TEST_SUITE(LabelTests);

class AtlasDemo : public TestCase
{
public:
};


class Atlas1 : public AtlasDemo
{
    cocos2d::TextureAtlas*        _textureAtlas;
public:
    CREATE_FUNC(Atlas1);

    Atlas1();
    ~Atlas1();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
protected:
    void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
protected:
    cocos2d::CustomCommand _customCommand;
};

class LabelAtlasTest : public AtlasDemo
{
    float        _time;
public:
    CREATE_FUNC(LabelAtlasTest);

    LabelAtlasTest();

    virtual void step(float dt);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelAtlasColorTest : public AtlasDemo
{
    float        _time;
public:
    CREATE_FUNC(LabelAtlasColorTest);

    LabelAtlasColorTest();
    virtual void step(float dt);
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void actionFinishCallback();
};

class LabelTTFAlignment : public AtlasDemo
{
public:
    CREATE_FUNC(LabelTTFAlignment);

    LabelTTFAlignment();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};


class Atlas3 : public AtlasDemo
{
    float        _time;
public:
    CREATE_FUNC(Atlas3);

    Atlas3();

    virtual void step(float dt);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class Atlas4 : public AtlasDemo
{
    float        _time;
public:
    CREATE_FUNC(Atlas4);

    Atlas4();
    virtual void step(float dt);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class Atlas5 : public AtlasDemo
{
public:
    CREATE_FUNC(Atlas5);

    Atlas5();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};


class Atlas6 : public AtlasDemo
{
public:
    CREATE_FUNC(Atlas6);

    Atlas6();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class AtlasBitmapColor : public AtlasDemo
{
public:
    CREATE_FUNC(AtlasBitmapColor);

    AtlasBitmapColor();
    virtual std::string title() const override;

    virtual std::string subtitle() const override;
};

class AtlasFastBitmap : public AtlasDemo
{
public:
    CREATE_FUNC(AtlasFastBitmap);

    AtlasFastBitmap();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class BitmapFontMultiLine : public AtlasDemo
{
public:
    CREATE_FUNC(BitmapFontMultiLine);

    BitmapFontMultiLine();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelsEmpty : public AtlasDemo
{
public:
    CREATE_FUNC(LabelsEmpty);

    LabelsEmpty();
    void updateStrings(float dt);
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

private:
    bool setEmpty;
};

class LabelBMFontHD : public AtlasDemo
{
public:
    CREATE_FUNC(LabelBMFontHD);

    LabelBMFontHD();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelAtlasHD : public AtlasDemo
{
public:
    CREATE_FUNC(LabelAtlasHD);

    LabelAtlasHD();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelGlyphDesigner : public AtlasDemo
{
public:
    CREATE_FUNC(LabelGlyphDesigner);

    LabelGlyphDesigner();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelTTFTest : public AtlasDemo
{
public:
    CREATE_FUNC(LabelTTFTest);

    LabelTTFTest();
    virtual ~LabelTTFTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
private:
    void  setAlignmentLeft(cocos2d::Ref* sender);
    void  setAlignmentCenter(cocos2d::Ref* sender);
    void  setAlignmentRight(cocos2d::Ref* sender);
    void  setAlignmentTop(cocos2d::Ref* sender);
    void  setAlignmentMiddle(cocos2d::Ref* sender);
    void  setAlignmentBottom(cocos2d::Ref* sender);
    void  updateAlignment();
    const char* getCurrentAlignment();
private:
    cocos2d::TextHAlignment _horizAlign;
    cocos2d::LabelTTF* _label;
    cocos2d::TextVAlignment _vertAlign;
};

class LabelTTFMultiline : public AtlasDemo
{
public:
    CREATE_FUNC(LabelTTFMultiline);

    LabelTTFMultiline();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelTTFChinese : public AtlasDemo
{
public:
    CREATE_FUNC(LabelTTFChinese);

    LabelTTFChinese();
    virtual std::string title() const override;
};

class LabelBMFontChinese : public AtlasDemo
{
public:
    CREATE_FUNC(LabelBMFontChinese);

    LabelBMFontChinese();
    virtual std::string title() const override;
};

class BitmapFontMultiLineAlignment : public AtlasDemo
{
public:
    CREATE_FUNC(BitmapFontMultiLineAlignment);

    BitmapFontMultiLineAlignment();
    ~BitmapFontMultiLineAlignment();
    void snapArrowsToEdge();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void stringChanged(cocos2d::Ref* sender);
    void alignmentChanged(cocos2d::Ref* sender);
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

public:
    cocos2d::LabelBMFont* _labelShouldRetain;
    cocos2d::Sprite* _arrowsBarShouldRetain;
    cocos2d::Sprite* _arrowsShouldRetain;
    cocos2d::MenuItemFont *_lastSentenceItem, *_lastAlignmentItem;
    bool _drag;
};

class LabelTTFOpacityTest : public AtlasDemo
{
public:
    CREATE_FUNC(LabelTTFOpacityTest);

    LabelTTFOpacityTest();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class BMFontOneAtlas : public AtlasDemo
{
public:
    CREATE_FUNC(BMFontOneAtlas);

    BMFontOneAtlas();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class BMFontUnicode : public AtlasDemo
{
public:
    CREATE_FUNC(BMFontUnicode);

    BMFontUnicode();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class BMFontInit : public AtlasDemo
{
public:
    CREATE_FUNC(BMFontInit);

    BMFontInit();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class TTFFontInit : public AtlasDemo
{
public:
    CREATE_FUNC(TTFFontInit);

    TTFFontInit();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class TTFFontShadowAndStroke : public AtlasDemo
{
public:
    CREATE_FUNC(TTFFontShadowAndStroke);

    TTFFontShadowAndStroke();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelBMFontBounds : public AtlasDemo
{
public:
    CREATE_FUNC(LabelBMFontBounds);

    LabelBMFontBounds();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class NewLabelTTFUnicode : public AtlasDemo
{
public:
    CREATE_FUNC(NewLabelTTFUnicode);

    NewLabelTTFUnicode();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class NewLabelBMFontTest : public AtlasDemo
{
public:
    CREATE_FUNC(NewLabelBMFontTest);

    NewLabelBMFontTest();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

private:
};

class NewLabelFontDefTest : public AtlasDemo
{
public:
    CREATE_FUNC(NewLabelFontDefTest);

    NewLabelFontDefTest();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

private:
};

class LabelBMFontCrashTest : public AtlasDemo
{
public:
    CREATE_FUNC(LabelBMFontCrashTest);

    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class LabelBMFontBinaryFormat : public AtlasDemo
{
public:
    CREATE_FUNC(LabelBMFontBinaryFormat);

    LabelBMFontBinaryFormat();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif

// we don't support linebreak mode

#endif
