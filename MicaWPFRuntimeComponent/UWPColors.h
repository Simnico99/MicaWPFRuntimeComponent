#pragma once

#include "UWPColors.g.h"

#include <string>
#include <string_view>

namespace winrt::MicaWPFRuntimeComponent::implementation
{
    struct UWPColors : UWPColorsT<UWPColors>
    {
        UWPColors() = default;

        [[nodiscard]]
        Windows::Foundation::Collections::IVectorView<hstring> GetSystemColors();

    private:
        [[nodiscard]]
        static std::wstring CreateColorString(
            Windows::UI::Color color,
            std::wstring_view attributeName);
    };
}

namespace winrt::MicaWPFRuntimeComponent::factory_implementation
{
    struct UWPColors : UWPColorsT<UWPColors, implementation::UWPColors>
    {
    };
}
