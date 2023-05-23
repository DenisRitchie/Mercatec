// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"

namespace winrt::Mercatec::Application::implementation
{
    struct App : AppT<App>
    {
    public:
        App();
        winrt::fire_and_forget OnLaunched(const Microsoft::UI::Xaml::LaunchActivatedEventArgs&);

    private:
        winrt::Microsoft::UI::Xaml::Window m_Window{ nullptr };
    };
} // namespace winrt::Mercatec::Application::implementation
