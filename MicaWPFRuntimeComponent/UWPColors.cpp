#include "pch.h"
#include "UWPColors.h"
#include "UWPColors.g.cpp"
#include <sstream>


namespace winrt::MicaWPFRuntimeComponent::implementation
{
    Windows::Foundation::Collections::IVectorView<hstring> UWPColors::GetSystemColors()
    {
        Windows::Foundation::Collections::IVector<hstring>  vect{ winrt::single_threaded_vector<hstring>() };
        auto uiSettings = Windows::UI::ViewManagement::UISettings();
        auto systemAccentColor = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::Accent);
        auto systemAccentColorLight1 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentLight1);
        auto systemAccentColorLight2 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentLight2);
        auto systemAccentColorLight3 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentLight3);
        auto systemAccentColorDark1 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentDark1);
        auto systemAccentColorDark2 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentDark2);
        auto systemAccentColorDark3 = uiSettings.GetColorValue(Windows::UI::ViewManagement::UIColorType::AccentDark3);

        vect.Append(hstring(CreateColorStrings(systemAccentColor, "SystemAccentColor")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorLight1, "SystemAccentColorLight1")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorLight2, "SystemAccentColorLight2")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorLight3, "SystemAccentColorLight3")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorDark1, "SystemAccentColorDark1")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorDark2, "SystemAccentColorDark2")));
        vect.Append(hstring(CreateColorStrings(systemAccentColorDark3, "SystemAccentColorDark3")));

        return vect.GetView();
    }

    std::wstring MicaWPFRuntimeComponent::implementation::UWPColors::CreateColorStrings(winrt::Windows::UI::Color color, char attributeName[])
    {
        std::wstring string;

        std::stringstream charAStream;
        charAStream << unsigned(color.A);
        auto charAString = charAStream.str();

        std::stringstream charRStream;
        charRStream << unsigned(color.R);
        auto charRString = charRStream.str();

        std::stringstream charGStream;
        charGStream << unsigned(color.G);
        auto charGString = charGStream.str();

        std::stringstream charBStream;
        charBStream << unsigned(color.B);
        auto charBString = charBStream.str();


        string.append(s2ws(charAString));
        string.push_back(',');
        string.append(s2ws(charRString));
        string.push_back(',');
        string.append(s2ws(charGString));
        string.push_back(',');
        string.append(s2ws(charBString));
        string.push_back(',');
        string.append(s2ws(attributeName));

        return string;
    }

    std::wstring MicaWPFRuntimeComponent::implementation::UWPColors::s2ws(const std::string& str)
    {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstrTo(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
        return wstrTo;
    }
}
