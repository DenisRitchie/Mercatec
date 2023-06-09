// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once
#include <Windows.h>
#include <Unknwn.h>
#include <RestrictedErrorInfo.h>
#include <hstring.h>
#include <strsafe.h>
#include <objidl.h>

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
#include <winrt/Windows.Globalization.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.Security.Credentials.h>
#include <winrt/Windows.Security.Cryptography.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.UI.Popups.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Interop.h>

#include <winrt/Microsoft.Graphics.Canvas.h>
#include <winrt/Microsoft.Graphics.Canvas.Effects.h>
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>

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

#include <winrt/Mercatec.Application.h>
#include <winrt/Mercatec.Helpers.h>
#include <winrt/Mercatec.Helpers.Converters.h>
#include <winrt/Mercatec.Helpers.Services.h>
#include <winrt/Mercatec.Helpers.ViewModels.h>
#include <winrt/Mercatec.ViewModels.h>

#include <Mercatec.WinUIEx.HwndExtensions.hpp>
#include <Mercatec.WinUIEx.WindowExtensions.hpp>

#include <Microsoft.UI.Xaml.Window.h>

#include <wil/winrt.h>
#include <wil/resource.h>
#include <wil/cppwinrt_helpers.h>

#include <Mercatec.Services.hpp>
#include <Mercatec.Helpers.Types.hpp>
#include <Mercatec.Helpers.Strings.hpp>
#include <Mercatec.Helpers.FunctionTraits.hpp>
#include <Mercatec.Helpers.ServiceLocator.hpp>
#include <Mercatec.Helpers.AnimationExtensions.hpp>

#include <ppl.h>
#include <ppltasks.h>
#include <concurrent_vector.h>
#include <concurrent_unordered_map.h>
#include <concurrent_unordered_set.h>
#include <agents.h>

#include <algorithm>
#include <format>
#include <chrono>
#include <functional>
#include <ranges>

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

using ::Mercatec::WinUIEx::HwndExtensions;
using ::Mercatec::WinUIEx::WindowExtensions;

using namespace std::string_literals;
using namespace std::string_view_literals;
using namespace std::chrono_literals;

#ifdef PUSH_MACRO_GetCurrentTime
# pragma pop_macro("GetCurrentTime")
# pragma pop_macro("GetEnvironmentVariable")
# pragma pop_macro("SetEnvironmentVariable")
#endif
