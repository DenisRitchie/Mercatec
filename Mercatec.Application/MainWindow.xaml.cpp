// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
# include "MainWindow.g.cpp"
#endif

#include <winrt/Mercatec.Helpers.h>
#include <winrt/Mercatec.Helpers.ViewModels.h>

#include <Mercatec.Helpers.Application.hpp>

using namespace winrt;
using namespace winrt::Microsoft::UI::Xaml;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Security::Credentials;
using namespace winrt::Mercatec::Helpers;
using namespace winrt::Mercatec::Helpers::ViewModels;

using namespace ::Mercatec::Helpers::Applications;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mercatec::Application::implementation
{
    MainWindow::MainWindow()
      : m_Monitor{ make_self<::Mercatec::WinUIEx::Messaging::WindowMessageMonitor>(*this) }
      , m_Manager{ Mercatec::WinUIEx::WindowManager::Get(*this) }
    {
        InitializeComponent();
        SetUpComponent();
    }

    void MainWindow::SetUpComponent() noexcept
    {
        Title(ApplicationName());
        WindowExtensions::CenterOnScreen(*this);
        TaskBarIcon(WinUIEx::Icon::FromFile(IconPath()));
        FrameContent().Navigate(xaml_typename<Mercatec::Application::MainPage>());
    }
} // namespace winrt::Mercatec::Application::implementation
