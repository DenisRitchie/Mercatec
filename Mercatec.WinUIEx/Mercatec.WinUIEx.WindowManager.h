﻿#pragma once

#include "WindowManager.g.h"
#include "Mercatec.WinUIEx.Messaging.WindowMessageMonitor.hpp"

#include <winrt/Mercatec.WinUIEx.h>
#include <winrt/Mercatec.WinUIEx.Messaging.h>
#include <winrt/Microsoft.UI.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Composition.SystemBackdrops.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Graphics.h>
#include <winrt/Windows.Storage.h>
#include <memory>

namespace winrt::Mercatec::WinUIEx::implementation
{
    /// <summary>
    ///     Manages Window sizes, persists location and size across application sessions, simplifies backdrop configurations etc.
    ///     Use this class instead of <see cref="WindowEx"/> if you just want to extend an existing window with functionality, without having to change the baseclass.
    /// </summary>
    struct WindowManager : WindowManagerT<WindowManager>
    {
    private:
        struct WindowManagerImpl;
        std::unique_ptr<WindowManagerImpl> Impl;

        static bool TryGetWindowManager(const Microsoft::UI::Xaml::Window& Window, WinUIEx::WindowManager& Manager);

    public:
        /// <summary>
        ///     Gets (or creates) a window manager for the specific window.
        /// </summary>
        /// <param name="Window"></param>
        /// <returns></returns>
        static WinUIEx::WindowManager Get(const Microsoft::UI::Xaml::Window& Window);

        /// <summary>
        ///     Initializes a new instance of the <see cref="WindowManager"/> class.
        /// </summary>
        /// <param name="window"></param>
        WindowManager(const Microsoft::UI::Xaml::Window& Window);
        WindowManager(const WindowManager&)            = delete;
        WindowManager(WindowManager&&)                 = default;
        WindowManager& operator=(const WindowManager&) = delete;
        WindowManager& operator=(WindowManager&&)      = default;
        ~WindowManager();

    private:
        WindowManager(const Microsoft::UI::Xaml::Window& Window, const com_ptr<::Mercatec::WinUIEx::Messaging::WindowMessageMonitor>& Monitor);
        void Window_VisibilityChanged(const IInspectable& Sender, const Microsoft::UI::Xaml::WindowVisibilityChangedEventArgs& Args);

    public:
        /// <summary>
        ///     Gets a reference to the AppWindow for the app.
        /// </summary>
        Microsoft::UI::Windowing::AppWindow AppWindow() const noexcept;

        /// <summary>
        ///     Gets or sets the width of the window.
        /// </summary>
        /// <value>The window width in device independent pixels.</value>
        /// <seealso cref="MinWidth"/>
        /// <seealso cref="MaxWidth"/>
        double_t Width() const noexcept;
        void     Width(const double_t Width) noexcept;

        /// <summary>
        ///     Gets or sets the height of the window.
        /// </summary>
        /// <value>The window height in device independent pixels.</value>
        /// <seealso cref="MinHeight"/>
        /// <seealso cref="MaxHeight"/>
        double_t Height() const noexcept;
        void     Height(const double_t Height) noexcept;

        /// <summary>
        ///     Gets or sets the minimum width of this window.
        /// </summary>
        /// <value>The minimum window width in device independent pixels.</value>
        /// <remarks>A window is currently set to a minimum of 139 pixels.</remarks>
        /// <seealso cref="MaxWidth"/>
        /// <seealso cref="MinHeight"/>
        double_t MinWidth() const noexcept;
        void     MinWidth(const double_t MinWidth) noexcept;

        /// <summary>
        ///     Gets or sets the minimum height of this window
        /// </summary>
        /// <value>The minimum window height in device independent pixels.</value>
        /// <remarks>A window is currently set to a minimum of 39 pixels.</remarks>
        /// <seealso cref="MaxHeight"/>
        /// <seealso cref="MinWidth"/>
        double_t MinHeight() const noexcept;
        void     MinHeight(const double_t MinHeight) noexcept;

