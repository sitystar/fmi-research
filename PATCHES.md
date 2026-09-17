# PATCHES.md — все правки стороннего кода

**Правки и дописанние файлов: Evgenii I, 2026.**
Upstream-проекты (AIT-IES/FMITerminalBlock, fmipp) не форкались отдельно — их
исходники вложены в этот репозиторий уже с правками.

## fmipp (FMI++, sourcesourceforge, vendored в `fmipp/`)

| Файл | Правка | Причина |
|---|---|---|
| `CMakeLists.txt` | `-std=c++11` → `-std=c++17` | Boost.Math 1.90 требует ≥ C++14 |
| `export/src/HelperFunctions.cpp` | `copy_option::overwrite_if_exists` → `copy_options::overwrite_existing` | новый API Boost.Filesystem |
| `export/src/SHMManager.cpp` | `ipcdetail::thread_sleep` → `thread_sleep_ms` | убран старый внутренний API Boost.Interprocess |

## FMITerminalBlock (AIT-IES, vendored в `FMITerminalBlock/`)

Сборочные правки (Boost.Asio/Boost 1.90 против кода 2017 г.):

| Файл | Правка |
|---|---|
| `include/network/CompactASN1Subscriber.h` | `io_service` → `io_context`; `io_service::work` → `executor_work_guard` |
| `src/network/CompactASN1Subscriber.cpp` | то же + `service_.post()` → `boost::asio::post()`; `buffer_cast<T>(b.data())` → `static_cast<T>(b.data().data())` |
| `include/network/CompactASN1TCPClientPublisher.h` | `io_service` → `io_context` |
| `src/network/CompactASN1TCPClientPublisher.cpp` | `resolver::query`/`iterator` → `results_type` + `resolve(host, port)` |
| `include/network/CompactASN1UDPPublisher.h` | `io_service` → `io_context` |
| `src/network/CompactASN1UDPPublisher.cpp` | то же, что у TCP-паблишера |
| `src/network/CompactASN1TCPClientSubscriber.cpp` | то же + range-форма `connect()` |
| `include/base/PortID.h` | + `#include <string>` (неявная зависимость больше не проходит) |

Функциональная правка (стоит предложить upstream):

| Файл | Правка |
|---|---|
| `include/network/ASN1Commons.h` | + константы тегов SINT/INT/USINT/UINT/UDINT/ULINT (нумерация по IEC 61499 / fbdkasn1) |
| `src/network/CompactASN1Subscriber.cpp` | + декодирование целочисленных ASN.1-тегов (раньше поддерживался только DINT): без этого FORTE-типы UINT/INT и т.п. терялись с «Unsupported ASN.1 type with tag NN» |

Сборка также требует: `-DCMAKE_POLICY_VERSION_MINIMUM=3.5` (CMake ≥ 4 против
`cmake_minimum_required(3.1)` upstream), `-DBUILD_SWIG=OFF -DBUILD_TESTS=OFF
-DFMITerminalBlock_BUILD_TESTS=OFF`. Всё это зашито в `scripts/setup.sh`.

## Новые файлы 

`scripts/*`, `app/*`, `models/Tank.fmu.dir` (готовый FMU), `ИНСТРУКЦИЯ.md`, `README.md`, `PATCHES.md`.

