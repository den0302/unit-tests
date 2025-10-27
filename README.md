# Система Управління Зоопарком

Це консольний додаток на C++, який реалізує систему керування зоопарком із підтримкою авторизації користувачів, бази даних SQLite, системи логування та ролей доступу (RBAC).

## Основні Можливості

* **Авторизація Користувачів:**
  * Вхід у систему за логіном і паролем.
  * Паролі зберігаються у вигляді хеш-сум (`std::hash`).
  * Ролі користувачів:
    * `ADMIN` — повний доступ (управління акаунтами та системними налаштуваннями).
    * `MANAGER` — управління зоопарком (тварини, працівники, вольєри).
    * `EMPLOYEE` — базовий доступ (виконання завдань, годування тварин).

* **Керування Тваринами:**
  * Додавання, видалення, редагування інформації про тварин.
  * Підтримка типів: `Mammal`, `Bird`, `Reptile`, `Fish`, `Amphibian`, `Insect`, `Arachnid`.
  * Перевірка сумісності тварин у межах одного вольєру.
  * Призначення тварин до вольєрів і годування.

* **Керування Працівниками:**
  * Додавання, видалення працівників.
  * Призначення працівників до вольєрів.
  * Перепризначення або видалення з поточних вольєрів.
  * Вивід інформації про всіх працівників.

* **Керування Вольєрами та Графом Зоопарку:**
  * Модель зоопарку реалізована як граф (`ZooGraph`), де вершини — це вольєри, а ребра — шляхи між ними.
  * Можливість знаходження найкоротших маршрутів.
  * Перевірка зв’язності зоопарку.

* **Підтримка SQLite:**
  * Усі дані зберігаються в базі `zoo.db`.
  * Використовуються таблиці:
    * `accounts`
    * `animals`
    * `employees`
    * `aviaries`
    * `paths`
  * Таблиці створюються автоматично при першому запуску.

* **Система Логування:**
  * Власна реалізація логера (`Logger`).
  * Підтримувані рівні: `DEBUG`, `INFO`, `WARN`, `ERROR`.
  * Вивід логів у консоль і файл (`log.txt`).
  * Кольорове форматування виводу.

## Структура Проєкту

Оригінальний проєкт має модульну структуру:

* `/Accounts` — управління користувачами:
  * `Account`, `AuthManager`
* `/Creatures` — тварини та працівники:
  * `Animal`, `AnimalManager`, `Employee`, `EmployeeManager`
* `/DatabaseManager` — робота з SQLite:
  * `DatabaseManager`, `AviaryRepository`, `PathRepository` тощо
* `/Graphs` — структура зоопарку як графа:
  * `ZooGraph`, `Graph`, `Aviary`, `Path`
* `/Logger` — система логування
* `/Menus` — консольні меню для різних ролей

## Залежності

* **C++17** (або вище)
* **SQLite3** — база даних
* **Rpcrt4** — бібліотека Windows для генерації UUID
* **CMake / Ninja** — система збірки

## Збірка та Запуск

### Варіант 1. Через CMake і CLion

1. Створити файл `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

set(SQLITE_PATH "C:/libs/sqlite")

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()
include(GoogleTest)

add_library(Lab1Lib
        Creatures/Employee.h
        Creatures/Animals.h
        Creatures/Animals.cpp
        Creatures/Employee.cpp
        Graphs/Graph.h
        Graphs/Graph.cpp
        Graphs/ZooGraph.h
        Graphs/ZooGraph.cpp
        Accounts/Account.h
        Accounts/Account.cpp
        Accounts/AuthManager.h
        Accounts/AuthManager.cpp
        Menus/AdminMenu.h
        Menus/AdminMenu.cpp
        Menus/ManagerMenu.h
        Menus/ManagerMenu.cpp
        Menus/Menu.h
        Menus/Menu.cpp
        Creatures/AnimalManager.h
        Creatures/AnimalManager.cpp
        Creatures/EmployeeManager.h
        Creatures/EmployeeManager.cpp
        Logger/Logger.h
        Logger/Logger.cpp
        Logger/LoggerGlobal.h
        Logger/LoggerGlobal.cpp
        DatabaseManager/DatabaseManager.h
        DatabaseManager/DatabaseManager.cpp
        DatabaseManager/AccountRepository.h
        DatabaseManager/AccountRepository.cpp
        DatabaseManager/AnimalRepository.h
        DatabaseManager/AnimalRepository.cpp
        DatabaseManager/AviaryRepository.h
        DatabaseManager/AviaryRepository.cpp
        DatabaseManager/EmployeeRepository.h
        DatabaseManager/EmployeeRepository.cpp
        DatabaseManager/PathRepository.h
        DatabaseManager/PathRepository.cpp
        DatabaseManager/SQLUtilities/SQLUtils.h
        DatabaseManager/SQLUtilities/SQLUtils.cpp
)

target_include_directories(Lab1Lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SQLITE_PATH}
)

target_link_libraries(Lab1Lib PUBLIC
        "${SQLITE_PATH}/sqlite3.dll"
        Rpcrt4
)

add_executable(Lab1 Lab1.cpp)

target_link_libraries(Lab1 PRIVATE Lab1Lib)

add_executable(my_tests
        tests/main_test.cpp
)

target_link_libraries(my_tests PRIVATE
        gtest_main
        Lab1Lib
)

gtest_discover_tests(my_tests)
add_test(NAME my_tests COMMAND my_tests)

add_custom_command(TARGET Lab1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SQLITE_PATH}/sqlite3.dll"
        $<TARGET_FILE_DIR:Lab1>
)

add_custom_command(TARGET my_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SQLITE_PATH}/sqlite3.dll"
        $<TARGET_FILE_DIR:my_tests>
)
```

2. Зібрати проєкт у CLion або вручну:

```bash
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release .
ninja
```

3. Запустити виконуваний файл:

```bash
./ZooManagementSystem
```

## Приклад Використання

1. При першому запуску система створює стандартні акаунти:
   ```
   admin / admin
   manager / manager
   employee / employee
   ```
2. Авторизуйтеся під потрібним користувачем.
3. Для адміністратора доступне керування обліковими записами.
4. Менеджер може керувати працівниками, тваринами, вольєрами.
5. Працівник може переглядати та годувати тварин.

## Файли

* `Lab1.cpp` — основний вихідний код.
* `zoo.db` — база даних SQLite.
* `log.txt` — файл логів.

## 📘 Documentation
The project documentation is automatically generated with **Doxygen**  
and published via **GitHub Pages** after every commit to the `main` branch.  
[View the documentation here](https://denysfreiuk.github.io/unit-tests/)
