import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/merlin/venom_cpp_basics/training/02-ros2-wheelleg/Tutorial/install/my_first_pkg'
