project('pendulum', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

exe = executable('pendulum', 'pendulum.c',
  dependencies : [ m_dep, dependency('raylib') ],
  install : true)
