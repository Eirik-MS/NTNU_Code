project('sdl2_image_windows', 'cpp')

cxx = meson.get_compiler('cpp')
sdl2_image_windows_dep = declare_dependency(
  dependencies : [cxx.find_library('SDL2_image', dirs : join_paths(meson.current_source_dir(), 'lib'))],
  include_directories : include_directories(join_paths('include', 'SDL2')))

copy_prg = find_program(join_paths(meson.current_source_dir(), 'copy.py'))
custom_target('copy SDL_image DLL',
  output: 'copy.log',
  command : [copy_prg, join_paths(meson.current_source_dir(), 'bin', 'SDL2_image.dll'),
                       join_paths(meson.global_build_root(), 'SDL2_image.dll')],
  install : false,
  build_by_default : true)