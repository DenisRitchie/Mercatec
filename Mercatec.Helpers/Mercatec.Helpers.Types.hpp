#pragma once

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

#include <set>
#include <map>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <unordered_map>
#include <unordered_set>

namespace Mercatec::inline Types
{
    using Guid = winrt::guid;

    using Boolean = bool;

    using Byte = uint8_t;

    using Int8  = int_fast8_t;
    using UInt8 = uint_fast8_t;

    using Int16  = int_fast16_t;
    using UInt16 = uint_fast16_t;

    using Int32  = int_fast32_t;
    using UInt32 = uint_fast32_t;

    using Int64  = int_fast64_t;
    using UInt64 = uint_fast64_t;

    using Single = float_t;
    using Double = double_t;

    using Char   = wchar_t;
    using String = winrt::hstring;

    using Object   = winrt::Windows::Foundation::IInspectable;
    using DateTime = winrt::Windows::Foundation::DateTime;
    using TimeSpan = winrt::Windows::Foundation::TimeSpan;

    template <typename T>
    using Nullable = std::optional<T>;

    template <typename T>
    using IReference = winrt::Windows::Foundation::IReference<T>;

    template <typename T>
    using Vector = winrt::Windows::Foundation::Collections::IVector<T>;

    template <typename T>
    using ObservableVector = winrt::Windows::Foundation::Collections::IObservableVector<T>;

    template <typename Key, typename Value>
    using Map = winrt::Windows::Foundation::Collections::IMap<Key, Value>;

    template <typename Key, typename Value>
    using ObservableMap = winrt::Windows::Foundation::Collections::IObservableMap<Key, Value>;

    using winrt::Windows::Foundation::GuidHelper;

    using winrt::multi_threaded_map;
    using winrt::multi_threaded_observable_map;
    using winrt::multi_threaded_observable_vector;
    using winrt::multi_threaded_vector;
    using winrt::single_threaded_map;
    using winrt::single_threaded_observable_map;
    using winrt::single_threaded_observable_vector;
    using winrt::single_threaded_vector;
} // namespace Mercatec::inline Types
