# Install script for directory: /p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/universal_data_logger_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/universal_data_logger.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recordables_map.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/archiving_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/clopath_archiving_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/urbanczik_archiving_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/urbanczik_archiving_node_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/common_synapse_properties.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_label.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/common_properties_hom_w.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/syn_id_delay.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connector_base.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connector_base_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connector_model.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connector_model_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_id.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/deprecation_warning.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/device.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/device_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/dynamicloader.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/event.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/exceptions.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/genericmodel.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/genericmodel_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/node_collection.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/generic_factory.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/histentry.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/model.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/model_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/model_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_types.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_datums.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_names.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nestmodule.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_time.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_timeconverter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/modelrange.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/modelrange_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/parameter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/per_thread_bool_indicator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/proxynode.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/random_generators.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recording_device.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/pseudo_recording_device.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/ring_buffer.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/ring_buffer_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/secondary_event.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/secondary_event_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/slice_ring_buffer.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/spikecounter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/stimulation_device.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target_identifier.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/sparse_node_array.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/conn_parameter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/conn_builder.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/conn_builder_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/conn_builder_factory.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/conn_builder_conngen.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/sonata_connector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/music_event_handler.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/music_rate_in_handler.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/music_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/nest_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/synaptic_element.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/growth_curve.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/growth_curve_factory.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/kernel_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/vp_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/vp_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/io_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/io_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/mpi_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/mpi_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/simulation_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/sp_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/sp_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/delay_checker.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/random_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/event_delivery_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/event_delivery_manager_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/node_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/logging_manager.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recording_backend.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recording_backend_ascii.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recording_backend_memory.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/recording_backend_screen.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/manager_interface.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target_table.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target_table_devices.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target_table_devices_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/target_data.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/static_assert.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/send_buffer_position.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/source.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/source_table.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/source_table_position.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/spike_data.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/structural_plasticity_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_creator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/connection_creator_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/free_layer.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/grid_layer.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/grid_mask.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/layer.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/layer_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/mask.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/mask_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/ntree.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/ntree_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/position.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/spatial.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/stimulation_backend.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/nestkernel/buffer_resize_log.h"
    )
endif()

