#代码路径
aux_source_directory(. DIR_ROOT_SRCS)

file(GLOB_RECURSE CURR_SRC ${CMAKE_CURRENT_SOURCE_DIR}/longan_proto/*.cc)

#设置include路径
include_directories(/usr/local/include/)

include_directories(${PROJECT_SOURCE_DIR}/src/longan_proto/)

#设置lib目录
link_directories(/usr/local/lib/)


#设置变量
set(exec_name client)

set(ALL_SRCS ${DIR_ROOT_SRCS} ${CURR_SRC})

#生成可执行文件
add_executable(${exec_name} ${ALL_SRCS})

#连接库
target_link_libraries(${exec_name} 
   -lgrpc++ -lgrpc -lgrpc++_reflection -lprotobuf
   -lpthread
   )