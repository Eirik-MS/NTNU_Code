#pragma once

#include <string>
#include "internal/nuklear_configured.h"
#include "Point.h"
#include "internal/windows_main_fix.h"

namespace TDT4102 {
    namespace internal {
        [[maybe_unused]] static unsigned int nextWidgetID = 0;
    }

    class AnimationWindow;

    class Widget {
    friend class TDT4102::AnimationWindow;
    private:
        void (*callbackFunction)() = nullptr;
        TDT4102::Point position;
        unsigned int width = 0;
        unsigned int height = 0;
        // Each window in Nuklear needs a unique name, so we generate a unique one for each widget
        std::string uniqueWidgetName;

    protected:
        void fire();
        virtual void update(nk_context* context) = 0;
        explicit Widget(TDT4102::Point position, unsigned int width, unsigned int height);
    public:
        void setCallback(void (*callbackFunction)());
        virtual ~Widget() {}
    };
}