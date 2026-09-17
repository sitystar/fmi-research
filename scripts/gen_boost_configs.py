#!/usr/bin/env python3
# Автор: Evgenii I, 2026
"""Генерация per-component CMake-конфигов для Boost, распакованного из deb-пакетов.

Ubuntu не кладёт конфиги отдельных компонентов в -dev-пакеты, а BoostConfig из
метапакета ищет boost_<comp>-config.cmake. Скрипт создаёт их по факту наличия
библиотек. Используется scripts/fetch_boost.sh.

Запуск: gen_boost_configs.py <версия, напр. 1.90.0> <префикс распаковки>
"""
import os
import sys

ver = sys.argv[1]
prefix = os.path.abspath(sys.argv[2])
LIB = os.path.join(prefix, "usr/lib/x86_64-linux-gnu")
INC = os.path.join(prefix, "usr/include")
CM = os.path.join(LIB, "cmake")

comps = {
    "thread": (f"libboost_thread.so.{ver}", []),
    "system": (None, []),          # header-only в новых Boost
    "filesystem": (f"libboost_filesystem.so.{ver}", []),
    "date_time": (f"libboost_date_time.so.{ver}", []),
    "regex": (f"libboost_regex.so.{ver}", []),
    "log": (f"libboost_log.so.{ver}", ["Boost::thread", "Boost::filesystem"]),
    "log_setup": (f"libboost_log_setup.so.{ver}", ["Boost::log"]),
}

cfg = """# Generated locally (Evgenii I 2026) for extracted Ubuntu boost {ver}
if(NOT TARGET Boost::{comp})
  add_library(Boost::{comp} {kind} IMPORTED)
{body}
  set_property(TARGET Boost::{comp} APPEND PROPERTY INTERFACE_LINK_LIBRARIES Boost::headers{deps})
endif()
set(boost_{comp}_FOUND 1)
"""
body_lib = """  set_property(TARGET Boost::{comp} PROPERTY IMPORTED_LOCATION "{libdir}/{lib}")
  set_property(TARGET Boost::{comp} PROPERTY INTERFACE_INCLUDE_DIRECTORIES "{inc}")"""
body_hdr = """  set_property(TARGET Boost::{comp} PROPERTY INTERFACE_INCLUDE_DIRECTORIES "{inc}")"""
ver_file = f'set(PACKAGE_VERSION "{ver}")\nset(PACKAGE_VERSION_COMPATIBLE TRUE)\nset(PACKAGE_VERSION_EXACT TRUE)\n'

for comp, (lib, deps) in comps.items():
    d = os.path.join(CM, f"boost_{comp}-{ver}")
    os.makedirs(d, exist_ok=True)
    if lib:
        kind, body = "UNKNOWN", body_lib.format(comp=comp, libdir=LIB, lib=lib, inc=INC)
    else:
        kind, body = "INTERFACE", body_hdr.format(comp=comp, inc=INC)
    deps_s = "".join(" " + x for x in deps)
    with open(os.path.join(d, f"boost_{comp}-config.cmake"), "w") as f:
        f.write(cfg.format(comp=comp, kind=kind, body=body, deps=deps_s, ver=ver))
    with open(os.path.join(d, f"boost_{comp}-config-version.cmake"), "w") as f:
        f.write(ver_file)
print(f"configs written: {len(comps)} (boost {ver})")
