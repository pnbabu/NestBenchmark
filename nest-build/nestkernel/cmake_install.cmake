# Install script for directory: /home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lukkyguy/code/NestBenchmark/nest-simulator-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/universal_data_logger_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/universal_data_logger.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recordables_map.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/archiving_node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/clopath_archiving_node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/urbanczik_archiving_node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/urbanczik_archiving_node_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/common_synapse_properties.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_label.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/common_properties_hom_w.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/syn_id_delay.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connector_base.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connector_base_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connector_model.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connector_model_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_id.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/deprecation_warning.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/device.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/device_node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/dynamicloader.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/event.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/exceptions.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/genericmodel.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/genericmodel_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/node_collection.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/generic_factory.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/histentry.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/model.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/model_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/model_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_types.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_datums.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_names.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nestmodule.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_time.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_timeconverter.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/modelrange.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/modelrange_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/parameter.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/per_thread_bool_indicator.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/proxynode.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/random_generators.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recording_device.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/pseudo_recording_device.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/ring_buffer.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/ring_buffer_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/secondary_event.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/slice_ring_buffer.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/spikecounter.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/stimulation_device.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target_identifier.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/sparse_node_array.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/conn_parameter.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/conn_builder.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/conn_builder_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/conn_builder_factory.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/conn_builder_conngen.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/sonata_connector.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/music_event_handler.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/music_rate_in_handler.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/music_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/nest_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/synaptic_element.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/growth_curve.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/growth_curve_factory.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/kernel_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/vp_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/vp_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/io_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/io_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/mpi_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/mpi_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/simulation_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/sp_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/sp_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/delay_checker.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/random_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/event_delivery_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/event_delivery_manager_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/node_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/logging_manager.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recording_backend.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recording_backend_ascii.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recording_backend_memory.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/recording_backend_screen.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/manager_interface.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target_table.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target_table_devices.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target_table_devices_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/target_data.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/static_assert.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/send_buffer_position.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/source.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/source_table.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/source_table_position.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/spike_data.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/structural_plasticity_node.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_creator.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/connection_creator_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/free_layer.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/grid_layer.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/grid_mask.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/layer.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/layer_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/mask.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/mask_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/ntree.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/ntree_impl.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/position.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/spatial.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/stimulation_backend.h"
    "/home/lukkyguy/code/NestBenchmark/nest-simulator/nestkernel/buffer_resize_log.h"
    )
endif()

