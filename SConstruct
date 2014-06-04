
env = Environment()

import os
env['ENV']['TERM'] = os.environ['TERM']

if env["CXX"] == "g++":
    env["CXX"] = "clang++"

env.Append(
    CPPPATH=[
        "./include",
    ],
    CPPDEFINES=[
        'GTEST_LANG_CXX11',
    ],
    CCFLAGS=[
        '-O3',
        '-std=c++11',
        # '-std=c++1y',
        '-Wall',
        '-Wextra',
        '-Werror',
    ],
    LIBS=[
        'gtest',
        'pthread',
    ],
)

env.Program("runtests",source='tests/test.cpp')
env.Command("test_results","runtests","./runtests")
