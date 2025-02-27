import ctypes
import os

if os.name == "nt":
    lib = ctypes.CDLL("build/myLib.dll")
else:
    lib = ctypes.CDLL("build/libmyLib.so")


lib.process_csv.argtypes = [ctypes.c_char_p]

filename = input("Enter CSV file name: ").strip()

lib.process_csv(filename.encode('utf-8'))
