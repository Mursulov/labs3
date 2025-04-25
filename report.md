## 1 Клонируем из репозитория файлы для сборки 
git clone  https://github.com/tp-labs/lab03.git

## 2 Создаем папку source и добавляем файлы print
![ ](https://github.com/Mursulov/labs3/blob/main/image/%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5%20%D0%B8%D0%B7%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5.png?raw=true)


## 3 Создаем CMakeLists.txt 
<details><summary>Файл </summary>

    cmake_minimum_required(VERSION 3.14)
    
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    
    option(BUILD_EXAMPLES "Build examples" OFF)
    
    project(print)
    
    add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
    
    target_include_directories(print PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
    )
    
    if(BUILD_EXAMPLES)
      file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
      foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_NAME} print)
        install(TARGETS ${EXAMPLE_NAME}
          RUNTIME DESTINATION bin
        )
      endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    endif()
    
    install(TARGETS print
        EXPORT print-config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
    )
    
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
    install(EXPORT print-config DESTINATION cmake)

</details>

## Собираем сборку 

    git branch -M main
    git push -u origin main
    
![ ](https://github.com/Mursulov/labs3/blob/main/image/%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5%20%D0%B8%D0%B7%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5%20%282%29.png?raw=true)

![ ](https://github.com/Mursulov/labs3/blob/main/image/%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5%20%D0%B8%D0%B7%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5%20%283%29.png?raw=true)

![содержимое bild](https://github.com/Mursulov/labs3/blob/main/image/%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5%20%D0%B8%D0%B7%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5%20%284%29.png?raw=true)
