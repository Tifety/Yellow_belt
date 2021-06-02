cmake_minimum_required(VERSION 3.17)
project(final_task)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(final_task
       condition_parser.cpp
      condition_parser.h
    condition_parser_test.cpp
        test_runner.cpp
        main.cpp
       token.cpp
       token.h
       database.cpp
     database.h
        date.cpp
        date.h
       node.cpp
        node.h
        date_test.cpp database_test.cpp
        test_db.h
        )
