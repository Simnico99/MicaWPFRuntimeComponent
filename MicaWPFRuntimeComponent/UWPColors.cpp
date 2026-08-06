#include "pch.h"
#include "UWPColors.h"
#include "UWPColors.g.cpp"

#include <string>
#include <string_view>

namespace winrt::MicaWPFRuntimeComponent::implementation
{
    Windows::Foundation::Collections::IVectorView<hstring>
        UWPColors::GetSystemColors()
    {
        const auto uiSettings =
            Windows::UI::ViewManagement::UISettings();

        auto colors = winrt::single_threaded_vector<hstring>();

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::Accent),
                L"SystemAccentColor"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentLight1),
                L"SystemAccentColorLight1"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentLight2),
                L"SystemAccentColorLight2"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentLight3),
                L"SystemAccentColorLight3"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentDark1),
                L"SystemAccentColorDark1"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentDark2),
                L"SystemAccentColorDark2"));

        colors.Append(
            CreateColorString(
                uiSettings.GetColorValue(
                    Windows::UI::ViewManagement::UIColorType::AccentDark3),
                L"SystemAccentColorDark3"));

        return colors.GetView();
    }

    std::wstring UWPColors::CreateColorString(
        const Windows::UI::Color color,
        const std::wstring_view attributeName)
    {
        auto result = std::wstring();

        // Four values of up to three digits, four commas and the name.
        result.reserve(attributeName.size() + 16);

        result.append(std::to_wstring(color.A));
        result.push_back(L',');

        result.append(std::to_wstring(color.R));
        result.push_back(L',');

        result.append(std::to_wstring(color.G));
        result.push_back(L',');

        result.append(std::to_wstring(color.B));
        result.push_back(L',');

        result.append(attributeName);

        return result;
    }
}