        /// <summary>
        ///     Gets or sets the maximum width of this window
        /// </summary>
        /// <value>The maximum window width in device independent pixels.</value>
        /// <remarks>The default is 0, which means no limit. If the value is less than <see cref="MinWidth"/>, the <c>MinWidth</c> will also be used as the maximum width.</remarks>
        /// <seealso cref="MaxHeight"/>
        /// <seealso cref="MinWidth"/>
        double_t MaxWidth() const noexcept;
        void     MaxWidth(const double_t MaxWidth);

        /// <summary>
        ///     Gets or sets the maximum height of this window
        /// </summary>
        /// <value>The maximum window height in device independent pixels.</value>
        /// <remarks>The default is 0, which means no limit. If the value is less than <see cref="MinHeight"/>, the <c>MinHeight</c> will also be used as the maximum height.</remarks>
        /// <seealso cref="MaxWidth"/>
        /// <seealso cref="MinHeight"/>
        double_t MaxHeight() const noexcept;
        void     MaxHeight(const double_t MaxHeight);

    private:
        void OnWindowMessage(const IInspectable& Sender, const Mercatec::WinUIEx::Messaging::WindowMessageEventArgs& Args);

    public:
        /// <summary>
        ///     Gets or sets the current window state.
        /// </summary>
        /// <remarks>
        /// <para>When the <see cref="WindowState"/> property is changed, <see cref="StateChanged"/> is raised.</para>
        /// <note>
        ///     This property only has affect when using the OverlappedPresenter.
        /// </note>
        /// </remarks>
        /// <value>A <see cref="WindowState"/> that determines whether a window is restored, minimized, or maximized.
        /// The default is <see cref="WindowState.Normal"/> (restored).</value>
        /// <seealso cref="WindowManager.StateChanged"/>
        /// <seealso cref="PresenterKind"/>
        WindowState WindowState() const noexcept;
        void        WindowState(const WinUIEx::WindowState& State) noexcept;

        /// <summary>
        ///     Occurs when the window's <see cref="WindowState"/> property changes.
        /// </summary>
        /// <remarks>
        ///     <note>
        ///         This event only has affect when using the OverlappedPresenter.
        ///     </note>
        /// </remarks>
        /// <seealso cref="WindowManager.WindowState"/>
        /// <seealso cref="PresenterChanged"/>
        winrt::event_token StateChanged(const Windows::Foundation::TypedEventHandler<WinUIEx::WindowManager, Mercatec::WinUIEx::WindowState>& Handler);
        void               StateChanged(const event_token& Token) noexcept;

        /// <summary>
        ///     Event raised when a windows message is received.
        /// </summary>
        winrt::event_token WindowMessageReceived(const Windows::Foundation::TypedEventHandler<WinUIEx::WindowManager, Mercatec::WinUIEx::Messaging::WindowMessageEventArgs>& Handler);
        void               WindowMessageReceived(const event_token& Token) noexcept;

#pragma region Persistence
        /// <remarks>
        ///     The ID must be set before the window activates. The window size and position
        ///     will only be restored if the monitor layout hasn't changed between application settings.
        ///
        ///     The property uses ApplicationData storage, and therefore is currently only functional for
        ///     packaged applications.
        ///
        ///     By default the property uses <see cref="ApplicationData"/> storage, and therefore is currently only functional for
        ///     packaged applications. If you're using an unpackaged application, you must also set the <see cref="PersistenceStorage"/>
        ///     property and manage persisting this across application settings.
        /// </remarks>
        /// <seealso cref="PersistenceStorage"/>
        hstring PersistenceId() const noexcept;
        void    PersistenceId(const std::wstring_view PersistenceId) noexcept;

        /// <summary>
        ///     Gets or sets the persistence storage for maintaining window settings across application settings.
        /// </summary>
        /// <remarks>
        ///     For a packaged application, this will be initialized automatically for you, and saved with the application identity using <see cref="ApplicationData"/>.
        ///     However for an unpackaged application, you will need to set this and serialize the property to/from disk between application sessions.
        ///     The provided dictionary is automatically written to when the window closes, and should be initialized before any window with persistence opens.
        /// </remarks>
        /// <seealso cref="PersistenceId"/>
        static LocalSettings PersistenceStorage() noexcept;
        static void          PersistenceStorage(const LocalSettings& PersistenceStorage) noexcept;

