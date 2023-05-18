// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
# include "MainWindow.g.cpp"
#endif

#include "MainPage.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::Foundation;

#include <Mercatec.Helpers.Application.hpp>

using namespace ::Mercatec::Helpers::Applications;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mercatec::Application::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        SetUpComponent();
    }

    void MainWindow::SetUpComponent() noexcept
    {
        Title(ApplicationName());
        FrameContent().Navigate(xaml_typename<Mercatec::Application::MainPage>());
    }

    Microsoft::UI::WindowId MainWindow::WindowId() const noexcept
    {
        auto window_native{ try_as<IWindowNative>() };
        winrt::check_bool(window_native);

        HWND hwnd{ nullptr };
        window_native->get_WindowHandle(&hwnd);

        return GetWindowIdFromWindow(hwnd);
    }
} // namespace winrt::Mercatec::Application::implementation
