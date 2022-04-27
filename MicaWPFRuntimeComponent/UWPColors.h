#pragma once

#include "UWPColors.g.h"

namespace winrt::MicaWPFRuntimeComponent::implementation
{
    struct UWPColors : UWPColorsT<UWPColors>
    {
        UWPColors() = default;

        Windows::Foundation::Collections::IVectorView<hstring> GetSystemColors();
        std::wstring CreateColorStrings(winrt::Windows::UI::Color color, char attributeName[]);
        std::wstring s2ws(const std::string& str);
    };
}

namespace winrt::MicaWPFRuntimeComponent::factory_implementation
{
    struct UWPColors : UWPColorsT<UWPColors, implementation::UWPColors>
    {
    };
}
