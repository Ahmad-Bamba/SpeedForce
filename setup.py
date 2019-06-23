from distutils.core import setup, Extension
from os import environ

# compiler options
environ['CC']='g++'
environ['CXX']='g++'
environ['CPPFLAGS']='-I/usr/include -I/usr/local/include -Iinclude'

module = Extension('SpeedForce', sources = ['src/speedforce.cpp'])
setup(name = 'SpeedForce', version = '0.0.1a', 
      description = 'A C++ vector library for Python 3.x',
      ext_modules = [module])
