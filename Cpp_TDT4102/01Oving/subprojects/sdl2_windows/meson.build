project('sdl2_windows', 'cpp')

cxx = meson.get_compiler('cpp')
sdl2_windows_dep = declare_dependency(
  dependencies : [cxx.find_library('SDL2main', dirs : join_paths(meson.current_source_dir(), 'lib')), 
                  cxx.find_library('SDL2', dirs : join_paths(meson.current_source_dir(), 'lib'))],
  link_args: ['-lmingw32'],
  include_directories : include_directories(join_paths('include', 'SDL2')))

copy_prg = find_program(join_paths(meson.current_source_dir(), 'copy.py'))
custom_target('copy SDL DLL',
  output: 'copy.log',
  command : [copy_prg, join_paths(meson.current_source_dir(), 'bin', 'SDL2.dll'),
                       join_paths(meson.global_build_root(), 'SDL2.dll')],
  install : false,
  build_by_default : true)
