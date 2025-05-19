## Домашнее задание 3

*

Представьте, что вы стажер в компании "Formatter Inc.".
### Задание 1
Вам поручили перейти на систему автоматизированной сборки **CMake**.
Исходные файлы находятся в директории [formatter_lib](formatter_lib).
В этой директории находятся файлы для статической библиотеки *formatter*.
Создайте `CMakeList.txt` в директории [formatter_lib](formatter_lib),
с помощью которого можно будет собирать статическую библиотеку *formatter*.

```sh
$ mkdir HW03 
$ git clone https://github.com/tp-labs/lab03.git HW03 
Cloning into 'HW03'...
remote: Enumerating objects: 91, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 91 (delta 23), reused 21 (delta 21), pack-reused 61 (from 1)
Receiving objects: 100% (91/91), 1.02 MiB | 310.00 KiB/s, done.
Resolving deltas: 100% (41/41), done.
$ cd formatter_lib
$ cat > CMakeLists.txt <<EOF               
heredoc> cmake_minimum_required(VERSION 3.4)
heredoc> 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
heredoc> project(formatter_lib)
heredoc> add_library(formatter STATIC formatter.cpp)
heredoc> target_include_directories(formatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
heredoc> EOF
```

### Задание 2
У компании "Formatter Inc." есть перспективная библиотека,
которая является расширением предыдущей библиотеки. Т.к. вы уже овладели
навыком созданием `CMakeList.txt` для статической библиотеки *formatter*, ваш 
руководитель поручает заняться созданием `CMakeList.txt` для библиотеки 
*formatter_ex*, которая в свою очередь использует библиотеку *formatter*.
```sh
$ cd formatter_ex_lib
$ cat > CMakeLists.txt <<EOF
heredoc> cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(formatter_ex_lib)

add_library(formatter_ex STATIC formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(formatter_ex PUBLIC formatter)
heredoc> EOF

```
### Задание 3
Конечно же ваша компания предоставляет примеры использования своих библиотек.
Чтобы продемонстрировать как работать с библиотекой *formatter_ex*,
вам необходимо создать два `CMakeList.txt` для двух простых приложений:
* *hello_world*, которое использует библиотеку *formatter_ex*;
* *solver*, приложение которое испольует статические библиотеки *formatter_ex* и *solver_lib*.
```sh
$ cd hello_world_application 
$ cat > CMakeLists.txt <<EOF 
heredoc>cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello_world)

add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world PRIVATE formatter_ex)
heredoc>EOF
$ cd ..
$ cd solver_application 
$ cat > CMakeLists.txt <<EOF
heredoc> cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(solver_application)

add_executable(solver equation.cpp)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)
heredoc>EOF
$ cd ..
$ cd solver_lib
cat > CMakeLists.txt <<EOF
heredoc> cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

heredoc> project(solver_lib)
heredoc> 
heredoc> add_library(solver_lib STATIC solver.cpp)
heredoc> target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
heredoc> EOF
$ cd ..
$ cat > CMakeLists.txt <<EOF
heredoc> cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

heredoc> project(formatter_project)
heredoc> 
heredoc> add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_lib)
heredoc> add_subdirectory(hello_world_application)
add_subdirectory(solver_application)
heredoc> EOF
```
### Проверка
```sh
$ mkdir build
$ cd build
$ cmake ..                                                   
CMake Deprecation Warning at CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Deprecation Warning at formatter_lib/CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at formatter_ex_lib/CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at solver_lib/CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at hello_world_application/CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


CMake Deprecation Warning at solver_application/CMakeLists.txt:1 (cmake_minimum_required):
  Compatibility with CMake < 3.10 will be removed from a future version of
  CMake.

  Update the VERSION argument <min> value.  Or, use the <min>...<max> syntax
  to tell CMake that the project requires at least <min> but has been updated
  to work with policies introduced by <max> or earlier.


-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /home/wfs/mursulov/workspace/projects/HW03/build
$ ls -la                  
total 60
drwxrwxr-x 8 wfs wfs  4096 Apr 13 22:49 .
drwxrwxr-x 9 wfs wfs  4096 Apr 13 22:45 ..
-rw-rw-r-- 1 wfs wfs 16145 Apr 13 22:47 CMakeCache.txt
drwxrwxr-x 5 wfs wfs  4096 Apr 13 22:47 CMakeFiles
-rw-rw-r-- 1 wfs wfs  2772 Apr 13 22:47 cmake_install.cmake
drwxrwxr-x 3 wfs wfs  4096 Apr 13 22:47 formatter_ex_lib
drwxrwxr-x 3 wfs wfs  4096 Apr 13 22:47 formatter_lib
drwxrwxr-x 3 wfs wfs  4096 Apr 13 22:47 hello_world_application
-rw-rw-r-- 1 wfs wfs  6584 Apr 13 22:47 Makefile
drwxrwxr-x 3 wfs wfs  4096 Apr 13 22:47 solver_application
drwxrwxr-x 3 wfs wfs  4096 Apr 13 22:47 solver_lib
```