    private:
        static LocalSettings GetPersistenceStorage(const bool CreateIfMissing);

        void LoadPersistence();
        void SavePersistence();
#pragma endregion

        void AppWindow_Changed(const Microsoft::UI::Windowing::AppWindow& Sender, const Microsoft::UI::Windowing::AppWindowChangedEventArgs& Args);

    public:
        /// <summary>
        ///     Gets or sets a value indicating whether the default title bar is visible or not.
        /// </summary>
        bool IsTitleBarVisible() const noexcept;
        void IsTitleBarVisible(const bool IsTitleBarVisible) noexcept;

        /// <summary>
        ///     Gets or sets a value indicating whether the minimize button is visible
        /// </summary>
        bool IsMinimizable() const noexcept;
        void IsMinimizable(const bool IsMinimizable) noexcept;

        /// <summary>
        ///     Gets or sets a value indicating whether the maximimze button is visible
        /// </summary>
        bool IsMaximizable() const noexcept;
        void IsMaximizable(const bool IsMaximizable) noexcept;

        /// <summary>
        ///     Gets or sets a value indicating whether the window can be resized.
        /// </summary>
        bool IsResizable() const noexcept;
        void IsResizable(const bool IsResizable) noexcept;

        /// <summary>
        ///     Gets or sets a value indicating whether this window is always on top.
        /// </summary>
        bool IsAlwaysOnTop() const noexcept;
        void IsAlwaysOnTop(const bool IsAlwaysOnTop) noexcept;

        /// <summary>
        ///     Gets or sets the presenter kind for the current window
        /// </summary>
        /// <seealso cref="AppWindow.Presenter"/>
        /// <seealso cref="PresenterChanged"/>
        Microsoft::UI::Windowing::AppWindowPresenterKind PresenterKind() const noexcept;
        void                                             PresenterKind(const Microsoft::UI::Windowing::AppWindowPresenterKind PresenterKind) noexcept;

        /// <summary>
        ///     Raised if the window position changes.
        /// </summary>
        event_token PositionChanged(const Windows::Foundation::TypedEventHandler<WinUIEx::WindowManager, Windows::Graphics::PointInt32>& Handler);
        void        PositionChanged(const event_token& Token) noexcept;

        /// <summary>
        ///     Raised if the presenter for the window changes.
        /// </summary>
        event_token PresenterChanged(const Windows::Foundation::TypedEventHandler<WinUIEx::WindowManager, Microsoft::UI::Windowing::AppWindowPresenter>& Handler);
        void        PresenterChanged(const event_token& Token) noexcept;

        /// <summary>
        ///     Raised if the Z order of the window changes.
        /// </summary>
        event_token ZOrderChanged(const Windows::Foundation::TypedEventHandler<WinUIEx::WindowManager, ZOrderInfo>& Handler);
        void        ZOrderChanged(const event_token& Token) noexcept;

    public:
        /// <summary>
        ///     Gets or sets the system backdrop for the window.
        ///     Note: Windows 10 doesn't support Acrylic, so will fall back to default backdrop.
        /// </summary>
        /// <seealso cref="MicaSystemBackdrop"/>
        /// <seealso cref="AcrylicSystemBackdrop"/>
        BackdropType BackdropType() const noexcept;
        void         BackdropType(const WinUIEx::BackdropType BackdropType) noexcept;

    private:
        void Window_ThemeChanged(const Microsoft::UI::Xaml::FrameworkElement& Sender, const IInspectable& Args);
        void Window_Activated(const IInspectable& Sender, const Microsoft::UI::Xaml::WindowActivatedEventArgs& Args);
        void Window_Closed(const IInspectable& Sender, const Microsoft::UI::Xaml::WindowEventArgs& Args);

        void SetConfigurationSourceTheme() noexcept;
        bool TrySetMicaBackdrop(const bool UseMicaAlt) noexcept;
        bool TrySetAcrylicBackdrop() noexcept;
    };
} // namespace winrt::Mercatec::WinUIEx::implementation

namespace winrt::Mercatec::WinUIEx::factory_implementation
{
    struct WindowManager : WindowManagerT<WindowManager, implementation::WindowManager>
    {
    };
} // namespace winrt::Mercatec::WinUIEx::factory_implementation
