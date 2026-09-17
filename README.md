# fmi-research — связка «flogic/FORTE ↔ FMU-модель» для проверки логики управления

*Автор доработок, скриптов и документации: Evgenii I, 2026.*

Проверка логики 61499-приложений на математической модели: ядро общается с приложением через штатные `SERVER_`-блоки,
а на другом конце TCP сидит FMITerminalBlock, который "имитирует" объект управления,
прокручивая FMU-модель (экспорт из OpenModelica(с Engee пока не пробовал), FMI Model Exchange).

```
[ приложение 61499] → SERVER_ по TCP (ASN.1 IEC 61499) —→ [ FMITerminalBlock ] —FMI→ [ model.fmu ]
   (fl-orchestrator)                                                  (виртуальный объект)     (из OM/Engee)
```

## Состав репозитория

| Путь | Что |
|---|---|
| `ИНСТРУКЦИЯ.md` | как проверить связку на «баке» (пошагово) |
| `FMITerminalBlock/`, `fmipp/` | сторонние исходники с патчами |
| `scripts/run_fmu.sh` | запуск связки из консоли (модель — аргументами; входы/выходы — автоматически) |
| `scripts/fmi_gui.py` | **графический интерфейс**: импорт FMU, список моделей, параметры запуска, живой лог (`/usr/bin/python3`, нужен пакет python3-tk) |
| `scripts/setup.sh` | развёртывание на новой машине (зависимости → Boost → сборка) |
| `scripts/fetch_boost.sh` | Boost без root (deb-пакеты локально) — только если нет системного |
| `models/` | готовые FMU (распакованные каталоги; подготовка FMU — вне этого проекта) |
| `app/toy/fmi_tank.fboot` | проверочное приложение «бак с гистерезисом» (генерация из проекта `fmi_tank` в IDE) |
| `app/ide/fmi_tank/` |проекта flogic IDE |


## Десктопное приложение GUI (.deb, с инсталлятором)

`scripts/fmi_gui.py` упаковывается в самодостаточное приложение (python/tkinter
— внутри бинарника, на целевой машине ставить ничего не нужно):

```bash
# машина сборки (однократно): sudo apt install -y python3-tk python3-pip binutils
packaging/build_deb.sh                          # → dist/fmi-coupling-gui_1.х.х_amd64.deb
sudo apt install ./dist/fmi-coupling-gui_*_amd64.deb   # на любой машине
```

Пакет самодостаточен: связыватель FMITerminalBlock со всеми библиотеками
устанавливается в `/opt/fmi-coupling/fmitb`. Модели и trace живут в рабочем
каталоге пользователя `~/fmi-coupling` (создаётся при первом запуске; путь и
`FMI_RESEARCH_HOME` для разработки — кнопка «Сменить каталог»). Правило то же:
Flogic (IEC 61499, forte) запускает пользователь самостоятельнл, приложение управляет лишь FMITerminalBlock.

## CI/CD (GitHub Actions)

`.github/workflows/build.yml` собирает всё при каждом push в main (и по кнопке
Run workflow); артефакты скачиваются на странице запуска → Artifacts:

| Джоба | Что собирает | Артефакт |
|---|---|---|
| `fmitb` | FMITerminalBlock + fmipp (с патчами) + бандл libboost | `dist/fmitb/` |
| `gui-deb` | десктопное приложение `.deb` (python внутри) | `dist/*.deb` |
| `smoke` | проверка: бинарник грузится, FMU (из репозитория) читается, каналы доходят до FORTE | — |

## Перенос на другую машину (Linux x86_64)

```bash
git clone <этот-репозиторий> && cd fmi-research
scripts/setup.sh          # зависимости, Boost, сборка FMITerminalBlock (~5–10 минут)
```
`setup.sh` сам выберет Boost: системный (`sudo apt install libboost-log-dev
libboost-thread-dev libboost-filesystem-dev libboost-date-time-dev
libboost-regex-dev`) или локальный без root (`scripts/fetch_boost.sh <версия>`).
FMU — готовые артефакты: приходят из средств моделирования (Engee/OpenModelica),
в репозитории лежат распакованными (`models/*.fmu.dir`, linux64). Новая модель =
получить `.fmu`, распаковать (или импортировать кнопкой в GUI) и запустить.

