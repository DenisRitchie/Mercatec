// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once
#include <Windows.h>
#include <Unknwn.h>
#include <RestrictedErrorInfo.h>
#include <hstring.h>
#include <ppltasks.h>

//! CSIDL
//! https://learn.microsoft.com/en-us/windows/win32/shell/csidl
//!
//! CSIDL (constant special item ID list) values provide a unique system-independent way to identify special folders used
//! frequently by applications, but which may not have the same name or location on any given system.
//!
//! For example, the system folder may be "C:\Windows" on one system and "C:\Winnt" on another.
//! These constants are defined in Shlobj.h.
//!
//! SHGetSpecialFolderPathW function (shlobj_core.h)
//! https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpathw
//!
//! KNOWNFOLDERID
//! https://learn.microsoft.com/en-us/windows/win32/shell/knownfolderid

#include <Shlobj.h>
#include <ShlObj_core.h>
#include <Shlwapi.h>
#include <KnownFolders.h>

#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "Shlwapi.lib")

//!
//! CreateDispatcherQueueController Function
//! https://learn.microsoft.com/en-us/windows/win32/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller
//!
//! DispatcherQueueOptions Structure
//! https://learn.microsoft.com/en-us/windows/win32/api/dispatcherqueue/ns-dispatcherqueue-dispatcherqueueoptions
//!
#include <DispatcherQueue.h>

// Undefine GetCurrentTime macro to prevent
// conflict with Storyboard::GetCurrentTime
#ifdef PUSH_MACRO_GetCurrentTime
# pragma push_macro("GetCurrentTime")
# pragma push_macro("GetEnvironmentVariable")
# pragma push_macro("SetEnvironmentVariable")
#endif

#undef GetCurrentTime
#undef GetEnvironmentVariable
#undef SetEnvironmentVariable

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

#include <winrt/Windows.Security.Credentials.h>
#include <winrt/Windows.Security.Cryptography.h>

#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>

#include <winrt/Windows.UI.Popups.h>
#include <winrt/Windows.UI.Xaml.Interop.h>

#include <winrt/Windows.System.h>

#include <winrt/Microsoft.UI.h>
#include <winrt/Microsoft.UI.Composition.h>
#include <winrt/Microsoft.UI.Composition.Effects.h>
#include <winrt/Microsoft.UI.Dispatching.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Input.h>
#include <winrt/Microsoft.UI.Input.Interop.h>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#include <winrt/Microsoft.UI.Xaml.Controls.Primitives.h>
#include <winrt/Microsoft.UI.Xaml.Data.h>
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <winrt/Microsoft.UI.Xaml.Interop.h>
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Navigation.h>
#include <winrt/Microsoft.UI.Xaml.Shapes.h>
#include <winrt/Microsoft.UI.Xaml.Input.h>

#include <winrt/Microsoft.Windows.AppLifecycle.h>
#include <winrt/Microsoft.Windows.AppNotifications.h>
#include <winrt/Microsoft.Windows.PushNotifications.h>
#include <winrt/Microsoft.Windows.System.h>

#include <Microsoft.UI.Xaml.Window.h>

#include <wil/winrt.h>
#include <wil/cppwinrt_wrl.h>
#include <wil/cppwinrt_helpers.h>

#include <algorithm>
#include <concepts>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <functional>
#include <format>
#include <ranges>
#include <optional>

namespace winrt
{
    using namespace Microsoft::UI;
    using namespace Microsoft::UI::Xaml;
    using namespace Microsoft::UI::Xaml::Controls;
    using namespace Microsoft::UI::Xaml::Navigation;
    using namespace Microsoft::UI::Windowing;
    using namespace Windows::Graphics;
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
} // namespace winrt

namespace MU   = winrt::Microsoft::UI;
namespace MUX  = winrt::Microsoft::UI::Xaml;
namespace MUXC = winrt::Microsoft::UI::Xaml::Controls;
namespace MUXN = winrt::Microsoft::UI::Xaml::Navigation;
namespace MUXI = winrt::Microsoft::UI::Xaml::Input;
namespace MUXM = winrt::Microsoft::UI::Xaml::Media;
namespace MUW  = winrt::Microsoft::UI::Windowing;
namespace WSC  = winrt::Windows::Security::Credentials;

#ifdef PUSH_MACRO_GetCurrentTime
# pragma pop_macro("GetCurrentTime")
# pragma pop_macro("GetEnvironmentVariable")
# pragma pop_macro("SetEnvironmentVariable")
#endif
