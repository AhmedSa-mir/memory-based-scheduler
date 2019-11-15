add_executable(process process.cpp)

add_executable(sched_process sched_process.cpp)
target_link_libraries(sched_process sched_lib)

add_library(sched_lib scheduler.cpp)